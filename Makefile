# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 18:22:15 by vmoreau           #+#    #+#              #
#    Updated: 2019/12/06 14:24:25 by vmoreau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#PRINTF
NAME = libftprintf.a

SRCS = src/test.c

OBJS = $(SRCS:.c=.o)

INCL = header/

HEADER = $(INCL)ft_printf.h

CC = clang

CFLAGS = -Werror -Wall -Wextra

LIBLINK = -L./ -lftprintf

#LIBFT
LIB = libft/

OBJLIB = $(LIB)src/*.o

#RULE
all : target $(NAME)

target :
	@$(MAKE) -C libft re

$(OBJS) : %.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -I$(INCL) -c $< -o $@

$(NAME) : echoCL echoCS $(OBJS) echoAR
	@ar rcs $@ $(OBJS) $(OBJLIB)

exec :
	$(CC) $(CFLAGS) main.c $(LIBLINK)

cleanlib :
	@$(MAKE) -C libft fclean
	
clean : echoCLEAN
	@$(RM) $(OBJS)

fclean : cleanlib clean echoFCLEAN
	@$(RM) $(NAME)

re : fclean all

#ECHO
echoCL:
	@echo "\033[1;33m===> Compiling Libftprintf\033[m"
echoCS :
	@echo "\033[33;32m===> Compilation Success\033[m"
echoCLEAN :
	@echo "\033[1;35m===> Cleanning OBJ Libftprintf\033[m"
echoFCLEAN :
	@echo "\033[1;35m===> Cleanning Libftprintf.a\033[m"
echoAR :
	@echo "\033[33;36m===> Archiving Libftprintf\033[m"
.PHONY : all clean fclean re target exec cleanlib
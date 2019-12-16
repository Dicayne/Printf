# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 18:22:15 by vmoreau           #+#    #+#              #
#    Updated: 2019/12/16 20:42:25 by vmoreau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#PRINTF
NAME = libftprintf.a

SRCS =		src/ft_printf.c		src/check_flags.c	src/find_size.c		\
			src/init_struct.c	src/itoas.c			src/print_s.c		\
			src/print_u.c		src/print_c.c		src/print_x.c		\
			src/print_p.c		src/print_di.c		src/print_0.c		\
			src/check_di.c		src/check_s.c		src/check_cper.c	\
			src/check_uxp.c		src/check_di_d.c	src/set_ret.c		
			
OBJS = $(SRCS:.c=.o)

INCL = header/

HEADER = $(INCL)ft_printf.h

CC = clang

CFLAGS = -Werror -Wall -Wextra

LIBLINK = -L./ -lftprintf

#LIBFT
LIB = Libft/

OBJLIB = $(LIB)src/*.o

LIBFT = $(LIB)libft.a

#RULE
all : complib $(NAME)

$(OBJS) : %.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -I $(INCL) -c $< -o $@ 

$(NAME) : echoCL $(OBJS) echoCS echoAR
	@ar rcs $@ $(OBJS) $(OBJLIB)

complib :
	@$(MAKE) -C libft all

exec :
	@$(CC) $(CFLAGS) main.c $(LIBLINK)
	@./a.out

cleanlibft :
	@$(MAKE) -C libft clean

fcleanlibft :
	@$(MAKE) -C libft fclean
	
clean : echoCLEAN cleanlibft
	@$(RM) $(OBJS)

fclean : clean echoFCLEAN fcleanlibft
	@$(RM) $(NAME)
	@rm -rf a.out a.out.dSYM

re : fclean all

#ECHO
echoCL:
	@echo "\033[33;33m===> Compiling Libftprintf\033[m"
echoCS :
	@echo "\033[1;32m===> Compilation Success\033[m"
echoCLEAN :
	@echo "\033[35m===> Cleanning OBJ Libftprintf\033[m"
echoFCLEAN :
	@echo "\033[35m===> Cleanning Libftprintf.a\033[m"
echoAR :
	@echo "\033[1;36m===> Archiving Libftprintf\033[m"

.PHONY : all clean fclean re complib exec cleanlibft fcleanlibft

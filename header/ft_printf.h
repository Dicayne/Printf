/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:27:27 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/11 18:40:19 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../Libft/header/libft.h"
# define HEXA_LOW "0123456789abcdef"
# define HEXA_UP "0123456789ABCDEF"

typedef struct	s_struct
{
	va_list args;
	int		i;
	int		nb_read;
	int		nb_str;
	int		field;
	int		bool;
	int		prec;
	int		bool_s;
	int		tmp;
	int		tmp2;
	int		dash;
	int		less;
}				t_struct;
int				ft_printf(const char *str, ...);
void			init_struct(t_struct *st);
void			print_s(t_struct *st);
void			print_di(t_struct *st);
void			print_c(t_struct *st);
void			print_p(t_struct *st);
void			print_i(t_struct *st);
void			print_u(t_struct *st);
void			print_x(t_struct *st, char x);
void			print_0(t_struct *st);
void			check_diuxpc(t_struct *st, int size);
#endif

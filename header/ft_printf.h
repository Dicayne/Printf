/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:27:27 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/07 23:13:09 by vmoreau          ###   ########.fr       */
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

int		ft_printf(const char *str, ...);
void	print_s(va_list args, int *ret);
void	print_di(va_list args, int *ret);
void	print_c(va_list args, int *ret);
void	print_p(va_list args, int *ret);
void	print_i(va_list args, int *ret);
void	print_u(va_list args, int *ret);
void	print_xX(va_list args, int *ret, char x);
#endif

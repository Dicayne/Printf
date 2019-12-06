/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:27:27 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/06 20:25:22 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../Libft/header/libft.h"

int		ft_printf(const char *str, ...);
void	print_s(va_list args);
void	print_d(va_list args);
void	print_c(va_list args);
// void	print_p(va_list args);
void	print_i(va_list args);
// void	print_u(va_list args);
// void	print_x(va_list args);
// void	print_X(va_list args);
#endif
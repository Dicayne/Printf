/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 21:25:40 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/15 01:10:38 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void			print_c(t_struct *st, t_flags *flg, const char **str)
{
	char	c;

	(void)flg;
	c = **str;
	(*str)++;
	if (c == 'c')
		c = va_arg(st->args, int);
	st->nb_read += set_ret(flg, 1);
	check_dicuxp(flg, st, 1);
	ft_putchar(c);
	if (flg->dash == 1)
		print_field_d1(flg);
}

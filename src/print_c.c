/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 20:02:19 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/11 16:31:53 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	print_c(t_struct *st)
{
	char c;

	st->nb_str++;
	c = va_arg(st->args, int);
	if (st->field > 0 && st->prec == 0 && st->bool_s == 0)
	{
		st->bool = 1;
		check_diuxpc(st, 1);
	}
	else
		st->nb_read -= st->nb_str - 1;
	ft_putchar(c);
}

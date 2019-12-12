/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 20:02:19 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/12 15:46:55 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void	check(t_struct *st)
{
	if (st->field > 0 && st->prec == 0 && st->bool_s == 0)
	{
		if (st->dash == 1)
		{
			st->tmp2 = st->field - 1;
			st->field = 0;
		}
		st->bool = 1;
		check_diuxpc(st, 1);
	}
	else
		st->nb_read -= st->nb_str - 1;
}

void		print_c(t_struct *st)
{
	char c;

	st->nb_str++;
	c = va_arg(st->args, int);
	check(st);
	ft_putchar(c);
	if (st->dash == 1)
	{
		st->nb_read += st->tmp2;
		while (st->tmp2 > 0)
		{
			ft_putchar(' ');
			st->tmp2--;
		}
	}
}

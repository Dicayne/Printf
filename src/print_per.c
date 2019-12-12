/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_per.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:20:15 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/12 18:47:31 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void		check(t_struct *st)
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
	else if (st->field > 0 && st->prec > 0 && st->bool_s == 0)
	{
		st->nb_read -= st->nb_str - st->field;
		st->field -= 1;
		st->prec = 0;
		print_0(st);
	}
	else
		st->nb_read -= st->nb_str - 1;
}

void			print_per(t_struct *st)
{
	char c;

	st->nb_str++;
	c = '%';
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

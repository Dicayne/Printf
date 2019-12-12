/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_diuxpc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:48:20 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/12 16:23:49 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void		check_diuxpc2(t_struct *st, int size)
{
	st->tmp = st->field;
	st->field -= st->prec;
	st->prec -= size;
	print_0(st);
	st->nb_read += st->tmp - st->nb_str;
}

void			check_diuxpc(t_struct *st, int size)
{
	if (st->field <= size && st->prec <= size)
		st->nb_read += size - st->nb_str;
	else if (st->field > size && st->prec <= size)
	{
		st->prec = 0;
		st->field -= size;
		st->tmp = st->field;
		if (st->bool_s == 0)
			st->bool = 1;
		print_0(st);
		st->nb_read += st->tmp + size - st->nb_str;
	}
	else if (st->field <= st->prec && st->prec > size)
	{
		st->field = 0;
		st->prec -= size;
		st->tmp = st->prec;
		print_0(st);
		st->nb_read += st->tmp + size - st->nb_str;
	}
	else if (st->field > size && st->field > st->prec)
		check_diuxpc2(st, size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 23:36:57 by vmoreau           #+#    #+#             */
/*   Updated: 2020/01/09 23:23:58 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void		check_s3(t_flags *flg, t_struct *st, int size)
{
	if (flg->prec > size)
	{
		if (st->bool == 1)
			flg->field -= 6;
		flg->field -= size;
	}
	else if (flg->field == size && flg->prec >= 0 && flg->prec <= size)
		flg->field -= flg->prec;
	else if (flg->field > size && flg->prec <= size && flg->dash == 0)
		flg->field -= size;
	else if (flg->field > size && flg->prec < size)
		flg->field -= flg->prec;
	print_0s(flg);
}

static void		check_s2(t_flags *flg, t_struct *st, int size)
{
	if (flg->prec <= size && flg->prec >= 0)
	{
		st->read = flg->prec;
		if (flg->field > flg->prec && flg->dash != 1)
		{
			flg->field -= flg->prec;
			print_0s(flg);
		}
		else if (st->min_int == 1 && flg->dash == 0)
			flg->field = 0;
	}
	else
	{
		if (flg->prec_neg == 1)
			flg->field -= size;
		st->read = size;
	}
	if (flg->field >= size && st->min_int == 0)
		check_s3(flg, st, size);
}

void			check_s(t_flags *flg, t_struct *st, int size)
{
	if (flg->dash == 1)
	{
		if (flg->prec > size && st->min_int == 0)
			flg->field = flg->field - size;
		else if (flg->field > size && flg->prec < size && flg->dot == 1)
			flg->field = flg->field;
		else if (flg->prec > 0 && flg->dot == 1 && st->min_int == 0)
			flg->field = flg->field - flg->prec;
		else if (flg->dot == 0)
			flg->field = flg->field - size;
	}
	if (flg->dot == 0)
	{
		if (flg->dash == 0)
		{
			flg->field -= size;
			print_0s(flg);
		}
		st->read = size;
	}
	else if (flg->dot == 1)
		check_s2(flg, st, size);
}

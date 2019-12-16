/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 23:36:57 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/16 02:33:19 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

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
	}
	else
		st->read = size;
	if (flg->field >= size)
	{
		if (flg->prec > size)
			flg->field -= size;
		else if (flg->prec >= 0)
			flg->field -= flg->prec;
		else if (flg->field > size)
			flg->field -= size;
		print_0s(flg);
	}
}

void			check_s(t_flags *flg, t_struct *st, int size)
{
	if (flg->dash == 1)
	{
		if (flg->prec > size)
			flg->field = flg->field - size;
		else if (flg->field > size && flg->prec < size && flg->dot == 1)
			flg->field = flg->field;
		else if (flg->prec > 0 && flg->dot == 1)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:22:56 by vmoreau           #+#    #+#             */
/*   Updated: 2020/01/09 23:13:47 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void		print_field_d1s(t_flags *flg, t_struct *st, int size)
{
	if (st->min_int == 1 && flg->prec <= size)
		flg->field -= flg->prec;
	else if (st->min_int == 1 && flg->prec >= size)
		flg->field -= size;
	while (flg->field > 0)
	{
		ft_putchar(' ');
		flg->field--;
	}
}

void		print_field_d1(t_flags *flg)
{
	while (flg->field > 0)
	{
		ft_putchar(' ');
		flg->field--;
	}
}

void		print_0s(t_flags *flg)
{
	if (flg->zero == 0 && flg->dash == 0)
	{
		while (flg->field > 0)
		{
			ft_putchar(' ');
			flg->field--;
		}
	}
	else if (flg->zero == 1)
	{
		while (flg->field > 0)
		{
			ft_putchar('0');
			flg->field--;
		}
	}
}

static void	print_02(t_flags *flg)
{
	while (flg->field > 0)
	{
		ft_putchar('0');
		flg->field--;
	}
}

void		print_0(t_flags *flg)
{
	if (flg->zero == 0)
	{
		if (flg->dash == 0)
		{
			while (flg->field > 0)
			{
				ft_putchar(' ');
				flg->field--;
			}
		}
		while (flg->prec > 0)
		{
			ft_putchar('0');
			flg->prec--;
		}
	}
	else if (flg->zero == 1)
		print_02(flg);
}

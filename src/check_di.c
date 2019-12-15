/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 23:36:50 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/15 20:16:05 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void		check_di3(t_flags *flg, int size)
{
	if (flg->field > flg->prec && flg->prec >= size)
	{
		if (flg->prec >= size && flg->less == 1)
			flg->field = 0;
		else
			flg->field = flg->field - flg->prec;
		flg->prec = flg->prec - size;
		print_0(flg);
	}
	else if (flg->field > size && flg->prec < flg->field && flg->prec < size)
	{
		flg->field = flg->field - size;
		flg->prec = 0;
		print_0(flg);
	}
}

static void		check_di2(t_flags *flg, int nbr, int size)
{
	if (flg->field == 0 && flg->prec > size)
	{
		flg->prec = flg->prec - size;
		print_0(flg);
	}
	else if (flg->field > 0 && flg->prec == 0)
	{
		if (nbr < 0)
			flg->field = flg->field - size;
		else if (flg->field <= size && nbr != 0)
			flg->field = 0;
		else if (flg->field > size && nbr != 0)
			flg->field = flg->field - size;
		print_0(flg);
	}
	else if (flg->field <= flg->prec && flg->prec > size)
	{
		flg->field = 0;
		flg->prec = flg->prec - size;
		print_0(flg);
	}
	else
		check_di3(flg, size);
}

static void		check_di_d2(t_flags *flg, int size)
{
	if (flg->field <= size && flg->prec < size)
		flg->field = 0;
	else if (flg->field > size && flg->prec < size)
		flg->field -= size;
	else if (flg->field > size && flg->prec >= size && flg->prec <= flg->field)
	{
		flg->field -= flg->prec + size;
		flg->prec -= size;
		print_0(flg);
	}
	else if(flg->field > size && flg->prec >= size && flg->prec > flg->field)
	{
		flg->field = 0;
		flg->prec -= size;
		print_0(flg);
	}
	else if (flg->field <= size && flg->prec >= size)
	{
		flg->field = 0;
		flg->prec -= size;
		print_0(flg);
	}
}

static void		check_di_d1(t_flags *flg, int nbr, int size)
{
	if (nbr >= 0 && flg->less == 0)
	{
		if (flg->field <= size && flg->prec >= size)
		{
			flg->field = 0;
			if (flg->prec > size)
			{
				flg->prec -= size;
				print_0(flg);
			}
		}
		else if (flg->field > size && flg->prec > 0 && flg->prec <= size)
			flg->field -= size;
		else if (flg->field > size && flg->prec > size)
		{
			flg->field -= flg->prec;
			flg->prec -= size;
			print_0(flg);
		}
		else if (flg->field < size && flg->prec < flg->field)
			flg->field = 0;
		else if (flg->field >= size && flg->prec <= size && nbr > 0)
			flg->field -= size;
	}
	else if(nbr < 0 || flg->less == 1)
		check_di_d2(flg, size);
}

void			check_di(t_flags *flg, t_struct *st, int nbr, int size)
{
	if (flg->prec == 0 && flg->dot == 1 && nbr == 0)
		st->bool = 1;
	if (flg->dash == 1)
	{
		if(flg->dot == 0)
			flg->field -= size;
		else if (flg->dot == 1)
			check_di_d1(flg, nbr, size);
	}
	else
	{
		if(flg->dot == 0)
		{
			flg->field -= size;
			print_0(flg);
		}
		else if (flg->dot == 1)
			check_di2(flg, nbr, size);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:56:46 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/09 19:44:31 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int		find_size(int nb)
{
	int size;

	size = 0;
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		nb = -nb;
		size++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

void			print_di(t_struct *st)
{
	int nbr;

	nbr = va_arg(st->args, int);
	st->nb_str++;
	if (st->field > 0 && st->prec == 0)
	{
		st->field = st->field - find_size(nbr);
		st->nb_read = st->nb_read + find_size(nbr) + st->field - st->nb_str;
		print_0(st);
	}
	else if (st->prec > 0 && st->prec >= find_size(nbr))
	{
		if (st->field > 0 && st->field > st->prec)
			st->field = st->field - st->prec;
		else
			st->field = 0;
		st->prec = st->prec - find_size(nbr);
		st->nb_read += find_size(nbr) + st->field + st->prec - st->nb_str;
		print_0(st);
	}
	else
		st->nb_read = st->nb_read + find_size(nbr) - st->nb_str;
	ft_putnbr(nbr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:56:46 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/11 18:40:14 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int		find_size(int nb)
{
	int size;

	size = 0;
	if (nb == -2147483648)
		return (10);
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

static void		print(int nbr, t_struct *st)
{
	if (nbr > -2147483648)
	{
		if (nbr < 0)
			nbr = -nbr;
		ft_putnbr(nbr);
	}
	else
	{
		nbr = 214748364;
		ft_putnbr(nbr);
		ft_putchar('8');
	}
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

void			print_di(t_struct *st)
{
	int nbr;
	int size;

	st->nb_str++;
	nbr = va_arg(st->args, int);
	if (nbr < 0 && st->field == 0)
	{
		st->field--;
		st->nb_read++;
		ft_putchar('-');
		st->less = 2;
	}
	else if (nbr < 0 && st->field > 0)
	{
		st->prec++;
		st->less = 2;
	}
	size = find_size(nbr);
	if (st->dash == 1)
	{
		st->tmp2 = st->field - st->prec;
		st->field = 0;
	}
	check_diuxpc(st, size);
	print(nbr, st);
}

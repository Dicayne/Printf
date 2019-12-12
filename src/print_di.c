/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:56:46 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/12 21:36:02 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int		find_size(int nb, t_struct *st)
{
	int size;

	size = 0;
	if (nb == 0)
		return (1);
	if (nb == -2147483648)
		return (10);
	if (nb < 0)
	{
		if (st->dash == 0)
			size++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

static void		print(int nbr, t_struct *st, int size, int prectmp)
{
	if (st->tmp2 == -42)
		st->nb_read -= st->nb_str;
	else if (nbr > -2147483648)
	{
		printf("%d %d", st->bool, st->prec);
		if (st->bool == 1 && prectmp == 0 && nbr == 0)
		{
			ft_putchar(' ');
		}
		else
			ft_putnbr(nbr);
	}
	else
	{
		nbr = 214748364;
		if (st->bool_s2 == 0)
		{
			ft_putchar('-');
			st->nb_read++;
		}
		ft_putnbr(nbr);
		ft_putchar('8');
	}
	if (st->dash == 1 && st->tmp2 > size)
	{
		st->tmp2 -= size;
		st->nb_read += st->tmp2;
		while (st->tmp2 > 0)
		{
			ft_putchar(' ');
			st->tmp2--;
		}
	}
}

static void		check(t_struct *st, int *nbr)
{
	if (*nbr == 0 && st->bool_s2 == 1 && st->field == 0)
		st->tmp2 = -42;
	else if (*nbr < 0 && st->field == 0 && st->dash == 1)
	{
		st->field--;
		st->nb_read++;
		ft_putchar('-');
		st->less = 2;
	}
	else if (*nbr < 0 && st->field > 0 && st->dash == 1)
	{
		st->prec++;
		st->nb_read++;
		st->less = 2;
	}
	else if (*nbr < 0 && st->field > 0 && st->bool_s == 1)
	{
		if (st->bool_s2 == 0)
			st->field--;
		st->nb_read++;
		*nbr = -*nbr;
		ft_putchar('-');
	}
}

void			print_di(t_struct *st)
{
	int nbr;
	int size;
	int prectmp;
	
	st->nb_str++;
	nbr = va_arg(st->args, int);
	prectmp = st->prec;
	check(st, &nbr);
	size = find_size(nbr, st);
	if (st->dash == 1)
	{
		st->tmp2 = st->field - st->prec;
		st->field = 0;
	}
	if (st->tmp2 != -42)
		check_diuxpc(st, size);
	print(nbr, st, size, prectmp);
}

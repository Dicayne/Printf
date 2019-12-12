/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 20:33:11 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/12 18:23:09 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int		find_size(unsigned int nb)
{
	int size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

static void		ft_putnbr_u(unsigned int nb, t_struct *st, int size)
{
	if (st->tmp2 == -42)
		st->nb_read -= st->nb_str;
	else if (nb > 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	else
		ft_putchar(nb + '0');
	if (st->dash == 1)
	{
		if (st->tmp2 > size)
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
}

void			print_u(t_struct *st)
{
	unsigned int	nbr;
	int				size;

	st->nb_str++;
	nbr = va_arg(st->args, unsigned int);
	size = find_size(nbr);
	if (st->dash == 1)
	{
		st->tmp2 = st->field - st->prec;
		st->field = 0;
	}
	if (nbr == 0 && st->bool_s2 == 1 && st->field == 0)
		st->tmp2 = -42;
	if (st->tmp2 != -42)
		check_diuxpc(st, size);
	ft_putnbr_u(nbr, st, size);
}

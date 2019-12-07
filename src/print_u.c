/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 20:33:11 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/07 21:02:47 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int		find_size(unsigned int nb)
{
	int size;

	size = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

static void		ft_putnbr_u(unsigned int nb)
{
	if (nb > 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	else
		ft_putchar(nb + '0');
}

void			print_u(va_list args, int *ret)
{
	unsigned int nbr;

	nbr = va_arg(args, unsigned int);
	ft_putnbr_u(nbr);
	*ret = *ret + find_size(nbr) - 2;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 20:33:11 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/11 17:53:59 by vmoreau          ###   ########.fr       */
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

void			print_u(t_struct *st)
{
	unsigned int	nbr;
	int				size;

	st->nb_str++;
	nbr = va_arg(st->args, unsigned int);
	size = find_size(nbr);
	check_diuxpc(st, size);
	ft_putnbr_u(nbr);
}

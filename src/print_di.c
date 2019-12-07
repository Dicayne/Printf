/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:56:46 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/07 21:01:54 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int		find_size(int nb)
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

void			print_di(va_list args, int *ret)
{
	int nbr;

	nbr = va_arg(args, int);
	ft_putnbr(nbr);
	*ret = *ret + find_size(nbr) - 2;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:25:47 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/07 21:02:21 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int		find_size(unsigned long adrul)
{
	int size;

	size = 0;
	while (adrul > 0)
	{
		adrul = adrul / 16;
		size++;
	}
	return (size);
}

void			print_p(va_list args, int *ret)
{
	unsigned long	adrul;
	char			*adr;
	int				i;

	adrul = va_arg(args, unsigned long);
	i = find_size(adrul);
	*ret = *ret + i;
	adr = (char *)malloc(sizeof(char) * (i + 1));
	if (adr != NULL)
	{
		adr[i] = '\0';
		i--;
		while (adrul > 0)
		{
			adr[i] = HEXA_LOW[(adrul % 16)];
			adrul = adrul / 16;
			i--;
		}
		ft_putstr("0x");
		ft_putstr(adr);
		free(adr);
	}
}

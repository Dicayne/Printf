/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 21:06:02 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/07 21:13:46 by vmoreau          ###   ########.fr       */
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

void			print_xX(va_list args, int *ret, char x)
{
	unsigned long	adrul;
	char			*adr;
	int				i;
	char 			*hexa;

	if (x == 'X')
		hexa = HEXA_UP;
	else
		hexa = HEXA_LOW;
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
			adr[i] = hexa[(adrul % 16)];
			adrul = adrul / 16;
			i--;
		}
		ft_putstr(adr);
		free(adr);
	}
}

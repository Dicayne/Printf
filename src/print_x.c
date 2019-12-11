/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 21:06:02 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/11 16:32:07 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int		find_size(unsigned long adrul)
{
	int size;

	size = 0;
	if (adrul == 0)
		return (1);
	while (adrul > 0)
	{
		adrul = adrul / 16;
		size++;
	}
	return (size);
}

void			print_x(t_struct *st, char x)
{
	unsigned int	adrul;
	char			*adr;
	int				i;
	char			*hexa;

	st->nb_str++;
	if (x == 'X')
		hexa = HEXA_UP;
	else
		hexa = HEXA_LOW;
	adrul = va_arg(st->args, unsigned int);
	i = find_size(adrul);
	check_diuxpc(st, i);
	if (!(adr = (char *)malloc(sizeof(char) * (i + 1))))
		return ;
	adr[i] = '\0';
	i--;
	while (adrul > 0 || i >= 0)
	{
		adr[i] = hexa[(adrul % 16)];
		adrul = adrul / 16;
		i--;
	}
	ft_putstr(adr);
	free(adr);
}

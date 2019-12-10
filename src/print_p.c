/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:25:47 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/09 15:37:16 by vmoreau          ###   ########.fr       */
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

void			print_p(t_struct *st)
{
	unsigned long	adrul;
	char			*adr;
	int				i;

	adrul = va_arg(st->args, unsigned long);
	i = find_size(adrul);
	st->nb_read = st->nb_read + i;
	adr = (char *)malloc(sizeof(char) * (i + 1));
	if (adr != NULL)
	{
		adr[i] = '\0';
		i--;
		while (adrul > 0 || i >= 0)
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

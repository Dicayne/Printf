/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:25:47 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/12 16:01:11 by vmoreau          ###   ########.fr       */
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

static void		check(t_struct *st, int size)
{
	if (st->field > 0 && st->prec == 0 && st->bool_s == 0)
	{
		st->bool = 1;
		check_diuxpc(st, size);
	}
	else
		st->nb_read -= st->nb_str - size;
}

static void		print(t_struct *st, int size, int choice)
{
	if (st->dash == 1)
	{
		if (choice == 1)
		{
			st->tmp2 = st->field - (size + 2);
			st->field = 0;
		}
		else if (choice == 2)
		{
			if (st->tmp2 > size)
			{
				st->nb_read += st->tmp2;
				while (st->tmp2 > 0)
				{
					ft_putchar(' ');
					st->tmp2--;
				}
			}
		}
	}
}

void			print_p(t_struct *st)
{
	unsigned long	adrul;
	char			*adr;
	int				i;

	st->nb_str++;
	adrul = va_arg(st->args, unsigned long);
	i = find_size(adrul);
	print(st, i, 1);
	adr = (char *)malloc(sizeof(char) * (i + 1));
	if (adr != NULL)
	{
		check(st, i + 2);
		adr[i--] = '\0';
		while (adrul > 0 || i >= 0)
		{
			adr[i--] = HEXA_LOW[(adrul % 16)];
			adrul = adrul / 16;
		}
		ft_putstr("0x");
		ft_putstr(adr);
		print(st, i, 2);
		free(adr);
	}
}

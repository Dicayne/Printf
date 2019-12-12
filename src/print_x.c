/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 21:06:02 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/12 18:32:52 by vmoreau          ###   ########.fr       */
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

static void		check(t_struct *st, int size, int choice)
{
	if (st->dash == 1)
	{
		if (choice == 1)
		{
			st->tmp2 = st->field - size;
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

static int		init(t_struct *st, char x, char **hexa, unsigned int *adrul)
{
	st->nb_str++;
	*hexa = HEXA_LOW;
	if (x == 'X')
		*hexa = HEXA_UP;
	*adrul = va_arg(st->args, unsigned int);
	return (find_size(*adrul));
}

void			print_x(t_struct *st, char x)
{
	unsigned int	adrul;
	char			*adr;
	char			*hexa;
	int				i;

	i = init(st, x, &hexa, &adrul);
	check(st, i, 1);
	if (adrul == 0 && st->bool_s2 == 1 && st->field == 0)
		st->tmp2 = -42;
	if (st->tmp2 != -42)
		check_diuxpc(st, i);
	if (!(adr = (char *)malloc(sizeof(char) * (i + 1))))
		return ;
	adr[i--] = '\0';
	while (adrul > 0 || i >= 0)
	{
		adr[i--] = hexa[(adrul % 16)];
		adrul = adrul / 16;
	}
	if (st->tmp2 == -42)
		st->nb_read -= st->nb_str;
	else
		ft_putstr(adr);
	check(st, i, 2);
	free(adr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:50:54 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/12 17:25:48 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void		print(t_struct *st, int size, char *str)
{
	int i;

	i = 0;
	if (st->dash == 1)
	{
		st->tmp2 = st->field;
		st->field = 0;
	}
	check_s(st, size);
	while (str[i] != '\0' && i < st->field)
	{
		write(1, &str[i], 1);
		i++;
	}
	if (st->dash == 1)
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

void			print_s(t_struct *st)
{
	char	*str;
	int		size;
	int		bool;

	bool = 0;
	st->nb_str++;
	str = va_arg(st->args, char *);
	if (str == NULL)
		str = "(null)";
	size = ft_strlen(str);
	print(st, size, str);
}

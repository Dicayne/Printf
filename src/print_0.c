/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:22:56 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/09 19:14:06 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	print_0(t_struct *st)
{
	char c;
	char d;

	c = ' ';
	d = '0';
	if (st->bool == 1)
	{
		c = '0';
		d = ' ';
	}
	while (st->field > 0)
	{
		ft_putchar(d);
		st->field--;
	}
	while (st->prec > 0)
	{
		ft_putchar(c);
		st->prec--;
	}
}

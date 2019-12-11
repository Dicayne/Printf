/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:22:56 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/11 18:24:54 by vmoreau          ###   ########.fr       */
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
	if (st->less == 2)
		ft_putchar('-');
	while (st->prec > 0)
	{
		ft_putchar(c);
		st->prec--;
	}
}

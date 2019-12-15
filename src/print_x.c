/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 21:50:57 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/15 02:31:11 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void			print_x(t_struct *st, t_flags *flg, const char **str)
{
	char			*hexabase;
	char			*hex;
	unsigned int	nbr;
	int				i;

	(void)flg;
	hexabase = HEXA_LOW;
	if (**str == 'X')
		hexabase = HEXA_UP;
	(*str)++;
	nbr = va_arg(st->args, unsigned int);
	i = find_size_hex(nbr);
	st->nb_read += set_ret(flg, i);
	check_dicuxp(flg, st, i);
	hex = itoa_hex(nbr, i, hexabase);
	ft_putstr(hex);
	if (flg->dash == 1)
		print_field_d1(flg);
	free(hex);
}

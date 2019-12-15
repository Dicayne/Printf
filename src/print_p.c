/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 21:54:08 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/15 20:12:38 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void			print_p(t_struct *st, t_flags *flg, const char **str)
{
	char			*hexabase;
	char			*adr;
	unsigned long	nbr;
	int				i;

	(void)flg;
	hexabase = HEXA_LOW;
	nbr = va_arg(st->args, unsigned long);
	(*str)++;
	i = find_size_hex_ul(nbr);
	st->nb_read += set_ret(flg, nbr, i + 2);
	check_uxp(flg, st, nbr, i + 2);
	adr = itoa_hex_ul(nbr, i, hexabase);
	ft_putstr("0x");
	ft_putstr(adr);
	if (flg->dash == 1)
		print_field_d1(flg);
	free(adr);
}

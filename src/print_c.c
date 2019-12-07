/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 20:02:19 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/07 21:02:34 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	print_c(va_list args, int *ret)
{
	char c;

	*ret = *ret - 1;
	c = va_arg(args, int);
	ft_putchar(c);
}

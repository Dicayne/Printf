/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:50:54 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/07 21:03:13 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	print_s(va_list args, int *ret)
{
	char *str;

	str = va_arg(args, char *);
	*ret = *ret + ft_strlen(str) - 2;
	ft_putstr(str);
}

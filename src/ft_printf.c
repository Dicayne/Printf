/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:51:54 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/07 23:49:10 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	check_after_persent(const char *str, va_list args, int *ret)
{
	if (str[0] == '%')
	{
		ft_putchar('%');
		*ret = *ret - 1;
	}
	else if (str[0] == 's')
		print_s(args, ret);
	else if (str[0] == 'd' || str[0] == 'i')
		print_di(args, ret);
	else if (str[0] == 'c')
		print_c(args, ret);
	else if (str[0] == 'p')
		print_p(args, ret);
	else if (str[0] == 'u')
		print_u(args, ret);
	else if (str[0] == 'x' || str[0] == 'X')
		print_xX(args, ret, str[0]);
}

int		ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		nb_read;

	i = 0;
	nb_read = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			check_after_persent(&str[i], args, &nb_read);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	nb_read = nb_read + i;
	return (nb_read);
}

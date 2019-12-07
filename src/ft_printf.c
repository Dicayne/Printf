/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:51:54 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/07 21:12:49 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	check_after_persent(const char *str, va_list args, int *ret)
{
	int i;

	i = 1;
	if (str[i] == '%')
		ft_putchar('%');
	else if (str[i] == 's')
		print_s(args, ret);
	else if (str[i] == 'd' || str[i] == 'i')
		print_di(args, ret);
	else if (str[i] == 'c')
		print_c(args, ret);
	else if (str[i] == 'p')
		print_p(args, ret);
	else if (str[i] == 'u')
		print_u(args, ret);
	else if (str[i] == 'x' || str[i] == 'X')
		print_xX(args, ret, str[i]);
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
			check_after_persent(&str[i], args, &nb_read);
			str[i + 1] == '%' ? i = i + 2 : i++;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	nb_read = nb_read + i;
	return (nb_read);
}

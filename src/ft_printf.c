/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:51:54 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/06 20:32:37 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header/ft_printf.h"

void	check_after_persent(char *str, va_list args)
{
	int i;

	i = 1;
	if (str[i] == 's')
		print_s(args);
	else if (str[i] == 'd')
		print_d(args);
	else if (str[i] == 'i')
		print_i(args);
	else if (str[i] == 'c')
		print_c(args);
}

int		ft_printf(const char *str, ...)
{
	va_list args;
	int i;
	int nb_read;

	i = 0;
	nb_read = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
			{
				ft_putchar('%');
				i++;
			}
			check_after_persent((char *)&str[i], args);
			i++;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	nb_read = nb_read + i;
	return (nb_read);
}
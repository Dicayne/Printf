/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:51:54 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/10 20:24:12 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void		flags_0(const char *str, t_struct *st)
{
	if (str[st->i] == '0' || str[st->i] == '.')
	{
		st->i++;
		st->nb_str++;
		st->bool_s = 1;
	}
	while (str[st->i] >= '0' && str[st->i] <= '9')
	{
		st->field = st->field * 10 + (str[st->i] - '0');
		st->i++;
		st->nb_str++;
	}
	if (str[st->i] == '.')
	{
		st->i++;
		st->nb_str++;
		st->bool = 1;
	}
	while (str[st->i] >= '0' && str[st->i] <= '9')
	{
		st->prec = st->prec * 10 + (str[st->i] - '0');
		st->i++;
		st->nb_str++;
	}
}

static void		check_after_persent(const char *str, t_struct *st)
{
	st->field = 0;
	st->prec = 0;
	st->bool = 0;
	st->bool_s = 0;
	st->nb_str = 1;
	if (str[st->i] == '.' || (str[st->i] >= '0' && str[st->i] <= '9'))
		flags_0(str, st);
	if (str[st->i] == '%')
	{
		ft_putchar('%');
		st->nb_read--;
	}
	else if (str[st->i] == 's')
		print_s(st);
	else if (str[st->i] == 'd' || str[st->i] == 'i')
		print_di(st);
	else if (str[st->i] == 'c')
		print_c(st);
	else if (str[st->i] == 'p')
		print_p(st);
	else if (str[st->i] == 'u')
		print_u(st);
	else if (str[st->i] == 'x' || str[st->i] == 'X')
		print_x(st, str[st->i]);
}

int				ft_printf(const char *str, ...)
{
	t_struct st;

	st.i = 0;
	st.nb_read = 0;
	va_start(st.args, str);
	while (str[st.i] != '\0')
	{
		if (str[st.i] == '%')
		{
			st.i++;
			check_after_persent(str, &st);
		}
		else
			ft_putchar(str[st.i]);
		st.i++;
	}
	st.nb_read = st.nb_read + st.i;
	va_end(st.args);
	return (st.nb_read);
}

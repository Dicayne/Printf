/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:50:54 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/11 13:51:34 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void		check_st4(t_struct *st, int size)
{
	int tmp2;

	tmp2 = 0;
	if (st->prec <= size)
	{
		st->field -= st->prec;
		st->tmp = st->prec;
		tmp2 = st->field;
		st->prec = 0;
		print_0(st);
		st->field = st->tmp;
	}
	else if (st->prec > size)
	{
		st->field -= size;
		st->prec = 0;
		tmp2 = st->field;
		print_0(st);
		st->field = size;
	}
	st->nb_read += st->field + tmp2 - st->nb_str;
}

static void		check_st3(t_struct *st, int size)
{
	if (st->prec >= st->field)
	{
		if (st->field <= size && st->prec <= size)
			st->field = st->prec;
		else if (st->prec > size && st->field < size)
			st->field = size;
		else if (st->prec > size && st->field > size)
		{
			st->tmp = st->field;
			st->prec = 0;
			st->field -= size;
			print_0(st);
			st->field = st->tmp;
		}
		st->nb_read += st->field - st->nb_str;
	}
	else if (st->prec < st->field)
		check_st4(st, size);
}

static void		check_st2(t_struct *st, int size)
{
	if (st->bool_s == 1 && st->bool == 0)
	{
		if (st->field > size)
			st->field = size;
		st->nb_read += st->field - st->nb_str;
	}
	else if (st->bool_s == 0 && st->bool == 0)
	{
		if (st->field > size)
		{
			st->tmp = st->field;
			st->prec = st->field - size;
			st->field = 0;
			print_0(st);
			st->nb_read += st->tmp - st->nb_str;
			st->field = size;
		}
		else
		{
			st->field = size;
			st->nb_read += st->field - st->nb_str;
		}
	}
}

static void		check_st1(t_struct *st, int size)
{
	if (st->prec == 0 && st->field == 0 && st->bool_s == 0)
	{
		st->field = size;
		st->nb_read += st->field - st->nb_str;
	}
	else if (st->prec == 0 && st->field == 0 && st->bool_s == 1)
		st->nb_read -= st->nb_str;
	else if (st->field > 0 && st->prec == 0 && st->bool == 0)
		check_st2(st, size);
	else if (st->field > 0 && st->prec == 0 && st->bool == 1)
	{
		st->tmp = st->field;
		print_0(st);
		st->nb_read += st->tmp - st->nb_str;
	}
	else if (st->prec > 0 && st->field > 0)
		check_st3(st, size);
}

void			print_s(t_struct *st)
{
	char	*str;
	int		i;
	int		size;
	int		bool;

	i = 0;
	bool = 0;
	st->nb_str++;
	str = va_arg(st->args, char *);
	if (str == NULL)
		str = "(null)";
	size = ft_strlen(str);
	check_st1(st, size);
	while (str[i] != '\0' && i < st->field)
	{
		write(1, &str[i], 1);
		i++;
	}
}

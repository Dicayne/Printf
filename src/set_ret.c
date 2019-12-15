/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ret.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 00:53:51 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/15 02:59:08 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int		set_ret(t_flags *flg, int size)
{
	if (flg->field > size && flg->prec <= flg->field)
		return (flg->field);
	else if (flg->field > size && flg->prec > flg->field)
		return (flg->prec);
	else if (flg->field <  flg->prec&& flg->prec > size)
		return (flg->prec);
	else
		return (size);
}

int		set_ret_s(t_flags *flg, int size)
{
	if (flg->field > size && flg->prec <= flg->field)
		return (flg->field);
	else if (flg->field > size && flg->prec > flg->field)
		return (flg->prec);
	else if (flg->dot == 1 && flg->prec == 0 && flg->field == 0)
		return (0);
	else if (flg->dot == 1 && flg->prec == 0 && flg->field > 0)
		return (flg->field);
	else if (flg->prec < size && flg->prec > flg->field)
		return (flg->prec);
	else if (flg->field < size && flg->prec < flg->field)
		return (flg->field);
	else
		return (size);
}

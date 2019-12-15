/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dicuxp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 23:36:50 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/15 01:28:34 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	check_dicuxp(t_flags *flg, t_struct *st, int size)
{
	(void)st;
	if (flg->dash == 1)
	{
		if (flg->prec > size)
			flg->field = flg->field - flg->prec;
		else
			flg->field = flg->field - size;
	}
	else
	{
		if(flg->dot == 0)
		{
			flg->field -= size;
			print_0(flg);
		}
	}
}

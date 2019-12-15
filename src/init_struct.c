/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:03:16 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/15 02:46:51 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	init_struct(t_flags *flg, t_struct *st)
{
	flg->field = 0;
	flg->prec = 0;
	flg->dash = 0;
	flg->zero = 0;
	flg->dot = 0;
	st->min_int = 0;
	st->read = 0;
}

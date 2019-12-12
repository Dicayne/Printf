/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:23:09 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/12 18:20:57 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void		init_struct(t_struct *st)
{
	st->field = 0;
	st->prec = 0;
	st->bool = 0;
	st->bool_s = 0;
	st->bool_s2 = 0;
	st->nb_str = 1;
	st->dash = 0;
}

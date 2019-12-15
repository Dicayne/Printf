/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 14:31:00 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/15 16:16:55 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	check_cper(t_flags *flg, int size)
{
	if (flg->dash == 1)
			flg->field = flg->field - size;
	else
	{
			flg->field -= size;
			print_0s(flg);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:17:46 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/12 21:34:04 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"
#include <limits.h>

int main()
{
	int p;
	int ftp;
	
	ftp = ft_printf("M:%2i\n", 0);
		p =  printf("B:%2i\n", 0);
	printf("MYPF:%d			BASE:%d\n", ftp, p);
	if (p == ftp)
		printf("\033[0;42m               OK :) \033[0m\n");
	else
		printf("\033[0;41m               KO :( \033[0m\n");
	return (0);
}

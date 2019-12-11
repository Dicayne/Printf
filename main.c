/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:17:46 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/11 18:41:37 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"

int main()
{
	// char *str = "Coucou";
	// int nb = 42;
	// int nb2 = 24;
	//char c = 'p';
	//int nbu = -2147483648;
	int p;
	int ftp;
	//void *str = NULL;
	// ftp = printf("M:%10.9d\n", nbu);
	//  p =  printf("B:%10.9u\n", nbu);
	// 	  printf("U:%10.9x\n", nbu);
	ftp = ft_printf("M:%*.*dp%%\n", -20, 15, -12345);
		p =  printf("B:%*.*dp%%\n", -20, 15, -12345);
	printf("MYPF:%d			BASE:%d\n", ftp, p);
	if (p == ftp)
		printf("\033[0;42m               OK :) \033[0m\n");
	else
		printf("\033[0;41m               KO :( \033[0m\n");
	return (0);
}

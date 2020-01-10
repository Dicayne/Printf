/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:17:46 by vmoreau           #+#    #+#             */
/*   Updated: 2020/01/10 23:43:56 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"
#include <limits.h>

int main()
{
	int p;
	int ftp;

	ftp = ft_printf("M:%16.*d|\n", -8, -2147483647);
		p =  printf("B:%16.*d|\n", -8, -2147483647);
	printf("MYPF:%d			BASE:%d\n", ftp, p);
	if (p == ftp)
		printf("\033[0;42m               OK :) \033[0m\n");
	else
		printf("\033[0;41m               KO :( \033[0m\n");

	ftp = ft_printf("M:%.*i|\n", -6, -3);
		p =  printf("B:%.*i|\n", -6, -3);
	printf("MYPF:%d			BASE:%d\n", ftp, p);
	if (p == ftp)
		printf("\033[0;42m               OK :) \033[0m\n");
	else
		printf("\033[0;41m               KO :( \033[0m\n");
	return (0);
}

// int main()
// {
// 	int p;
// 	int ftp;

// 	ftp = ft_printf("M:%2i|\n", 0);
// 		p =  printf("B:%2i|\n", 0);
// 	printf("MYPF:%d			BASE:%d\n", ftp, p);
// 	if (p == ftp)
// 		printf("\033[0;42m               OK :) \033[0m\n");
// 	else
// 		printf("\033[0;41m               KO :( \033[0m\n");
	
// 	ftp = ft_printf("M:%2i|\n", -1);
// 		p =  printf("B:%2i|\n", -1);
// 	printf("MYPF:%d			BASE:%d\n", ftp, p);
// 	if (p == ftp)
// 		printf("\033[0;42m               OK :) \033[0m\n");
// 	else
// 		printf("\033[0;41m               KO :( \033[0m\n");
// 	return (0);
// }

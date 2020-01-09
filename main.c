/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:17:46 by vmoreau           #+#    #+#             */
/*   Updated: 2020/01/09 23:07:36 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"
#include <limits.h>

int main()
{
	int p;
	int ftp;

	ftp = ft_printf("M:%2.9p|\n", 1234);
		p =  printf("B:%2.9p|\n", 1234);
	printf("MYPF:%d			BASE:%d\n", ftp, p);
	if (p == ftp)
		printf("\033[0;42m               OK :) \033[0m\n");
	else
		printf("\033[0;41m               KO :( \033[0m\n");
	
	ftp = ft_printf("M:%5.p|\n", 0);
		p =  printf("B:%5.p|\n", 0);
	printf("MYPF:%d			BASE:%d\n", ftp, p);
	if (p == ftp)
		printf("\033[0;42m               OK :) \033[0m\n");
	else
		printf("\033[0;41m               KO :( \033[0m\n");

	ftp = ft_printf("M:%2.p|\n", NULL);
		p =  printf("B:%2.p|\n", NULL);
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

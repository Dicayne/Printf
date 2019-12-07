/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:17:46 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/07 23:58:43 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"

int main()
{
	char *str = "Coucou";
	int nb = -2147483648;
	char c = 'p';
	unsigned int nbu = 4294967295;
	int p;
	int ftp;

	ftp = ft_printf("MYPF :pst:%% s:|%s| x:|%x| X:|%X| i:|%i| p:|%p| u:|%u| d:|%d| c:|%c|\n", str, nb, nb, nb, str, nbu, nb, c);
		 p = printf("BASE :pst:%% s:|%s| x:|%x| X:|%X| i:|%i| p:|%p| u:|%u| d:|%d| c:|%c|\n", str, nb, nb, nb, str, nbu, nb, c);
	printf("MYPF:%d			BASE:%d\n", ftp, p);
	return (0);
}

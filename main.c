/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:17:46 by vmoreau           #+#    #+#             */
/*   Updated: 2019/12/07 21:11:24 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"

int main()
{
	char *str = "Coucou";
	int nb = 2335164;
	char c = 'p';
	int p;
	int ftp;
	unsigned int nbu = 4294967295;

	ftp = ft_printf("MYPF :s:|%s| d:|%d| c:|%c| i:|%i| Adresse:|%p| u:|%u| x:|%x| X: |%X|\n", str, nb, c, nb, str, nbu, nb, nb);
		 p = printf("BASE :s:|%s| d:|%d| c:|%c| i:|%i| Adresse:|%p| u:|%u| x:|%x| X: |%X|\n", str, nb, c, nb, str, nbu, nb, nb);
	printf("MYPF:%d			BASE:%d", ftp, p);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 09:09:20 by areid             #+#    #+#             */
/*   Updated: 2018/03/29 09:11:11 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wformat-extra-args"

int			main(void)
{
	int		myret;
	int		ret;

	printf("\n");
	myret = ft_printf("%-5%");
	printf("---%d\n", myret);
	ret = printf("%-5%");
	printf("---%d\n", ret);
	return (0);
}

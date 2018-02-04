/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 12:27:21 by areid             #+#    #+#             */
/*   Updated: 2018/02/04 15:00:56 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_str(char *str)
{
	while (str && *str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_printf(char *str, ...)
{
	int i;

	i = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
		}
		i++;
	}
	ft_print_str(str);
}

int main()
{
	int		num;

	num = 2;
	printf("Me\nComp\n\n");
//	ft_printf("HELLO\n%d");
	ft_printf("HELLO %d\n", num);
	printf("HELLO %d\n", num);
	return (0);
}

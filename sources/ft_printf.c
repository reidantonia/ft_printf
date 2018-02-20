/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 12:27:21 by areid             #+#    #+#             */
/*   Updated: 2018/02/12 11:31:36 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	ft_print_arg(char * argstr, char *str)
{
	if (*str == 's')
	{
		ft_putstr(argstr);
	}
}

void	ft_printf(char *argstr, ...)
{
	int					i;
	int					argnum;
	va_list				argptr;
	char				*str;

	va_start(argptr, argstr);
	i = 0;
	argnum = 0;
	str = ft_strdup(argstr);
	while (str[i] && str[i] != '\0')
	{
		if (str[i] == '%')
			argnum++;
		i++;
	}
	argnum = 0;
	
	while (str && *str != '\0')
	{
		while (str && *str != '\0' && *str != '%')
		{
			ft_putchar(*str);
			str++;
		}
		if (*str == '%')
		{
			str++;
			argnum++;
			argstr = va_arg(argptr, char *);
			ft_print_arg(argstr, str);
			str++;
		}
	}
}

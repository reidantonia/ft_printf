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

int	ft_print_arg(char *argstr, char *str)
{
	if (*str == 's')
	{
		ft_putstr(argstr);
	}
	else if (*str == '%' && argstr == NULL)
	{
		ft_putstr("%");
		return (1);
	}
	return (ft_strlen(argstr));
}

int	ft_printf(char *argstr, ...)
{
//	int					i;
//	int					argnum;
	va_list				argptr;
	char				*str;
	int					run_len;

	va_start(argptr, argstr);
//	i = 0;
//	argnum = 0;
	str = ft_strdup(argstr);
	run_len = 0;
//	while (str[i] && str[i] != '\0')
//	{
//		if (str[i] == '%' && str[i + 1] != '%')
//			argnum++;
//		i++;
//	}
//	argnum = 0;
	while (str && *str != '\0')
	{
		while (str && *str != '\0' && *str != '%')
		{
			ft_putchar(*str);
			str++;
			run_len++;
		}
		if (*str == '%')
		{
			str++;
			//argnum--;
			if (!(argstr = va_arg(argptr, char *)))
				argstr = NULL;
			printf("argstr is %s\n\n", argstr);
			run_len += ft_print_arg(argstr, str);
			str++;
		}
	}
	return (run_len);
}

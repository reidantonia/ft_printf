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


void	ft_print_padding(int len)
{
	while (len)
	{
	ft_putchar(' ');
	len--;
	}
}

int		ft_max(int arglen, int padding_val)
{
	int max;

	max = arglen;
	if (padding_val > max)
	max = padding_val;
	return (max);
}

t_args	ft_print_arg(char *argstr, char *str)
{
	int padding_val;
	int digits;
	t_args	len;
	int arglen;

	len.value_length = 0;
	padding_val = ft_atoi(str);
	digits = ft_cntdigits(padding_val);
	str = str + digits;
	while (*str == ' ')
	{
	str++;
	}
	if (*str == 's')
	{
		arglen = ft_strlen(argstr);
		ft_print_padding(padding_val-arglen);
		ft_putstr(argstr);
		len.value_length = ft_max(arglen, padding_val);
		len.code_length = digits + 1;
	}
	else if (*str == '%')
	{
		ft_putstr("%");
		len.code_length = 1;
		len.value_length = 1;
	}
	return (len);
}

int	ft_printf(char *argstr, ...)
{
	va_list				argptr;
	char				*str;
	int					run_len;
	t_args				ret;

	va_start(argptr, argstr);
	str = ft_strdup(argstr);
	run_len = 0;
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
			argstr = va_arg(argptr, char*);
			ret = ft_print_arg(argstr, str);
			run_len += ret.value_length;
			str += ret.code_length;
		}
	}
	va_end(argptr);
	return (run_len);
}

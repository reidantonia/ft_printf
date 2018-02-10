/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 12:27:21 by areid             #+#    #+#             */
/*   Updated: 2018/02/10 22:13:17 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

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

t_args		ft_process(char *str) 
{
	t_args	arg;
	int i;

	i = 0;
	if (str[0] == '-')
		arg.align = "left";
	else if (str[0] == '0')
		arg.zero_fill = "yes";
	if (ft_isdigit(str[i]) && str[i] != '0')
	{
		while (ft_isdigit(str[i]))
			i++;
		arg.width = atoi(ft_strsub(str, 0, i));
	}
	//arg.code_length = i;
	return (arg);
}

void	ft_printf(char *str, ...)
{
	int			i;
	int			argnum;
	va_list		argptr;
	t_args		*arg;

	va_start(argptr, str);
	i = 0;
	argnum = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] == '%')
			argnum++;
		i++;
	}
	printf("num of args is %d\n", argnum);
	arg = (t_args*)ft_strnew(argnum + 1);
	i = 0;
	argnum = 0;
	while (str && str[i] != '\0')
	{
		while (str && str[i] != '\0' && str[i] != '%')
		{
			ft_putchar(str[i]);
			i++;
		}
		if (str[i] == '%')
		{
		argnum++;
		arg[argnum] = ft_process(ft_strsub(str, i, ft_strlen(str)));
		i = i + arg[argnum].code_length;
		}
		i++;
	}
}

int main()
{
	int		num;
	char *lel = "lelstr";
	char *dog = "dogstr";
	char *cat = "catstr";
	char *hii = "hiistr";

	num = 2;
	ft_printf("ME:HELLO %s %s %s %s", hii, cat, dog, lel);
	printf("\nCOMPUTER:HELLO %d\n", num);
	return (0);
}

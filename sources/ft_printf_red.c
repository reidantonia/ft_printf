/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 12:27:21 by areid             #+#    #+#             */
/*   Updated: 2018/02/11 17:52:39 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_args	ft_process(char *str)
{	
	t_args	arg;
	int		i;

	i = 0;
	printf("the string is: '%s'\n", str);
	if (str[0] == 's')
	{
		arg.id = 's';
		arg.code_length = 1;
		i++;
		printf("arg.id is '%c'\n", arg.id);
		return (arg);
	}
	else if (str[0] == '-' && str[i] != '\0')
	{
		arg.align = "left";
		i++;
	}
	else if (str[0] == '0' && str[i] != '\0')
	{
		arg.zero_fill = "yes";
		i++;
	}
	if (ft_isdigit(str[i]) && str[i] != '0' && str[i] != '\0')
	{
		while (ft_isdigit(str[i]) && str[i] != '\0')
			i++;
		arg.width = ft_atoi(ft_strsub(str, 0, i));
	}
	arg.code_length = i;
	free(str);
	return (arg);
}

void	ft_print_arg(t_args arg, char *str)
{
	if (arg.id == 's')
	{
		ft_putstr(str);
//	printf("%s", str);fflush(stdout);
}
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
			i++;
			argnum++;
			arg[argnum] = ft_process(ft_strsub(str, i, ft_strlen(str)));
			ft_print_arg(arg[argnum], va_arg(argptr, char*));
			i = i + arg[argnum].code_length;
		}
		i++;
	}
}

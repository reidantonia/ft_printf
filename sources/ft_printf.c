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

struct t_args	ft_process(char *str, t_args arg)
{	
	//struct t_args	arg;
	
	arg.code_length = 1;
	arg.id = 's';
	/*//int		i;

	//i = 0;
	if (str[0] == 's')
	{
		arg.id = 's';
		arg.code_length = 1;
	//	i++;
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
	free(str);*/
	return (arg);
}

void	ft_print_arg(t_args arg, char *str)
{
	if (arg.id == 's')
	{
		ft_putstr(str);
	}
}

void	ft_printf(char *argstr, ...)
{
	int			i;
	int			argnum;
	va_list		argptr;
	t_args		*arg;
	char		*str;

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
	printf("num of args is %d\noriginal: '%s'\n\n", argnum, str);
	arg = (t_args*)ft_strnew(argnum + 1);
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
			argnum++;
			argstr = va_arg(argptr, char *);
			arg[argnum] = ft_process(ft_strsub(str, 0, ft_strlen(str)), arg);
			//ft_print_arg(arg[argnum], argstr);
			str++;
		}
	}
printf("\n*********************************************\n\n");
}

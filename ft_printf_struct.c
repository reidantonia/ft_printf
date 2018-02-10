/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 12:27:21 by areid             #+#    #+#             */
/*   Updated: 2018/02/10 14:37:51 by areid            ###   ########.fr       */
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

void	ft_printf(char *str, ...)
{
		int i;
		int	argnum;
		va_list argptr;
		t_args *arg;

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
		i = 0;
		arg = (t_args*)ft_strnew(argnum + 1);
		while (i <= argnum)
		{
				arg[i].value = ft_strdup((char *)str);
				printf("\ni is %d\n", i);
				printf("ret[%d].value is %s", i, arg[i].value);
				str = va_arg(argptr, char *);
				i++;
		}
		va_end(argptr);
}

int main()
{
		int		num;
char *lel = "lelstr";		
		char *dog = "dogstr";
		char *cat = "catstr";
		char *hii = "hiistr";


		num = 2;
		printf("Me\nComp\n\n");
		//	ft_printf("HELLO\n%d");
		ft_printf("HELLO %s %s %s %d\n", hii, cat, dog, lel);
		printf("\n\nHELLO %d\n", num);
		return (0);
}

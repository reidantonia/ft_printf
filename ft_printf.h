/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 12:27:49 by areid             #+#    #+#             */
/*   Updated: 2018/02/04 15:00:09 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
//#include "libft/libft.a"

typedef structs
{
	char fid;
	char flag;
}


int	ft_atoi(const char *s);   //remove when have lib
char *ft_strnew(size_t size); //////remove later
char *ft_strdup(const char *src);

#endif

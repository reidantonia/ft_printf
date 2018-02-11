/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 12:27:49 by areid             #+#    #+#             */
/*   Updated: 2018/02/11 11:08:15 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

typedef struct		s_args
{
	char	id;
	char	flag;
	int		code_length;
	char	value_length;
	char	*value;
	int		width;
	char	*align;
	char	*zero_fill;
}					t_args;


int		ft_atoi(const char *s);
char	*ft_strnew(size_t size);
char	*ft_strdup(const char *src);
int		ft_isdigit(int c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);

#endif

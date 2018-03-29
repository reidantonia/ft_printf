/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 12:27:49 by areid             #+#    #+#             */
/*   Updated: 2018/03/29 09:19:17 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/include/libft.h"

typedef struct		s_args
{
	char			value_length;
	int				code_length;
/*char			id;
	char			flag;
	char			*value;
	int				width;
	char			*align;
	char			*zero_fill;*/
}					t_args;

int					ft_printf(char *str, ...);
int					ft_atoi(const char *s);
char				*ft_strnew(size_t size);
char				*ft_strdup(const char *src);
int					ft_isdigit(int c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *s);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
int					ft_cntdigits(long long n);
#endif

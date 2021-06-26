/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:38:13 by seungcoh          #+#    #+#             */
/*   Updated: 2021/06/26 16:45:59 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

#include<stdio.h>

typedef struct	s_cond
{
	int			m_flag;
	int			h_flag;
	int			n_flag;
	int			flag;
	long		width;
	long		prec;
	char		spec;
}				t_cond;

typedef struct	s_idx
{
	int			offset;
	int			width;
	int			prec;
	int			len;
	int			i;
}				t_idx;

int				ft_strlen(const char *str);
char			*ft_strdup(const char *src);
int				ft_max(const long a, const long b);
int				ft_min(const long a, const long b);
char			*ft_ntoa(long long n, int digit, t_cond *stat);
void			check_flag(const char **format, t_cond *stat);
void			check_width(const char **format, va_list ap, t_cond *stat);
void			check_precision(const char **format, va_list ap, t_cond *stat);
char			*check_specifier(const char **format, va_list ap, t_cond *stat);
char			*print_cpe(va_list ap, t_cond *stat, int c_flag);
char			*print_s(va_list ap, t_cond *stat);
char			*print_diuxp(va_list ap, t_cond *stat);
int				ft_printf(const char *format, ...);
#endif

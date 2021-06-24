/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:37:42 by seungcoh          #+#    #+#             */
/*   Updated: 2021/06/24 17:11:06 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init(t_cond *stat)
{
	stat->m_flag = 0;
	stat->hex_flag = 0;
	stat->flag = 0;
	stat->spec = 0;
	stat->prec = 2147483648;
	stat->width = -1;
}

char	*check_ap(const char **format, va_list ap, t_cond *stat)
{
	char *ret;

	ret = 0;
	(*format)++;
	check_flag(format, stat);
	check_width(format, ap, stat);
	check_precision(format, ap, stat);
	return (check_specifier(format, ap, stat));
}

int		print_format(const char **format, va_list ap)
{
	int		len;
	int		ret;
	char	*prt;
	t_cond	stat;

	ret = 0;
	while (**format)
	{
		if (**format == '%')
		{
			init(&stat);
			if((prt = check_ap(format, ap, &stat)))
			{
				write(1, prt, (len = ft_strlen(prt)));
				ret += len;
			}
			free(prt);
		}
		else
		{
			write(1, (*format)++, 1);
			ret++;
		}
	}
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = print_format(&format, ap);
	va_end(ap);
	return (ret);
}

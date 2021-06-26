/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:15:48 by seungcoh          #+#    #+#             */
/*   Updated: 2021/06/26 16:28:39 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flag(const char **format, t_cond *stat)
{
	while (**format == '0' || **format == '-')
	{
		if (**format == '0')
			stat->flag |= (1 << 0);
		if (**format == '-')
			stat->flag |= (1 << 1);
		(*format)++;
	}
}

void	check_width(const char **format, va_list ap, t_cond *stat)
{
	long	val;

	if (**format == '*')
	{
		val = va_arg(ap, int);
		if (val < 0)
		{
			stat->flag |= (1 << 1);
			val = -val;
		}
		stat->width = val;
		(*format)++;
		return ;
	}
	val = 0;
	while ('0' <= **format && **format <= '9')
	{
		val *= 10;
		val += **format - '0';
		(*format)++;
	}
	stat->width = val;
}

void	check_precision(const char **format, va_list ap, t_cond *stat)
{
	long	val;
	int		m_flag;

	val = 0;
	m_flag = 0;
	if (**format != '.')
		return ;
	(*format)++;
	if (**format == '*')
	{
		val = va_arg(ap, int);
		(*format)++;
	}
	else if (**format == '-')
	{
		(*format)++;
		m_flag = 1;
	}
	while ('0' <= **format && **format <= '9')
	{
		val *= 10;
		val += *(*format)++ - '0';
	}
	stat->prec = (val >= 0 && !m_flag) ? val : 2147483648;
}

char	*check_specifier(const char **format, va_list ap, t_cond *stat)
{
	char	*ret;

	ret = 0;
	if (**format == 'c' || **format == '%')
		ret = print_cpe(ap, stat, (int)('c' - **format));
	else if (**format == 's')
		ret = print_s(ap, stat);
	else if (**format == 'd' || **format == 'i' || **format == 'u' \
	|| **format == 'x' || **format == 'X')
	{
		stat->spec = **format;
		ret = print_diuxp(ap, stat);
	}
	else if (**format == 'p')
	{
		stat->spec = **format;
		stat->h_flag = 2;
		ret = print_diuxp(ap, stat);
	}
	else
		return (ret);
	(*format)++;
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 13:57:25 by seungcoh          #+#    #+#             */
/*   Updated: 2021/06/26 14:33:04 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	long	ft_abs(long long n, t_cond *stat)
{
	if (n < 0 && stat->spec != 'p')
		n = -1 * n;
	return (n);
}

static	char	*fill_num(int size, long long temp, t_cond *stat, int digit)
{
	char				*ret;
	int					val;
	int					hex;
	unsigned long long	utemp;

	hex = (stat->spec == 'p') ? 2 : 0;
	utemp = temp;
	if (!(ret = (char*)malloc(sizeof(char) * (size + hex + 1))))
		return (0);
	ret[size-- + hex] = 0;
	if (stat->spec == 'p')
		while (size - stat->m_flag >= 0)
		{
			val = utemp % digit;
			if ((val = utemp % digit + '0') > 9 + '0')
				val += 'a' - 10 - '0';
			ret[size-- + hex] = val;
			utemp /= digit;
		}
	else {
		while (size - stat->m_flag >= 0)
		{
			val = temp % digit;
			if ((val = temp % digit + '0') > 9 + '0')
				val += 'a' - 10 - '0';
			ret[size-- + hex] = val;
			temp /= digit;
		}
	}
	if (stat->m_flag == 1)
		ret[0] = '-';
	if (stat->spec == 'p')
	{
		ret[0] = '0';
		ret[1] = 'x';
	}
	return (ret);
}

char			*ft_ntoa(long long n, int digit, t_cond *stat)
{
	int					size;
	char				*ret;
	long long			temp;
	int					i;
	unsigned long long	utemp;

	temp = n;
	utemp = n;
	size = 1;
	if (temp < 0 && stat->spec != 'p')
	{
		temp *= -1;
		stat->m_flag = 1;
	}
	if (stat->spec == 'p')
		while (utemp /= digit)
			size++;
	else
		while (temp /= digit)
			size++;
	temp = ft_abs(n, stat);
	ret = fill_num(size + stat->m_flag, temp, stat, digit);
	i = -1;
	if ('X' == stat->spec)
		while (++i < size)
			if ('a' <= ret[i] && ret[i] <= 'f')
				ret[i] -= 32;
	return (ret);
}

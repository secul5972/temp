/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 13:57:25 by seungcoh          #+#    #+#             */
/*   Updated: 2021/06/26 19:28:01 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	long	ft_abs(long long n, t_cond *stat)
{
	if (n < 0)
	{
		n = -1 * n;
		stat->m_flag = 1;
	}
	return (n);
}

static	char	*fill_num(int size, long long temp, t_cond *stat, int digit)
{
	char	*ret;
	int		val;

	if (!(ret = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	ret[size--] = 0;
	while (size - stat->m_flag >= 0)
	{
		val = temp % digit;
		if ((val = temp % digit + '0') > 9 + '0')
			val += 'a' - 10 - '0';
		ret[size--] = val;
		temp /= digit;
	}
	if (stat->m_flag == 1)
		ret[0] = '-';
	return (ret);
}

char			*ft_ntoa(long long n, int digit, t_cond *stat)
{
	int			size;
	char		*ret;
	long long	temp;
	int			i;

	temp = ft_abs(n, stat);
	size = 1;
	while (temp /= digit)
		size++;
	ret = fill_num(size + stat->m_flag, ft_abs(n, stat), stat, digit);
	i = -1;
	if ('X' == stat->spec)
		while (++i < size)
			if ('a' <= ret[i] && ret[i] <= 'f')
				ret[i] -= 32;
	return (ret);
}

char			*ft_ptoa(unsigned long long n, int digit, t_cond *stat)
{
	int					size;
	char				val;
	char				*ret;
	unsigned long long	utemp;

	utemp = n;
	size = 1;
	while (n /= digit)
		size++;
	if (!(ret = (char*)malloc(sizeof(char) * (size + stat->h_flag + 1))))
		return (0);
	ret[size-- + stat->h_flag] = 0;
	while (size - stat->m_flag >= 0)
	{
		val = utemp % digit;
		if ((val = utemp % digit + '0') > 9 + '0')
			val += 'a' - 10 - '0';
		ret[size-- + stat->h_flag] = val;
		utemp /= digit;
	}
	ret[0] = '0';
	ret[1] = 'x';
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:30:29 by oseungcheol       #+#    #+#             */
/*   Updated: 2021/08/26 13:32:13 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data_ptr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_streq(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] == s2[i])
        return (1);
    else
        return (0);
}

int ft_min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

long ft_atol(const char *str)
{
	size_t	i;
	long	ret;
	int		m_flag;

	i = 0;
	m_flag = 0;
	ret = 0;
	while (str[i] == 9 || str[i] == 10 || str[i] == 11
	|| str[i] == 12 || str[i] == 13 || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		m_flag = str[i++] - '+';
	while ('0' <= str[i] && str[i] <= '9')
	{
		ret *= 10;
		ret += str[i] - '0';
		i++;
	}
	if (m_flag != 0)
		ret *= -1;
	return (ret);
}

int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

double ft_atod(const char *str)
{
	int len;
	int m_flag;
	int i;
	double ret;
	double temp;

	i = 0;
	m_flag = 1;
	len = ft_strlen(str);
	if (str[0] == '-')
	{
		m_flag = -1;
		i++;
	}
	ret = ft_atol(str);
	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] == '.')
		i++;
	temp = ft_atol(str + i);
	i = len - i;
	while (i--)
		temp /= 10;
	ret += temp;
	return m_flag * ret;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:42:58 by seungcoh          #+#    #+#             */
/*   Updated: 2021/06/26 19:28:11 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(const char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*ret;
	int		s_len;

	s_len = ft_strlen(src);
	if (!(ret = (char *)malloc(sizeof(char) * (s_len + 1))))
		return (0);
	while (s_len >= 0)
	{
		ret[s_len] = src[s_len];
		s_len--;
	}
	return (ret);
}

int		ft_max(const long a, const long b)
{
	if (a > b)
		return (a);
	return (b);
}

int		ft_min(const long a, const long b)
{
	if (a < b)
		return (a);
	return (b);
}

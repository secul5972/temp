/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:42:58 by seungcoh          #+#    #+#             */
/*   Updated: 2021/06/24 14:35:55 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_max(const long a, const long b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(const long a, const long b)
{
	if (a < b)
		return (a);
	return (b);
}

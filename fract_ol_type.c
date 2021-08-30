/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 01:08:28 by seungcoh          #+#    #+#             */
/*   Updated: 2021/08/31 01:36:39 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	Mandelbrot(t_d_pair p)
{
	int			i;
	t_d_pair	z;
	double		t;

	i = 0;
	z.x = p.x;
	z.y = p.y;
	while (z.x * z.x + z.y * z.y <= 4 && i < LOOP_LIMIT)
	{
		t = z.x * z.x - z.y * z.y + p.x;
		z.y = 2 * z.x * z.y + p.y;
		z.x = t;
		i++;
	}
	return (i);
}

int	Julia(t_d_pair p, t_d_pair j_p)
{
	int			i;
	t_d_pair	z;
	double		t;

	i = 0;
	z.x = p.x;
	z.y = p.y;
	while (z.x * z.x + z.y * z.y <= 4 && i < LOOP_LIMIT)
	{
		t = z.x * z.x - z.y * z.y + j_p.x;
		z.y = 2 * z.x * z.y + j_p.y;
		z.x = t;
		i++;
	}
	return (i);
}

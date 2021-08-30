/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 01:10:08 by seungcoh          #+#    #+#             */
/*   Updated: 2021/08/31 01:44:53 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data_ptr + \
	(y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	coloring_pixel(t_frac_data *frac, t_d_pair p, int i, int j)
{
	int	val;

	if (frac->f_flag == 1)
	{
		val = Mandelbrot(p);
		if (val != LOOP_LIMIT)
			my_mlx_pixel_put(&frac->img, i, j, \
			(255 - val / 10) * 0x10000 + 10 * val * 0x100 + 20 * (val / 20));
		if (val == LOOP_LIMIT)
			my_mlx_pixel_put(&frac->img, i, j, 0);
	}
	else if (frac->f_flag == 2)
	{
		val = Julia(p, frac->julia_comp);
		if (val != LOOP_LIMIT)
			my_mlx_pixel_put(&frac->img, i, j, \
			20 * (val / 16) * 0x10000 + 16 * val * 0x100 + (255 - val / 16));
		if (val == LOOP_LIMIT)
			my_mlx_pixel_put(&frac->img, i, j, 0);
	}
}

void	draw_frac(t_frac_data *frac)
{
	int			i;
	int			j;
	int			l;
	t_d_pair	p;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < LENGTH)
		{
			p.x = frac->center.x + (double)i / frac->pixel - frac->w_l.x / 2;
			p.y = frac->center.y + (double)j / frac->pixel - frac->w_l.y / 2;
			coloring_pixel(frac, p, i, j);
			j++;
		}
		i++;
	}
}

int	press_esc(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int	press_wheel(int keycode, int x, int y, t_frac_data *frac)
{
	if (keycode == 4 || keycode == 5)
	{
		frac->mouse.x = (double)x / frac->pixel - frac->w_l.x / 2;
		frac->mouse.y = (double)y / frac->pixel - frac->w_l.y / 2;
		if (keycode == 5)
		{
			frac->center.x += -frac->mouse.x * (ZOOM_RATE - 1);
			frac->center.y += -frac->mouse.y * (ZOOM_RATE - 1);
			frac->pixel /= ZOOM_RATE;
			frac->w_l.x *= ZOOM_RATE;
			frac->w_l.y *= ZOOM_RATE;
		}
		else
		{
			frac->center.x += frac->mouse.x * (1 - 1 / ZOOM_RATE);
			frac->center.y += frac->mouse.y * (1 - 1 / ZOOM_RATE);
			frac->pixel *= ZOOM_RATE;
			frac->w_l.x /= ZOOM_RATE;
			frac->w_l.y /= ZOOM_RATE;
		}
		draw_frac(frac);
		mlx_put_image_to_window(frac->mlx, frac->win, frac->img.img_ptr, 0, 0);
	}
	return (0);
}

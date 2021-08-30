/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:25:54 by oseungcheol       #+#    #+#             */
/*   Updated: 2021/08/31 01:02:29 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_d_pair get_julia_para(int flag, char **argc)
{
	t_d_pair ret;

	ret.x = 0;
	ret.y = 0;
	if (flag != 2)
		return ret;
	ret.x = ft_atod(argc[2]);
	ret.y = ft_atod(argc[3]);
	return ret;
}

int fract_ol_init(t_frac_data *frac, t_img *img, char **argc)
{
	frac->mlx = mlx_init();
	frac->win = mlx_new_window(frac->mlx, WIDTH, LENGTH, "fract_ol");
	img->img_ptr = mlx_new_image(frac->mlx, WIDTH, LENGTH);
	img->data_ptr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, &img->line_length, &img->endian);
	if (frac->mlx == 0 || frac->win == 0 || img->img_ptr == 0 || img->data_ptr == 0)
	{
		printf("mlx error\n");
		return 0;
	}
	frac->wheel_cnt = 0;
	frac->center.x = 0;
	frac->center.y = 0;
	frac->pixel = ft_min(WIDTH, LENGTH) / 4;
	frac->w_l.x = WIDTH / frac->pixel;
	frac->w_l.y = LENGTH / frac->pixel;
	frac->r_center.x = 0;
	frac->r_center.y = 0;
	frac->julia_comp = get_julia_para(frac->f_flag, argc);
	return 1;
}

int Mandelbrot(t_d_pair p)
{
	int i;
	t_d_pair z;
	double t;

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
	return i;
}

int Julia(t_d_pair p, t_d_pair j_p)
{
	int i;
	t_d_pair z;
	double t;

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
	return i;
}

void draw_frac(t_frac_data *frac)
{
	int i;
	int j;
	int l;
	t_d_pair p;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < LENGTH)
		{
			p.x = frac->center.x + (double)i / frac->pixel - frac->w_l.x / 2;
			p.y = frac->center.y + (double)j / frac->pixel - frac->w_l.y / 2;
			if (frac->f_flag == 1)
			{
				l = Mandelbrot(p);
				if (l != LOOP_LIMIT)
					my_mlx_pixel_put(&frac->img, i, j, (255 - l / 10) * 0x10000 + 10 * l * 0x100 + 20 * (l / 20));
				if (l == LOOP_LIMIT)
					my_mlx_pixel_put(&frac->img, i, j, 0);
			}
			else if (frac->f_flag == 2)
			{
				l = Julia(p, frac->julia_comp);
				if (l != LOOP_LIMIT)
					my_mlx_pixel_put(&frac->img, i, j, 20 * (l / 16) * 0x10000 + 16 * l * 0x100 + (255 - l / 16));
				if (l == LOOP_LIMIT)
					my_mlx_pixel_put(&frac->img, i, j, 0);
			}
			j++;
		}
		i++;
	}
}

int press_esc(int keycode)
{
	if (keycode == 53)
		exit(0);
	return 0;
}

int press_wheel(int keycode, int x, int y, t_frac_data *frac)
{
	t_d_pair mouse;

	if (keycode == 4 || keycode == 5)
	{
		mouse.x = (double)x / frac->pixel - frac->w_l.x / 2;
		mouse.y = (double)y / frac->pixel - frac->w_l.y / 2;
		if (keycode == 5)
		{
			frac->center.x += -mouse.x * (ZOOM_RATE - 1);
			frac->center.y += -mouse.y * (ZOOM_RATE - 1);
			frac->pixel /= ZOOM_RATE;
			frac->w_l.x *= ZOOM_RATE;
			frac->w_l.y *= ZOOM_RATE;
		}
		else
		{
			if (mouse.x > 0)
				frac->center.x += (frac->w_l.x / 2 - mouse.x) / ZOOM_RATE + mouse.x - frac->w_l.x / ZOOM_RATE / 2;
			else
				frac->center.x += -(frac->w_l.x / 2 + mouse.x) / ZOOM_RATE + mouse.x + frac->w_l.x / ZOOM_RATE / 2;
			if (mouse.y > 0)
				frac->center.y += (frac->w_l.y / 2 - mouse.y) / ZOOM_RATE + mouse.y - frac->w_l.x / ZOOM_RATE / 2;
			else
				frac->center.y += -(frac->w_l.y / 2 + mouse.y) / ZOOM_RATE + mouse.y + frac->w_l.x / ZOOM_RATE / 2;
			frac->pixel *= ZOOM_RATE;
			frac->w_l.x /= ZOOM_RATE;
			frac->w_l.y /= ZOOM_RATE;
		}
		draw_frac(frac);
		mlx_put_image_to_window(frac->mlx, frac->win, frac->img.img_ptr, 0, 0);
	}
	return 0;
}

int set_frac_flag(int argv, char **argc)
{
	if ((argv != 2 && argv != 4) || (argv == 2 && !ft_streq(argc[1], "Mandelbrot")) || (argv == 4 && !ft_streq(argc[1], "Julia")))
	{
		printf("valid paramater : \"Mandelbrot\" or \"Julia\", complex number\n");
		return 0;
	}
	if (ft_streq(argc[1], "Mandelbrot"))
		return 1;
	else if (ft_streq(argc[1], "Julia"))
		return 2;
	else
		return 3;
}

int main(int argv, char **argc)
{
	t_frac_data frac;

	frac.f_flag = set_frac_flag(argv, argc);
	if (!fract_ol_init(&frac, &frac.img, argc) || !frac.f_flag)
		return 0;
	draw_frac(&frac);
	mlx_put_image_to_window(frac.mlx, frac.win, frac.img.img_ptr, 0, 0);
	mlx_key_hook(frac.win, press_esc, 0);
	mlx_hook(frac.win, 4, 1, press_wheel, &frac);
	mlx_loop(frac.mlx);
}

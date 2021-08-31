/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:25:54 by oseungcheol       #+#    #+#             */
/*   Updated: 2021/08/31 11:15:17 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_d_pair	get_julia_para(int flag, char **argc)
{
	t_d_pair	ret;

	ret.x = 0;
	ret.y = 0;
	if (flag != 2)
		return (ret);
	ret.x = ft_atod(argc[2]);
	ret.y = ft_atod(argc[3]);
	return (ret);
}

int	fract_ol_init(t_frac_data *frac, t_img *img, char **argc)
{
	frac->mlx = mlx_init();
	frac->win = mlx_new_window(frac->mlx, WIDTH, LENGTH, "fract_ol");
	img->img_ptr = mlx_new_image(frac->mlx, WIDTH, LENGTH);
	img->data_ptr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
	if (frac->mlx == 0 || frac->win == 0 || img->img_ptr == 0 || \
	img->data_ptr == 0)
	{
		write(2, "mlx error\n", 11);
		return (0);
	}
	frac->center.x = 0;
	frac->center.y = 0;
	frac->pixel = ft_min(WIDTH, LENGTH) / 4;
	frac->w_l.x = WIDTH / frac->pixel;
	frac->w_l.y = LENGTH / frac->pixel;
	frac->julia_comp = get_julia_para(frac->f_flag, argc);
	return (1);
}

int	set_frac_flag(int argv, char **argc)
{
	if ((argv != 2 && argv != 4) || \
	(argv == 2 && !ft_streq(argc[1], "Mandelbrot")) || \
	(argv == 4 && !ft_streq(argc[1], "Julia")))
	{
		printf("valid paramater : \"Mandelbrot\"");
		printf("or \"Julia\", complex number\n");
		printf("recommend : Julia -0.7 -0.27015\n");
		return (0);
	}
	if (ft_streq(argc[1], "Mandelbrot"))
		return (1);
	else if (ft_streq(argc[1], "Julia"))
		return (2);
	else
		return (3);
}

int	main(int argv, char **argc)
{
	t_frac_data	frac;

	frac.f_flag = set_frac_flag(argv, argc);
	if (!fract_ol_init(&frac, &frac.img, argc) || !frac.f_flag)
		return (0);
	draw_frac(&frac);
	mlx_put_image_to_window(frac.mlx, frac.win, frac.img.img_ptr, 0, 0);
	mlx_key_hook(frac.win, press_esc, 0);
	mlx_hook(frac.win, 4, 1, press_wheel, &frac);
	mlx_loop(frac.mlx);
}

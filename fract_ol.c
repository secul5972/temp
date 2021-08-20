/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:25:54 by oseungcheol       #+#    #+#             */
/*   Updated: 2021/08/20 14:24:14 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int fract_ol_init(void **mlx, void **win, t_img *img)
{
    *mlx = mlx_init();
    *win = mlx_new_window(*mlx, WIDTH, LENGTH, "fract_ol");
    img->img_ptr = mlx_new_image(*mlx, WIDTH, LENGTH);
    img->data_ptr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, &img->line_length, &img->endian);
	if (*mlx ==0 || *win == 0 || img->img_ptr == 0 || img->data_ptr == 0)
	{
		printf("mlx error\n");
		return 0;
	}
    return 1;
}

int Mandelbrot(t_comp_num p)
{
    int i;
    t_comp_num z;
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

int Julia(t_comp_num p, t_comp_num j_p)
{
    int i;
    t_comp_num z;
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

void draw_frac(t_img *img, int flag, t_comp_num j_p)
{
    int i;
    int j;
	int l;
    t_comp_num p; 

    i = 0;
    while (i < WIDTH)
    {
        j = 0;
        while (j < LENGTH)
        {
            p.x = ((double)i - (double)WIDTH / 2) * 4 / ft_min(WIDTH, LENGTH);
            p.y = ((double)j - (double)LENGTH / 2) * 4 / ft_min(WIDTH, LENGTH);
            if (flag == 1)
            {
                l = Mandelbrot(p); 
				if (l != LOOP_LIMIT)
                    my_mlx_pixel_put(img, i, j, (255 - l / 10) * 0x10000 + 10 * l * 0x100 + 20 * (l / 20));
            
            }
            else if (flag == 2)
			{
				l = Julia(p, j_p);
                if (l != LOOP_LIMIT)
                    my_mlx_pixel_put(img, i, j, 20 * (l / 16) * 0x10000 + 16 * l * 0x100 + (255 - l / 16));
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

int set_frac_flag(int argv, char **argc)
{
    if ((argv != 2 && argv != 4) || (argv == 2 && !ft_streq(argc[1], "Mandelbrot"))
    || (argv == 4 && !ft_streq(argc[1], "Julia")))
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

t_comp_num get_julia_para(int flag, char **argc)
{
	t_comp_num ret;

	ret.x = 0;
	ret.y = 0;
	if (flag != 2)
		return ret;
	ret.x = ft_atod(argc[2]);
	ret.y = ft_atod(argc[3]);	
	return ret;
}

int main(int argv, char **argc)
{
    void *mlx;
    void *win;
    t_img img;
    int flag;

	flag = set_frac_flag(argv, argc);
    if (!fract_ol_init(&mlx, &win, &img) || !flag)
        return 0;
    draw_frac(&img, flag, get_julia_para(flag, argc));
    mlx_put_image_to_window(mlx, win, img.img_ptr, 0, 0);
    mlx_key_hook(win, press_esc, 0);
    mlx_loop(mlx);
}

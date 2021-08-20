/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:25:54 by oseungcheol       #+#    #+#             */
/*   Updated: 2021/08/20 11:43:38 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int fract_ol_init(void **mlx, void **win, t_img *img)
{
    *mlx = mlx_init();
    if (mlx == 0)
        return 0;
    *win = mlx_new_window(*mlx, WIDTH, LENGTH, "fract_ol");
    if (*win == 0)
        return 0;
    img->img_ptr = mlx_new_image(*mlx, WIDTH, LENGTH);
    if (img->img_ptr == 0)
        return 0;
    img->data_ptr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, &img->line_length, &img->endian);
    if (img->data_ptr == 0)
        return 0;
    return 1;
}

void Mandelbrot(t_img *img, t_comp_num p, int x, int y)
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
    if (i == LOOP_LIMIT)
        my_mlx_pixel_put(img, x, y, 0x000000);
    else
        my_mlx_pixel_put(img, x, y, (255 - i / 10) * 0x10000 + 10 * i * 0x100 + 20 * (i/20));
}

void Julia(t_img *img, t_comp_num p, int x, int y)
{
int i;
    t_comp_num z;
    double t;
    
    i = 0;
    z.x = p.x;
    z.y = p.y;
    while (z.x * z.x + z.y * z.y <= 4 && i < LOOP_LIMIT)
    {
        t = z.x * z.x - z.y * z.y + -0.7;
        z.y = 2 * z.x * z.y + 0.27015;
        z.x = t;
        i++;
    }
    if (i == LOOP_LIMIT)
        my_mlx_pixel_put(img, x, y, 0x000000);
    else
        my_mlx_pixel_put(img, x, y, 0x123456 + 0x080808 * i);
}

void draw_frac(t_img *img, int flag)
{
    int i;
    int j;
    t_comp_num p; 

    i = 0;
    while (i < WIDTH)
    {
        j = 0;
        while (j < LENGTH)
        {
            p.x = ((double)i - (double)WIDTH / 2) * 4 / ft_min(WIDTH, LENGTH);
            p.y = ((double)j - (double)LENGTH / 2) * 4 / ft_min(WIDTH, LENGTH);
            if (flag == 0)
                Mandelbrot(img, p, i, j);
            else if(flag == 1)
                Julia(img, p, i, j);
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

int main(int argv, char **argc)
{
    void *mlx;
    void *win;
    t_img img;
    int flag;

    if (argv != 2 || (!ft_streq(argc[1], "Mandelbrot") && !ft_streq(argc[1], "Julia")))
    {
        printf("valid paramater : Mandelbrot, Julia\n");
        return 0;
    }    
    if (!fract_ol_init(&mlx, &win, &img))
    {
        printf("ERROR\n");
        return 0; 
    }
    if (ft_streq(argc[1], "Mandelbrot"))
        flag = 0;
    else if (ft_streq(argc[1], "Julia"))
        flag = 1;
    draw_frac(&img, flag);
    mlx_put_image_to_window(mlx, win, img.img_ptr, 0, 0);
    mlx_key_hook(win, press_esc, 0);
    mlx_loop(mlx);
}

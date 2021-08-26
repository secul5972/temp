/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:24:19 by oseungcheol       #+#    #+#             */
/*   Updated: 2021/08/26 14:16:53 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 800
# define LENGTH 800
# define LOOP_LIMIT 255
# define ZOOM_RATE 1.5

typedef struct s_d_pair
{
    double x;
    double y;
} t_d_pair;

typedef struct s_img
{
	void *img_ptr;
	char *data_ptr;
	int bits_per_pixel;
	int line_length;
	int endian;
}	t_img;

typedef struct s_frac_data
{
	int f_flag;
	int wheel_cnt;
	double pixel;
	void *win;
	void *mlx;
	t_img img;
	t_d_pair center;
	t_d_pair w_l;
	t_d_pair julia_comp;
}	t_frac_data;

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int	ft_streq(const char *s1, const char *s2);
int ft_min(int a, int b);
long ft_atol(const char *str);
int ft_strlen(const char *str);
double ft_atod(const char *str);

#endif

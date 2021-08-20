/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:24:19 by oseungcheol       #+#    #+#             */
/*   Updated: 2021/08/20 11:29:11 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 1200
# define LENGTH 800
# define LOOP_LIMIT 255

typedef struct s_img
{
	void *img_ptr;
	char *data_ptr;
	int bits_per_pixel;
	int line_length;
	int endian;
}	t_img;

typedef struct s_comp_num
{
    double x;
    double y;
} t_comp_num;

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int	ft_streq(const char *s1, const char *s2);
int ft_min(int a, int b);

#endif

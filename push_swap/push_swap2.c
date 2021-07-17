/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 14:50:04 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/17 17:34:54 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_mal(t_lpair *head, int argc, t_list **ins)
{
	double	log3;
	int		digit;
	int		size;

	log3 = 0.477121255;
	digit = 0;
	size = argc - 1;
	while (size)
	{
		size /= 10;
		digit++;
	}
	*ins = ft_make_list(((int)((double)digit / log3) + 1) * 5 / 3 * (argc - 1));
	head->a = ft_lalloc(0, 0, 0);
	head->a->end = head->a;
	head->b = ft_lalloc(0, 0, 0);
}

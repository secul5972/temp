/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 03:15:22 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/18 03:35:24 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ft_sort_stack(t_lpair *head, t_list *ins)
{
	int	ret;

	ret = 0;
	while (ret == 0)
		ret = ternary_div(head, 1, ins);
	if (ret == -1)
	{
		all_free(head, ins);
		return (0);
	}
	while (head->b->size)
	{
		if (ret == -1)
		{
			all_free(head, ins);
			return (0);
		}
		if (head->a->next->size)
			ret = ternary_div(head, 3, ins);
		else
			ret = ternary_div(head, 2, ins);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 14:50:04 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/18 14:28:57 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	input_pre(t_list *head, char **argv, int i)
{
	long	val;
	char	*temp;

	while (argv[++i])
	{
		temp = argv[i];
		while (*temp)
		{
			val = ft_atoi(&temp);
			if (val > 2147483647 || val < -2147483648)
				return (2);
			head->end->next = ft_lalloc(head, head->end, val);
			if (!head->end)
				return (3);
		}
	}
	if (argv[1] != 0)
		head->next->size = head->size;
	return (1);
}

int	init_mal(t_lpair *head, char **argv, t_list **ins)
{
	double	log3;
	int		size;
	int		flag;

	head->a = ft_lalloc(0, 0, 0);
	head->a->end = head->a;
	head->b = ft_lalloc(0, 0, 0);
	if (!(head->a) || !(head->b))
		return (3);
	flag = input_pre(head->a, argv, 0);
	if (flag == 2 || flag == 3)
		return (flag);
	log3 = 0.477121255;
	flag = 0;
	size = head->a->size - 1;
	while (size)
	{
		size /= 10;
		flag++;
	}
	*ins = ft_make_list(((int)((double)flag / log3) + 1) * 2 \
	 * (head->a->size - 1));
	if (!(*ins))
		return (3);
	return (1);
}

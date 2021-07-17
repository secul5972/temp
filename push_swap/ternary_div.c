/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ternary_div.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 00:27:03 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/17 12:41:11 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*small_div(t_lpair *head, int s_flag, t_ipair *cnt, t_list *ins)
{
	if (s_flag == 1 || s_flag == 3)
	{
		p_ins(head, 2, ins);
		return (head->a->next);
	}
	else
	{
		r_ins(head, 2, 0, ins);
		cnt->second++;
		return (head->b->next);
	}
}

static t_list	*middle_div(t_lpair *head, int s_flag, t_ipair *cnt, t_list *ins)
{
	if (s_flag == 1 || s_flag == 3)
	{
		p_ins(head, 2, ins);
		r_ins(head, 2, 0, ins);
		cnt->second++;
		return (head->a->next);
	}
	else
	{
		p_ins(head, 1, ins);
		r_ins(head, 1, 0, ins);
		cnt->first++;
		return (head->b->next);
	}
}

static t_list	*big_div(t_lpair *head, int s_flag, t_ipair *cnt, t_list *ins)
{
	if (s_flag == 1 || s_flag == 3)
	{
		r_ins(head, 1, 0, ins);
		cnt->first++;
		return (head->a->next);
	}
	else
	{
		p_ins(head, 1, ins);
		return (head->b->next);
	}
}

static t_list	*init_div(t_lpair *head, int s_flag, \
t_ipair *pivot, t_ipair *cnt)
{
	t_list	*curr;

	if (s_flag == 1 || s_flag == 3)
		curr = head->a;
	else
		curr = head->b;
	if (curr->next->size > 3)
		ft_sort(curr, pivot, curr->next->size);
	cnt->first = 0;
	cnt->second = 0;
	return (curr->next);
}

int	ternary_div(t_lpair *head, int s_flag, t_list *ins)
{
	int		i;
	int		size;
	t_ipair	pivot;
	t_ipair	cnt;
	t_list	*next;

	next = init_div(head, s_flag, &pivot, &cnt);
	size = next->size;
	next->size = 0;
	if (size <= 3)
		return (les_than_four(head, s_flag, size, ins));
	i = size;
	while (i--)
	{
		if (next->val < pivot.first)
			next = small_div(head, s_flag, &cnt, ins);
		else if (pivot.first <= next->val && next->val < pivot.second)
			next = middle_div(head, s_flag, &cnt, ins);
		else
			next = big_div(head, s_flag, &cnt, ins);
	}
	size_con1(head, s_flag, size, &cnt);
	size_con2(head, s_flag, ins, cnt);
	return (1);
}

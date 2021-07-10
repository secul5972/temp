/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ternary_div.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 00:27:03 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/10 14:27:04 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	small_div(t_lpair *head, int s_flag, t_ipair *cnt)
{
	if (s_flag == 0 || s_flag == 2)
		p_ins(head, 2);
	else if(s_flag == 1)
	{
		r_ins(head, 2, 0);
		cnt->second++;
	}
}

static void	middle_div(t_lpair *head, int s_flag, t_ipair *cnt)
{
	if (s_flag == 0 || s_flag == 2)
	{
		p_ins(head, 2);
		r_ins(head, 2, 0);
		cnt->second++;
	}
	else if (s_flag == 1)
	{
		p_ins(head, 1);
		r_ins(head, 1, 0);
		cnt->first++;
	}

}

static void	big_div(t_lpair *head, int s_flag, t_ipair *cnt)
{
	if (s_flag == 0 || s_flag == 2)
	{
		r_ins(head, 1, 0);
		cnt->first++;
	}
	else if(s_flag == 1)
		p_ins(head, 1);
}

static void	init_div(t_list *head, t_ipair *pivot, t_ipair *cnt)
{
	int		f_idx;
	int		s_idx;
	int		i;
	t_list	*curr;

	f_idx  = head->size/3;
	s_idx = f_idx * 2;
	i = 0;
	curr = head->next;
	while(i < head->size)
	{
		if (i == f_idx)
			pivot->first = curr->val;
		if (i == s_idx)
		{
			pivot->second = curr->val;
			break;
		}
		curr = curr->next;
		i++;
	}
	cnt->first = 0;
	cnt->second = 0;
	if (pivot->first > pivot->second)
		i_swap(&pivot->first, &pivot->second);
}

int	ternary_div(t_lpair *head, int s_flag)
{
	int		i;
	int		j;
	int		size;
	int		val;
	t_ipair	pivot;
	t_ipair	cnt;
	t_list	*next;

	if (s_flag == 0 || s_flag == 2)
	{
		init_div(head->a, &pivot, &cnt);
		size = head->a->next->size;
		head->a->next->size = 0;
		next = head->a->next;
	}
	else if (s_flag == 1)
	{
		init_div(head->b, &pivot, &cnt);
		size = head->b->next->size;
		head->b->next->size = 0;
		next = head->b->next;
	}
	if (size < 3)
		return (les_than_thr(head, s_flag, size));
	val = next->val;
	next = next->next;
	i = size;
	while (i--)
	{
		if (val < pivot.first)
			small_div(head, s_flag, &cnt);
		else if (pivot.first <= val && val < pivot.second)
			middle_div(head, s_flag, &cnt);
		else
			big_div(head, s_flag, &cnt);
		val = next->val;
		next = next->next;
	}
	if (s_flag == 0 || s_flag == 2)
		head->b->next->size = size - cnt.first - cnt.second;
	if (s_flag == 0)
	{
		head->a->next->size = cnt.first;
		cnt.first = 0;
	}
	if (s_flag == 1)
		head->a->next->size = size - cnt.first - cnt.second;
	i = 0;
	j = 0;
	while (i < cnt.first && j < cnt.second)
	{
		r_ins(head, 2, 1);
		i++;
		j++;
	}
	while (i++ < cnt.first)
		r_ins(head, 1, 1);
	while (j++ < cnt.second)
		r_ins(head, 2, 1);
	head->b->next->size = cnt.second;
	if (s_flag == 1 || s_flag == 2)
		head->a->next->size = cnt.first;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ternary_div.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 00:27:03 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/09 11:21:11 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	small_div(t_lpair *head, int s_flag, t_ipair *cnt)
{
	if (s_flag == 1 || s_flag == 3)
		p_ins(head, 2);
	else if(s_flag == 2)
	{
		r_ins(head, 2, 0);
		cnt->first++;
	}
}

static void	middle_div(t_lpair *head, int s_flag, t_ipair *cnt)
{
	if (s_flag == 1 || s_flag == 3)
	{
		p_ins(head, 2);
		r_ins(head, 2, 0);
		cnt->first++;
	}
	else if (s_flag == 2)
	{
		p_ins(head, 1);
		r_ins(head, 1, 0);
		cnt->second++;
	}

}

static void	big_div(t_lpair *head, int s_flag, t_ipair *cnt)
{
	if (s_flag == 1 || s_flag == 3)
	{
		r_ins(head, 1, 0);
		if (s_flag == 3)
			cnt->first++;
	}
	else if(s_flag == 2)
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
}

void	ternary_div(t_lpair *head, int s_flag)
{
	int		i;
	t_ipair	pivot;
	t_ipair	cnt;
	t_list	*curr;

	init_div(head->a, &pivot, &cnt);
	if (s_flag == 1 || s_flag == 3)
	{
		i = head->a->size;
		curr = head->a->next;
	}
	else if (s_flag == 2)
	{
		i = head->b->size;
		curr = head->b->next;
	}
	while (i--)
	{
		if (curr->val < pivot.first)
			small_div(head, s_flag, &cnt);
		else if (pivot.first <= curr->val && curr->val < pivot.second)
			middle_div(head, s_flag, &cnt);
		else
			big_div(head, s_flag, &cnt);
	}
	head->a->size = cnt.first;
	head->b->size = cnt.second;
	while (cnt.first-- && cnt.second--)
		r_ins(head, 3, 1);
	while (cnt.first--)
		r_ins(head, 1, 1);
	while (cnt.second--)
		r_ins(head, 2, 1);
}

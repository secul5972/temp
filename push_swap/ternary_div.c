/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ternary_div.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 00:27:03 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/15 00:11:45 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void print_func(t_lpair *head);

static void	small_div(t_lpair *head, int s_flag, t_ipair *cnt, t_list **ins)
{
	if (s_flag == 1 || s_flag == 3)
		p_ins(head, 2, ins);
	else if(s_flag == 2)
	{
		r_ins(head, 2, 0, ins);
		cnt->second++;
	}
}

static void	middle_div(t_lpair *head, int s_flag, t_ipair *cnt, t_list **ins)
{
	if (s_flag == 1 || s_flag == 3)
	{
		p_ins(head, 2, ins);
		r_ins(head, 2, 0, ins);
		cnt->second++;
	}
	else if (s_flag == 2)
	{
		p_ins(head, 1, ins);
		r_ins(head, 1, 0, ins);
		cnt->first++;
	}

}

static void	big_div(t_lpair *head, int s_flag, t_ipair *cnt, t_list **ins)
{
	if (s_flag == 1 || s_flag == 3)
	{
		r_ins(head, 1, 0, ins);
		cnt->first++;
	}
	else if(s_flag == 2)
		p_ins(head, 1, ins);
}

static int	init_div(t_list *head, t_ipair *pivot, t_ipair *cnt)
{
	int size;

	size = head->next->size;
	head->next->size = 0;
	if (size > 3)
		ft_sort(head, pivot, size);
	cnt->first = 0;
	cnt->second = 0;
	return (size);
}

int	ternary_div(t_lpair *head, int s_flag, t_list **ins)
{
	int		i;
	int		j;
	int		size;
	int		val;
	t_ipair	pivot;
	t_ipair	cnt;
	t_list	*next;

	if (s_flag == 1 || s_flag == 3)
	{
		size = init_div(head->a, &pivot, &cnt);
		next = head->a->next;
	}
	else
	{
		size = init_div(head->b, &pivot, &cnt);
		next = head->b->next;
	}
	if (size <= 3)
		return (les_than_four(head, s_flag, size, ins));

	i = size;
	while (i--)
	{
		val = next->val;
		next = next->next;
		if (val < pivot.first)
			small_div(head, s_flag, &cnt, ins);
		else if (pivot.first <= val && val < pivot.second)
			middle_div(head, s_flag, &cnt, ins);
		else
			big_div(head, s_flag, &cnt, ins);
	}
	if ((s_flag == 1 || s_flag == 3) && (size - cnt.first - cnt.second))
		head->b->next->size = size - cnt.first - cnt.second;
	if (s_flag == 1 && cnt.first)
	{
		head->a->next->size = cnt.first;
		cnt.first = 0;
	}
	if (s_flag == 2 && (size - cnt.first - cnt.second))
		head->a->next->size = size - cnt.first - cnt.second;
	i = 0;
	j = 0;
	while (i < cnt.first && j < cnt.second)
	{
		r_ins(head, 3, 1, ins);
		i++;
		j++;
	}
	while (i++ < cnt.first)
		r_ins(head, 1, 1, ins);
	i = 0;
	while (j++ < cnt.second)
		r_ins(head, 2, 1, ins);
	if (cnt.second)
		head->b->next->size = cnt.second;
	while((s_flag == 2) && (i++ < cnt.first))
		if (s_flag == 2)
			p_ins(head, 2, ins);
	if (s_flag == 2 && cnt.first)
		head->b->next->size = cnt.first;
	if (s_flag == 3 && cnt.first)
		head->a->next->size = cnt.first;
	return (1);
}

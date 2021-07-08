/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 10:08:17 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/08 10:49:15 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_ins(t_list *a, t_list *b, int head_flag)
{
	t_list *curr;
	t_list *first_node;

	if (head_flag & 1)
	{
		curr = a;
		first_node = curr->next;
		first_node->next = first_node->next->next;
		first_node->next->next->pre = first_node;
		curr->next = first_node->next;
		first_node->next->pre = curr;
		first_node->pre = curr->next;
	}
	if (head_flag & 2)
	{
		curr = b;
		first_node = curr->next;
		first_node->next = first_node->next->next;
		first_node->next->next->pre = first_node;
		curr->next = first_node->next;
		first_node->next->pre = curr;
		first_node->pre = curr->next;
	}
}

void	p_ins(t_list *a, t_list*b, int head_flag)
{
	t_list *push_head;
	t_list *pop_head;
	
	push_head = a;
	pop_head = b;
	if (head_flag == 2)
		list_swap(&a, &b);
	ft_push(push_head, ft_pop(push_head, 0), 0);
}

void	r_ins(t_list *a, t_list *b, int head_flag, int rev_flag)
{
	if (rev_flag == 0)
	{
		if (head_flag & 1)
			ft_push(a, ft_pop(a, 0), 1);
		if (head_flag & 2)
			ft_push(b, ft_pop(b, 0), 1);
	}
	else if (rev_flag == 1)
	{
		if (head_flag & 1)
			ft_push(a, ft_pop(a, 1), 0);
		if (head_flag & 2)
			ft_push(b, ft_pop(b, 1), 0);
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 10:08:17 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/11 13:43:36 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_ins(t_lpair *head, int h_flag, t_list **ins)
{
	t_list *f_node;
	t_list *s_node;

	if (h_flag & 1)
	{
		f_node = ft_pop(head->a, 0);
		s_node = ft_pop(head->a, 0);
		ft_push(head->a, f_node, 0);
		ft_push(head->a, s_node, 0);
		(*ins)->val += 1;
	}
	if (h_flag & 2)
	{
		f_node = ft_pop(head->b, 0);
		s_node = ft_pop(head->b, 0);
		ft_push(head->b, f_node, 0);
		ft_push(head->b, s_node, 0);
		(*ins)->val += 2;
	}
	ft_make_list(&((*ins)->next), 0, 0);
	(*ins) = (*ins)->next;
}

void	p_ins(t_lpair *head, int h_flag, t_list **ins)
{
	t_list *push_head;
	t_list *pop_head;
	
	push_head = head->a;
	pop_head = head->b;
	if (h_flag == 1)
		(*ins)->val = 4;
	if (h_flag == 2)
	{
		l_swap(&push_head, &pop_head);
		(*ins)->val = 5;
	}
	ft_push(push_head, ft_pop(pop_head, 0), 0);
	ft_make_list(&((*ins)->next), 0, 0);
	(*ins)->next->pre = (*ins);
	(*ins) = (*ins)->next;
}

void	r_ins(t_lpair *head, int h_flag, int rev_flag, t_list **ins)
{
	if (rev_flag == 0)
	{
		if (h_flag & 1)
		{
			ft_push(head->a, ft_pop(head->a, 0), 1);
			(*ins)->val = 6;
		}
		if (h_flag & 2)
		{
			ft_push(head->b, ft_pop(head->b, 0), 1);
			(*ins)->val = 7;
			if (h_flag == 3)
				(*ins)->val = 8;			
		}
	}
	else if (rev_flag == 1)
	{
		if (h_flag & 1)
		{
			ft_push(head->a, ft_pop(head->a, 1), 0);
			(*ins)->val = 9;
		}
		if (h_flag & 2)
		{
			ft_push(head->b, ft_pop(head->b, 1), 0);
			(*ins)->val = 10;
			if (h_flag == 3)
				(*ins)->val = 11;	
		}
	}
	ft_make_list(&((*ins)->next), 0, 0);
	(*ins) = (*ins)->next;
}


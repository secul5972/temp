/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 10:08:17 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/15 23:46:04 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_ins(t_lpair *head, int h_flag, t_list *ins)
{
	t_list *f_node;
	t_list *s_node;

	if (h_flag & 1)
	{
		f_node = ft_pop(head->a, 0);
		s_node = ft_pop(head->a, 0);
		ft_push(head->a, f_node, 0);
		ft_push(head->a, s_node, 0);
		ins->end->val += 1;
	}
	if (h_flag & 2)
	{
		f_node = ft_pop(head->b, 0);
		s_node = ft_pop(head->b, 0);
		ft_push(head->b, f_node, 0);
		ft_push(head->b, s_node, 0);
		ins->end->val += 2;
	}
	ins->end->next = ft_lalloc(ins, ins->end, 0);
}

void	p_ins(t_lpair *head, int h_flag, t_list *ins)
{
	t_list *push_head;
	t_list *pop_head;
	
	if (h_flag == 1 && head->b->size == 0)
		return ;
	if (h_flag == 2 && head->a->size == 0)
		return ;
	push_head = head->a;
	pop_head = head->b;
	if (h_flag == 1)
		ins->end->val = 4;
	if (h_flag == 2)
	{
		l_swap(&push_head, &pop_head);
		ins->end->val = 5;
	}
	ft_push(push_head, ft_pop(pop_head, 0), 0);
	ins->end->next = ft_lalloc(ins, ins->end, 0);
}

void	r_ins(t_lpair *head, int h_flag, int rev_flag, t_list *ins)
{
	if (h_flag == 1 && head->a->size == 1)
		return ;
	if (h_flag == 2 && head->b->size == 1)
		return ;
	if (rev_flag == 0)
	{
		if (h_flag & 1)
		{
			ft_push(head->a, ft_pop(head->a, 0), 1);
			ins->end->val = 6;
		}
		if (h_flag & 2)
		{
			ft_push(head->b, ft_pop(head->b, 0), 1);
			ins->end->val = 7;
			if (h_flag == 3)
				ins->end->val = 8;			
		}
	}
	else if (rev_flag == 1)
	{
		if (h_flag & 1)
		{
			ft_push(head->a, ft_pop(head->a, 1), 0);
			ins->end->val = 9;
		}
		if (h_flag & 2)
		{
			ft_push(head->b, ft_pop(head->b, 1), 0);
			ins->end->val = 10;
			if (h_flag == 3)
				ins->end->val = 11;	
		}
	}
	ins->end->next = ft_lalloc(ins, ins->end, 0);
}


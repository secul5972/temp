/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 10:08:17 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/11 12:06:06 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_ins(t_lpair *head, int h_flag)
{
	t_list *f_node;
	t_list *s_node;

	if (h_flag & 1)
	{
		f_node = ft_pop(head->a, 0);
		s_node = ft_pop(head->a, 0);
		ft_push(head->a, f_node, 0);
		ft_push(head->a, s_node, 0);
	}
	if (h_flag & 2)
	{
		f_node = ft_pop(head->b, 0);
		s_node = ft_pop(head->b, 0);
		ft_push(head->b, f_node, 0);
		ft_push(head->b, s_node, 0);
	}
}

void	p_ins(t_lpair *head, int h_flag)
{
	t_list *push_head;
	t_list *pop_head;
	
	push_head = head->a;
	pop_head = head->b;
	if (h_flag == 2)
		l_swap(&push_head, &pop_head);
	ft_push(push_head, ft_pop(pop_head, 0), 0);
}

void	r_ins(t_lpair *head, int h_flag, int rev_flag)
{
	if (rev_flag == 0)
	{
		if (h_flag & 1)
			ft_push(head->a, ft_pop(head->a, 0), 1);
		if (h_flag & 2)
			ft_push(head->b, ft_pop(head->b, 0), 1);
	}
	else if (rev_flag == 1)
	{
		if (h_flag & 1)
			ft_push(head->a, ft_pop(head->a, 1), 0);
		if (h_flag & 2)
			ft_push(head->b, ft_pop(head->b, 1), 0);
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ternary_div2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 14:11:57 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/12 12:47:31 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	size_eq_thr_a(t_lpair *head, int s_flag, t_list **ins)
{
	int		m_val;
	t_list	*curr;

	curr = head->a;
	m_val = ft_max(curr->next->next->next->val\
	, ft_max(curr->next->val, curr->next->next->val));
	if (m_val == curr->next->val && s_flag == 1)
		r_ins(head, 1, 0, ins);
	if (m_val == curr->next->next->val && s_flag ==1)
		r_ins(head, 1, 1, ins);
	if (curr->next->next->next->val == m_val)
		les_than_four(head, s_flag, 2, ins);
	else
	{
		if (m_val == curr->next->val)
			s_ins(head, 1, ins);
		p_ins(head, 2, ins);
		s_ins(head, 1, ins);
		p_ins(head, 1, ins);
		les_than_four(head, s_flag, 2, ins);
	}
}

static void	size_eq_thr_b(t_lpair *head, t_list **ins)
{
	int		m_val;
	t_list	*curr;

	curr = head->b;
	m_val = ft_max(curr->next->next->next->val\
	, ft_max(curr->next->val, curr->next->next->val));
	if (m_val == curr->next->next->next->val)
	{
		r_ins(head, 2, 0, ins);
		les_than_four(head, 2, 2, ins);
		r_ins(head, 2, 1, ins);
		p_ins(head, 1, ins);
		les_than_four(head, 1, 2, ins);
	}
	else
	{
		les_than_four(head, 2, 2, ins);
		p_ins(head, 1, ins);
		les_than_four(head, 1, 2, ins);
	}
}

int			les_than_four(t_lpair *head, int s_flag, int size, t_list **ins)
{
	if (size == 1)
	{	
		if (s_flag == 2)
			p_ins(head, 1, ins);
	}
	else if (size == 2 && (s_flag == 1 || s_flag == 3))
	{	
		if (head->a->next->val > head->a->next->next->val)
			s_ins(head, 1, ins);
	}
	else if (size == 2 && s_flag == 2)
	{
		p_ins(head, 1, ins);
		p_ins(head, 1, ins);
		if (head->a->next->val > head->a->next->next->val)
			s_ins(head, 1, ins);
	}
	else if (size == 3 && (s_flag == 1 || s_flag == 3))
		size_eq_thr_a(head, s_flag, ins);
	else if (size == 3 && s_flag == 2)
		size_eq_thr_b(head, ins);
	return (0);
}
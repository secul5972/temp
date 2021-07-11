/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ternary_div2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 14:11:57 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/11 14:44:40 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		les_than_thr(t_lpair *head, int s_flag, int size, t_list **ins)
{
	if (size == 1)
	{	if (s_flag == 2)
			p_ins(head, 1, ins);
	}
	else{
		if (s_flag == 1 || s_flag == 3)
		{
			if (head->a->next->val > head->a->next->next->val)
				s_ins(head, 1, ins);
		}
		else if (s_flag == 2)
		{
			p_ins(head, 1, ins);
			p_ins(head, 1, ins);
			if (head->a->next->val > head->a->next->next->val)
				s_ins(head, 1, ins);
		}
	}
	return (0);
}
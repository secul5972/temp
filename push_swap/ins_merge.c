/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_merge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 20:08:37 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/15 20:52:19 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ins_del(t_list **curr, int val)
{
	t_list *temp;
	t_list *next;
	
	temp = (*curr);
	next = (*curr)->next;
	if(val > 0)
	{
		(*curr)->val = val;
		(*curr)->next = next->next;
		next->next->pre = (*curr);
		(*curr) = (*curr)->pre;
		free(next);
	}
	else
	{
		(*curr)->pre->next = next->next;
		next->next->pre = (*curr)->pre;
		(*curr) = (*curr)->pre->pre;
		free(temp);
		free(next);
	}
}

void		ins_merge(t_list *ins)
{
	t_list *curr;
	t_list *next;

	if (ins == 0 || ins->next == 0 || ins->next->next == 0)
		return ;
	curr = ins->next;
	next = curr->next;
	while (next)
	{
		if ((curr->val == 1 && next->val == 2) || (curr->val == 2 && next->val == 1))
			ins_del(&curr, 3);
		else if ((curr->val == 6 && next->val == 7) || (curr->val == 7 && next->val == 6))
			ins_del(&curr, 8);
		else if ((curr->val == 9 && next->val == 10) || (curr->val == 10 && next->val == 9))
			ins_del(&curr, 11);
		else if ((curr->val == 4 && next->val == 5) || (curr->val == 5 && next->val == 4))
			ins_del(&curr, 0);
		else if ((curr->val == 6 && next->val == 9) || (curr->val == 9 && next->val == 6))
			ins_del(&curr, 0);
		else if ((curr->val == 7 && next->val == 10) || (curr->val == 10 && next->val == 7))
			ins_del(&curr, 0);
		else if ((curr->val == 8 && next->val == 11) || (curr->val == 11 && next->val == 8))
			ins_del(&curr, 0);
		curr = curr->next;
		next = curr->next;
	}

	if (ins->next == 0 || ins->next->next == 0 || ins->next->next->next == 0 || ins->next->next->next->next == 0)
		return ;
	curr = ins->next;
	next = curr->next;

	while(curr->next->next->next)
	{
		if(curr->val==7 && next->val==5 && next->next->val ==10 && next->next->next->val == 2)
		{
			curr->val=5;
			curr->next=next->next->next->next;
			free(next->next->next);
			free(next->next);
			free(next);
		}
		else
			curr = curr->next;
		next = curr->next;
	}
}
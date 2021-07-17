/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_merge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 20:08:37 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/17 12:56:49 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ins_del(t_list **c, int val)
{
	t_list	*temp;
	t_list	*next;

	temp = (*c);
	next = (*c)->next;
	if (val > 0)
	{
		(*c)->val = val;
		(*c)->next = next->next;
		next->next->pre = (*c);
		(*c) = (*c)->pre;
		free(next);
	}
	else
	{
		(*c)->pre->next = next->next;
		next->next->pre = (*c)->pre;
		(*c) = (*c)->pre->pre;
		free(temp);
		free(next);
	}
}

void	ins_merge2(t_list *c)
{
	t_list	*n;

	if (c == 0 || c->next == 0 || \
	c->next->next == 0 || c->next->next->next == 0)
		return ;
	n = c->next;
	while (c->next->next->next)
	{
		if (c->val == 7 && n->val == 5 && \
		n->next->val == 10 && n->next->next->val == 2)
		{
			c->val = 5;
			c->next = n->next->next->next;
			free(n->next->next);
			free(n->next);
			free(n);
		}
		else
			c = c->next;
		n = c->next;
	}
}

void	ins_merge(t_list *c)
{
	t_list	*n;

	if (c == 0 || c->next == 0)
		return ;
	n = c->next;
	while (n)
	{
		if ((c->val == 1 && n->val == 2) || (c->val == 2 && n->val == 1))
			ins_del(&c, 3);
		else if ((c->val == 6 && n->val == 7) || (c->val == 7 && n->val == 6))
			ins_del(&c, 8);
		else if ((c->val == 9 && n->val == 10) || (c->val == 10 && n->val == 9))
			ins_del(&c, 11);
		else if ((c->val == 4 && n->val == 5) || (c->val == 5 && n->val == 4))
			ins_del(&c, 0);
		else if ((c->val == 6 && n->val == 9) || (c->val == 9 && n->val == 6))
			ins_del(&c, 0);
		else if ((c->val == 7 && n->val == 10) || (c->val == 10 && n->val == 7))
			ins_del(&c, 0);
		else if ((c->val == 8 && n->val == 11) || (c->val == 11 && n->val == 8))
			ins_del(&c, 0);
		c = c->next;
		n = c->next;
	}
}

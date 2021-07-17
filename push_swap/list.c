/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:37:11 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/17 18:27:25 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lalloc(t_list *head, t_list *pre, const int val)
{
	t_list	*ret;

	ret = (t_list *)malloc(sizeof(t_list));
	ret->pre = pre;
	ret->next = 0;
	ret->end = 0;
	ret->val = val;
	ret->size = 0;
	if (head)
	{
		head->end = ret;
		head->size++;
	}
	return (ret);
}

t_list	*ft_make_list(int size)
{
	t_list	*head;
	t_list	*curr;

	head = ft_lalloc(0, 0, 0);
	curr = head;
	while (size--)
	{
		curr->next = ft_lalloc(0, curr, 0);
		if (!(curr->next))
		{
			curr = head;
			while (curr)
			{
				curr = head->next;
				free(head);
				head = curr;
			}
			return (0);
		}
		curr = curr->next;
	}
	head->end = head->next;
	return (head);
}

void	ft_push(t_list *head, t_list *pop_node, int e_flag)
{
	t_list	*end_node;

	if (e_flag)
	{
		pop_node->next = 0;
		if (head->end)
			end_node = head->end;
		else
			end_node = head;
		end_node->next = pop_node;
		pop_node->pre = end_node;
		head->end = pop_node;
		pop_node->next = 0;
	}
	else
	{
		pop_node->next = head->next;
		if (head->next)
			head->next->pre = pop_node;
		pop_node->pre = head;
		head->next = pop_node;
		if (!head->size)
			head->end = pop_node;
	}
	head->size++;
}

t_list	*ft_pop(t_list *head, int e_flag)
{
	t_list	*pop_node;

	if (e_flag)
	{
		pop_node = head->end;
		head->end = head->end->pre;
		head->end->next = 0;
	}
	else
	{
		pop_node = head->next;
		head->next = head->next->next;
		if (head->next)
			head->next->pre = head;
		else
			head->end = 0;
	}
	head->size--;
	return (pop_node);
}

void	all_free(t_lpair *head, t_list *ins)
{
	t_list	*curr;
	t_list	*next;

	curr = head->a;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	curr = head->b;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	curr = ins;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}

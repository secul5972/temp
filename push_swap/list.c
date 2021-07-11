/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:37:11 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/11 13:29:15 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_make_list(t_list **head, const int *val, const int size)
{
	t_list	*new_node;
	t_list	*curr;
	int		i;

	i = 0;
	*head = (t_list*)malloc(sizeof(t_list));
	curr = *head;
	while (i < size){
		new_node = (t_list*)malloc(sizeof(t_list));
		new_node->val = val[i++];
		new_node->pre = curr;
		new_node->next = 0;
		new_node->end = 0;
		new_node->size = 0;
		curr->next = new_node;
		curr = new_node;
	}
	(*head)->end = curr;
	(*head)->size = size;
	if (!size)
		(*head)->val = 0;
	if (size > 0)
		(*head)->next->size = size;
}

void	ft_push(t_list *head, t_list *pop_node, int e_flag)
{
	if (e_flag)
	{
	
		pop_node->next = 0;
		if (head->end)
		{
			head->end->next = pop_node;
			pop_node->pre = head->end;
		}
		else
		{
			head->next = pop_node;
			pop_node->pre = head;
		}
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
	t_list *pop_node;

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

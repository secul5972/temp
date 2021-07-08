/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:37:11 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/08 10:37:19 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_make_list(t_list **head, const int *val, const int size)
{
	t_list	*new_node;
	t_list	*curr;
	int		i;

	i = 0;
	*head = (t_list*)malloc(sizeof(t_list));
	curr = *head;
	while (i < size){
		new_node = (t_list*)malloc(sizeof(t_list));
		new_node->val = val[i];
		new_node->pre = curr;
		new_node->next = 0;
		new_node->end = 0;
		new_node->size = 0;
		curr->next = new_node;
		curr = new_node;
	}
	(*head)->end = curr;
	(*head)->size = size;
	return (new_node);
}

void	ft_push(t_list *head, t_list *pop_node, int end_flag)
{
	if (end_flag)
	{
		head->end->next = pop_node;
		pop_node->pre = head->end;
		head->end = pop_node;
	}
	else
	{
		head->next->pre = pop_node;
		pop_node->next = head->next;
		head->next = pop_node;
	}
	head->size++;
}

t_list	*ft_pop(t_list *head, int end_flag)
{
	t_list *pop_node;

	if (end_flag)
	{
		pop_node = head->end;
		head->end = head->end->pre;
	}
	else
	{
		pop_node = head->next;
		head->next = head->next->next;
	}
	pop_node->pre = 0;
	pop_node->next = 0;
	head->size--;
	return (pop_node);
}

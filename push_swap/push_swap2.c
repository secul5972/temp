/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 14:50:04 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/17 15:12:47 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*mal_ins(int size)
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

int	init_mal(t_lpair *head, int *num, int argc, t_list **ins)
{
	*ins = mal_ins(150000);
	head->a = ft_make_list(num, argc - 1);
	head->b = ft_lalloc(0, 0, 0);
	free(num);
	if (!(*ins) || !(head->a) || !(head->b))
		return (2);
	return (0);
}

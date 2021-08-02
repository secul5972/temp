/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:08:29 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/18 13:44:13 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_ins_con(t_list *curr)
{
	if (curr->val == 1)
		write(1, "sa\n", 3);
	if (curr->val == 2)
		write(1, "sb\n", 3);
	if (curr->val == 3)
		write(1, "ss\n", 3);
	if (curr->val == 4)
		write(1, "pa\n", 3);
	if (curr->val == 5)
		write(1, "pb\n", 3);
	if (curr->val == 6)
		write(1, "ra\n", 3);
	if (curr->val == 7)
		write(1, "rb\n", 3);
	if (curr->val == 8)
		write(1, "rr\n", 3);
	if (curr->val == 9)
		write(1, "rra\n", 4);
	if (curr->val == 10)
		write(1, "rrb\n", 4);
	if (curr->val == 11)
		write(1, "rrr\n", 4);
}

static void	print_ins(t_list *ins)
{
	t_list	*curr;

	curr = ins->next;
	while (curr && curr->val)
	{
		print_ins_con(curr);
		curr = curr->next;
	}
}

static int	init(t_lpair *head, int argc, char **argv, t_list **ins)
{
	t_list	*i;
	t_list	*j;
	int		flag;

	head->a = 0;
	head->b = 0;
	*ins = 0;
	if (argc == 1)
		return (1);
	flag = init_mal(head, argv, ins);
	i = head->a->next;
	while (flag < 2 && i)
	{
		j = i->next;
		while (j)
		{
			if (i->val == j->val)
				return (2);
			if (i->val > j->val)
				flag = 0;
			j = j->next;
		}
		i = i->next;
	}
	return (flag);
}

int	main(int argc, char **argv)
{
	t_lpair	head;
	t_list	*ins;
	int		ret;

	ret = init(&head, argc, argv, &ins);
	if (ret)
	{
		if (ret == 2)
			write(2, "Error\n", 6);
		if (ret == 3)
			write(2, "Memerror\n", 9);
		all_free(&head, ins);
		return (0);
	}
	ret = ft_sort_stack(&head, ins);
	if (!ret)
	{
		all_free(&head, ins);
		write(2, "Memerror\n", 9);
		return (0);
	}
	ins_merge(ins->next);
	ins_merge2(ins->next);
	print_ins(ins);
	all_free(&head, ins);
}

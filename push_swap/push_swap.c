/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:08:29 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/17 18:03:36 by seungcoh         ###   ########.fr       */
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
	while (curr)
	{
		print_ins_con(curr);
		curr = curr->next;
	}
}

static int	input_pre(t_list *head, int argc, char **argv)
{
	int		i;
	int		ret;
	int		flag;
	long	val;
	char	*temp;

	i = 0;
	ret = 0;
	if (argc == 1)
		return (2);
	while (argv[++i])
	{
		temp = argv[i];
		flag = 1;
		while (*temp){
			val = ft_atoi(&temp);
			if (val > 2147483647 || val < -2147483648)
			{
				if (flag)
					return (1);
				else
					continue;
			}
			head->end->next = ft_lalloc(head, head->end, val);
			head->size++;
			flag = 0;
		}
	}
	head->next->size = head->size;
	return (ret);
}

static int	init(t_lpair *head, int argc, char **argv, t_list **ins)
{
	t_list	*i;
	t_list	*j;
	int	flag;

	init_mal(head, argc, ins);
	if (!(*ins) || !(head->a) || !(head->b))
		return (2);
	flag = input_pre(head->a, argc, argv);
	i = head->a->next;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->val == j->val)
				return (1);
			if (i->val > j->val)
				flag = 0;
			j = j->next;
		}
		i = i->next;
	}
	if (flag)
		return (flag);
	return (0);
}

int	main(int argc, char **argv)
{
	t_lpair	head;
	t_list	*ins;
	int		ret;

	ret = init(&head, argc, argv, &ins);
	if (ret)
	{
		if (ret != 2)
			write(2, "Error\n", 6);
		all_free(&head, ins);
		return (0);
	}
	while (ternary_div(&head, 1, ins))
	{
	}
	while (head.b->size)
	{
		if (head.a->next->size)
			ternary_div(&head, 3, ins);
		else
			ternary_div(&head, 2, ins);
	}
	ins_merge(ins->next);
	ins_merge2(ins->next);
	print_ins(ins);
	all_free(&head, ins);
}

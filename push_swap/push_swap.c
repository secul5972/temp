/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:08:29 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/17 12:43:04 by seungcoh         ###   ########.fr       */
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

static int	*input_pre(int argc, char **argv, int *flag, int *idx)
{
	int		i;
	long	val;
	int		*ret;

	i = 0;
	*idx = -1;
	*flag = 2;
	if (argc > 1)
		ret = malloc(sizeof(int) * (argc - 1));
	else
		ret = 0;
	while (argv[++i])
	{
		val = ft_atoi(argv[i]);
		if (val > 2147483647 || val < -2147483648)
		{
			free(ret);
			*flag = 1;
			return (0);
		}
		ret[i - 1] = val;
	}
	return (ret);
}

static int	init(t_lpair *head, int argc, char **argv, t_list **ins)
{
	int	i;
	int	j;
	int	flag;
	int	*num;

	num = input_pre(argc, argv, &flag, &i);
	while (num && (++i < (argc - 1)))
	{
		j = i;
		while (++j < (argc - 1))
		{
			if (num[i] == num[j])
				return (1);
			if (num[i] > num[j])
				flag = 0;
		}
	}
	if (flag)
		return (flag);
	*ins = ft_lalloc(0, 0, 0);
	(*ins)->next = ft_lalloc(*ins, *ins, 0);
	head->a = ft_make_list(num, argc - 1);
	head->b = ft_lalloc(0, 0, 0);
	free(num);
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
		return (0);
	}
	while (ternary_div(&head, 1, ins))
	{
	}
	while (head.a->size != argc - 1)
	{
		if (head.a->next->size)
			ternary_div(&head, 3, ins);
		else
			ternary_div(&head, 2, ins);
	}
	ins_merge(ins);
	print_ins(ins);
	all_free(&head, ins);
}

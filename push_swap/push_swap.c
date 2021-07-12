/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:08:29 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/12 14:08:26 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_ins(t_list *ins)
{
	t_list *curr = ins->next;
	while(curr)
	{
		if (curr->val == 1)
			write(1,"sa\n", 3);
		if (curr->val == 2)
			write(1,"sb\n", 3);
		if (curr->val == 3)
			write(1,"ss\n", 3);
		if (curr->val == 4)
			write(1,"pa\n", 3);
		if (curr->val == 5)
			write(1,"pb\n", 3);
		if (curr->val == 6)
			write(1,"ra\n", 3);
		if (curr->val == 7)
			write(1,"rb\n", 3);
		if (curr->val == 8)
			write(1,"rr\n", 3);
		if (curr->val == 9)
			write(1,"rra\n", 4);
		if (curr->val == 10)
			write(1,"rrb\n", 4);
		if (curr->val == 11)
			write(1,"rrr\n", 4);
		curr = curr->next;
	}
}

int	*input_pre(int argc, char **argv)
{
	int		i;
	long	val;
	int		*ret;

	ret = 0;
	if (argc == 1)
		return (0);
	i = 1;
	ret = malloc(sizeof(int)*(argc - 1));
	if (!ret)
		return (0);
	while (argv[i])
	{
		val = ft_atoi(argv[i]);
		if (val>2147483647 || val<-2147483648)
		{
			free(ret);
			return (0);
		}
		ret[i - 1] = val;
		i++;
	}
	return (ret);
}

int main(int argc, char **argv)
{
	t_lpair head;
	t_list	*ins;
	t_list	*temp;
	int		*num;
	int		size;

	num = input_pre(argc, argv);
	if (!num)
	{
		write(2, "error\n", 6);
		return (0);
	}
	ins = (t_list*)malloc(sizeof(t_list));
	size = argc - 1;
	ft_make_list(&(head.a), num, size);
	ft_make_list(&(head.b), 0, 0);
	ft_make_list(&(ins->next), 0, 0);
	temp = ins->next;
	while (ternary_div(&head, 1, &temp));
	while (head.a->size != size)
	{
		if (head.a->next->size)
			ternary_div(&head, 3, &temp);
		else
			ternary_div(&head, 2, &temp);
	}
	print_ins(ins);
}

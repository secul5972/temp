/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:08:29 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/13 20:33:10 by seungcoh         ###   ########.fr       */
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

int	init(t_lpair *head, int *num, int argc, t_list **ins)
{
	int i;
	int j;
	int ret = 2;

	i = 0;
	if (!num)
		return (1);
	while (i < (argc - 1))
	{
		j = i + 1;
		while(j < (argc - 1))
		{
			if (num[i] == num[j])
				return (1);
			if (num[i] > num[j])
				ret = 0;
			j++;
		}
		i++;
	}
	if (ret)
		return (ret);
	*ins = (t_list*)malloc(sizeof(t_list));
	ft_make_list(&(head->a), num, argc - 1);
	ft_make_list(&(head->b), 0, 0);
	ft_make_list(&((*ins)->next), 0, 0);
	return (0);
}

void print_func(t_lpair *head)
{
	t_list *curr = head->a->next;
	while(curr){
		printf("%d\n",curr->val);
			curr = curr->next;
		}
	printf("a\n\n");
	curr = head->b->next;
	while(curr){
		printf("%d\n",curr->val);
		curr = curr->next;
	}
	printf("b\n\n");	
}

int main(int argc, char **argv)
{
	t_lpair head;
	t_list	*ins;
	t_list	*temp;
	int		*num;
	int		ret;

	if (argc == 1)
		return (0);
	num = input_pre(argc, argv);
	ret = init(&head, num, argc, &ins);
	if (ret)
	{
		if (ret != 2)
			write(2, "Error\n", 6);
		return (0);
	}
	temp = ins->next;
	while (ternary_div(&head, 1, &temp)){
		print_func(&head);
		print_ins(ins);
	}
	while (head.a->size != argc - 1)
	{
		if (head.a->next->size)
			ternary_div(&head, 3, &temp);
		else
			ternary_div(&head, 2, &temp);
		print_func(&head);
		print_ins(ins);
	}
	print_ins(ins);
}

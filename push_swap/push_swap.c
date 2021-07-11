/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:08:29 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/11 14:46:52 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


#include<stdio.h>
void print_func(t_lpair *head)
{
	t_list *curr = head->a->next;
	while(curr){
		printf("%d\n",curr->val);
			curr = curr->next;
		}
	printf("\n\n");
	curr = head->b->next;
	while(curr){
		printf("%d\n",curr->val);
		curr = curr->next;
	}
	printf("\n\n");	
}

void print_ins(t_list *ins)
{
	t_list *curr = ins->next;
	while(curr){
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
int main(int argc, char **argv)
{
	t_lpair head;
	t_list	*ins;
	t_list	*temp;
	int		i;

	int num[15] = {4,6,8,49,2,5,13,23,1,14,10,46,45,17,11};
	int num2[10] = {1,2,4,5,3,9,8,84,51,12};
	int num3[6] = {2, 1, 3, 6, 5, 8};
	int num4[1] = {5};
	/*
	if (argc == 1)
		write(1, "error\n", 6);
	*/
	int size = 15;
	ins = (t_list*)malloc(sizeof(t_list));
	ft_make_list(&(head.a), num, size);
	ft_make_list(&(head.b), 0, 0);
	ft_make_list(&(ins->next), 0, 0);
	temp = ins->next;
	while (ternary_div(&head, 1, &temp))
	{
		print_func(&head);
	}
	while (head.a->size != size)
	{
		print_func(&head);
		if (head.a->next->size)
			ternary_div(&head, 3, &temp);
		else
			ternary_div(&head, 2, &temp);
	}
	print_func(&head);
	print_ins(ins);
}

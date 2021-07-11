/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:08:29 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/11 12:46:53 by seungcoh         ###   ########.fr       */
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
int main(int argc, char **argv)
{
	t_lpair head;
	int i;

	int num[15] = {4,6,8,49,2,5,13,23,1,14,10,46,45,17,11};
	int num2[10] = {1,2,4,5,3,9,8,84,51,12};
	int num3[5] = {1,2,8,10,5};
	int num4[1] = {5};
	/*
	if (argc == 1)
		write(1, "error\n", 6);
	*/
	int size = 1;
	ft_make_list(&(head.a), num4, size);
	ft_make_list(&(head.b), 0, 0);

	while (ternary_div(&head, 1)){
		print_func(&head);
	}
	while (head.a->size != size)
	{
		print_func(&head);
		if (head.a->next->size)
			ternary_div(&head, 1);
		else
			ternary_div(&head, 2);
	}
	print_func(&head);
}

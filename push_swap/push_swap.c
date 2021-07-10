/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:08:29 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/10 14:32:53 by seungcoh         ###   ########.fr       */
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
	int num3[3] = {1,2,8};
	int num4[2] = {5,6};
	/*
	if (argc == 1)
		write(1, "error\n", 6);
	*/

	ft_make_list(&(head.a), num, 15);
	ft_make_list(&(head.b), 0, 0);

	while (ternary_div(&head, 0))
	{
		print_func(&head);
	}
	print_func(&head);
}

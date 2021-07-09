/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:08:29 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/09 11:21:09 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


#include<stdio.h>
int main(int argc, char **argv)
{
	t_list *a, *b, *curr;
	int i;

	int num[10] = {4,6,8,7,2,3,1,23,5,14};
	int num2[10] = {1,2,4,5,3,9,8,84,51,12};
	int num3[3] = {1,2,8};
	int num4[2] = {5,6};
	/*
	if (argc == 1)
		write(1, "error\n", 6);
	*/
	ft_make_list(&a, num3, 3);
	//ft_make_list(&b, 0, 0);
	ft_make_list(&b, num4, 2);

	t_lpair head;
	head.a=a;
	head.b=b;
	r_ins(&head, 1, 0);
	curr = a->next;
	while (curr){
		printf("%d\n", curr->val);
		curr=curr->next;
	}
	printf("\n\n");
	curr = b->next;
	while (curr){
		printf("%d\n", curr->val);
		curr=curr->next;
	}
}

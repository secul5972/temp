/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:08:29 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/08 10:37:20 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list *a, *b, *curr;
	int i;

	int num[10] = {4,6,8,7,2,3,1,23,5,14};
	/*
	if (argc == 1)
		write(1, "error\n", 6);
	*/
	a = (t_list*)malloc(sizeof(t_list));
	b = (t_list*)malloc(sizeof(t_list));
	i=0;
	curr = a;
	curr = ft_make_list(&a, num, 10);
	curr = ft_make_list(&b, 0, 0);

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:08:29 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/09 00:58:19 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_pivot(t_list *head, int *f_pivot, int *s_pivot)
{
	int		f_idx;
	int		s_idx;
	int		i;
	t_list	*curr;

	f_idx  = head->size/3;
	s_idx = f_idx * 2;
	i = 0;
	curr = head->next;
	while(i < head->size)
	{
		if (i == f_idx)
			*f_pivot = curr->val;
		if (i == s_idx)
		{
			*s_pivot = curr->val;
			break;
		}
		curr = curr->next;
		i++;
	}
}

void	ternary_div(t_list *a, t_list *b, int h_flag)
{
	int		f_pivot;
	int		s_pivot;
	int		i;
	int		cnt;
	t_list	*curr;

	find_pivot(a, &f_pivot, &s_pivot);
	i = a->size;
	curr = a->next;
	while (i--)
	{
		if (curr->val < f_pivot)
			small_div(a, b, h_flag);
		else if (f_pivot <= curr->val && curr->val < s_pivot)
			middle_div(a, b, h_flag, &cnt);
		else
			big_div(a, b, h_flag);
	}
	while (cnt--)
	{
		if (h_flag)
			r_ins(a, b, 2, 1);
		else
		{

		}
	}
}

int main(int argc, char **argv)
{
	t_list *a, *b, *curr;
	int i;

	int num[10] = {4,6,8,7,2,3,1,23,5,14};
	/*
	if (argc == 1)
		write(1, "error\n", 6);
	*/
	ft_make_list(&a, num, 10);
	ft_make_list(&b, 0, 0);


}

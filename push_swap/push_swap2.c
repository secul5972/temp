/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 00:27:03 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/09 00:48:58 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_div(t_list *a, t_list *b, int f_flag)
{
	if (f_flag)
		p_ins(a, b, 2);
	else
	{

	}
}

void	middle_div(t_list *a, t_list *b, int f_flag)
{
	if (f_flag)
	{
		p_ins(a, b, 2);
		r_ins(a, b, 2, 0);
	}
	else
	{

	}
	
}

void	big_div(t_list *a, t_list *b, int f_flag)
{
	if (f_flag)
		r_ins(a, b, 1, 0);
	else
	{

	}
}
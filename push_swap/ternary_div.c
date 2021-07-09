/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 00:27:03 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/09 10:03:34 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_div(t_lpair *head, int s_flag, t_ipair *cnt)
{
	if (s_flag == 1 || s_flag == 3)
		p_ins(head, 2);
	else if(s_flag == 2)
	{
		r_ins(head, 2, 0);
		cnt->first++;
	}
}

void	middle_div(t_lpair *head, int s_flag, t_ipair *cnt)
{
	if (s_flag == 1 || s_flag == 3)
	{
		p_ins(head, 2);
		r_ins(head, 2, 0);
		cnt->first++;
	}
	else if (s_flag == 2)
	{
		p_ins(head, 1);
		r_ins(head, 1, 0);
		cnt->second++;
	}

}

void	big_div(t_lpair *head, int s_flag, t_ipair *cnt)
{
	if (s_flag == 1 || s_flag == 3)
	{
		r_ins(head, 1, 0);
		if (s_flag == 3)
			cnt->first++;
	}
	else if(s_flag == 2)
		p_ins(head, 1);
}
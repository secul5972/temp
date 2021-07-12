/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 10:38:14 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/12 10:59:20 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	l_swap(t_list **f, t_list **s)
{
	t_list *temp;
	
	temp = *f;
	*f = *s;
	*s = temp;
}

void	i_swap(int *f, int *s)
{
	int	temp;
	
	temp = *f;
	*f = *s;
	*s = temp;
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
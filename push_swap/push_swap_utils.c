/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 10:38:14 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/17 16:14:47 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	l_swap(t_list **f, t_list **s)
{
	t_list	*temp;

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

long	ft_atoi(char **s)
{
	long	ret;
	int		m_flag;
	int		flag;

	m_flag = 0;
	flag = 1;
	ret = 0;
	while (**s == 9 || **s == 10 || **s == 11 \
	|| **s == 12 || **s == 13 || **s == 32)
		(*s)++;
	if (**s == '+' || **s == '-')
		m_flag = *(*s)++ - '+';
	while ('0' <= **s && **s <= '9')
	{
		ret *= 10;
		ret += *(*s)++ - '0';
		flag = 0;
	}
	if (m_flag != 0)
		ret *= -1;
	if (flag)
		return (2147483648);
	return (ret);
}

void	ft_sort(t_list *head, t_ipair *pivot, int size)
{
	int		num[1000000];
	int		i;
	int		j;
	t_list	*curr;

	i = 0;
	curr = head->next;
	while (i < size)
	{
		num[i++] = curr->val;
		curr = curr->next;
	}
	curr = head->next;
	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
			if (num[i] > num[j])
				i_swap(num + i, num + j);
	}
	pivot->first = num[size / 3 + 1];
	pivot->second = num[size - size / 3 - 1];
}

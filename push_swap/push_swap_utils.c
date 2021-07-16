/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 10:38:14 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/17 01:13:30 by seungcoh         ###   ########.fr       */
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

long	ft_atoi(const char *s)
{
	size_t	i;
	long	ret;
	int		m_flag;
	int		flag;

	i = 0;
	m_flag = 0;
	flag = 1;
	ret = 0;
	while (s[i] == 9 || s[i] == 10 || s[i] == 11 \
	|| s[i] == 12 || s[i] == 13 || s[i] == 32)
		i++;
	if (s[i] == '+' || s[i] == '-')
		m_flag = s[i++] - '+';
	while ('0' <= s[i] && s[i] <= '9')
	{
		ret *= 10;
		ret += s[i++] - '0';
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
	int		*num;
	int		i;
	int		j;
	t_list	*curr;

	num = (int *)malloc(sizeof(int) * size);
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
	free(num);
}

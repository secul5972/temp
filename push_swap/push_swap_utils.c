/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 10:38:14 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/18 14:01:52 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	w_space(char **s)
{
	while (**s == 9 || **s == 10 || **s == 11 \
	|| **s == 12 || **s == 13 || **s == 32)
		(*s)++;
}

long	ft_atoi(char **s)
{
	long	ret;
	int		m_flag;
	int		flag;

	m_flag = 0;
	flag = 1;
	ret = 0;
	w_space(s);
	if (**s == '+' || **s == '-')
		m_flag = *(*s)++ - '+';
	while ('0' <= **s && **s <= '9')
	{
		ret *= 10;
		ret += *(*s)++ - '0';
		flag = 0;
	}
	w_space(s);
	if (m_flag != 0)
		ret *= -1;
	if (flag)
		return (2147483648);
	return (ret);
}

static int	*cpy_list(t_list *head, int size)
{
	int		*num;
	int		i;
	t_list	*curr;

	i = 0;
	curr = head->next;
	num = (int *)malloc(sizeof(int) * size);
	if (!num)
		return (0);
	while (i < size)
	{
		num[i++] = curr->val;
		curr = curr->next;
	}
	return (num);
}

int	ft_sort_int(t_list *head, t_ipair *pivot, int size)
{
	int		*num;
	int		i;
	int		j;

	num = cpy_list(head, size);
	if (!num)
		return (0);
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
	return (1);
}

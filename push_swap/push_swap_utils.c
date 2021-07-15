/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 10:38:14 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/15 20:23:14 by seungcoh         ###   ########.fr       */
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

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

long	ft_atoi(const char *str)
{
	size_t	i;
	long	ret;
	int		m_flag;
	int		flag;

	i = 0;
	m_flag = 0;
	flag = 1;
	ret = 0;
	while (str[i] == 9 || str[i] == 10 || str[i] == 11
	|| str[i] == 12 || str[i] == 13 || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		m_flag = str[i++] - '+';
	while ('0' <= str[i] && str[i] <= '9')
	{
		ret *= 10;
		ret += str[i] - '0';
		i++;
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

	num = (int*)malloc(sizeof(int)*(size));
	i = 0;
	curr = head->next;
	while(curr)
	{
		num[i++] = curr->val;
		curr = curr->next;
	}
	curr = head->next;
	i = 0;
	while(i < size)
	{
		j = i + 1;
		while(j < size)
		{
			if (num[i] > num[j])
				i_swap(num + i, num + j);
			j++;
		}
		i++;
	}

	pivot->first=num[size/3];
	pivot->second=num[size - size/3 - 1];
	free(num);
}

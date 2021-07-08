/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:12:48 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/08 10:49:14 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

typedef struct	s_list{
	t_list	*pre;
	t_list	*next;
	t_list	*end;
	int		val;
	int		size;
}				t_list;

void	list_swap(t_list **f, t_list **s);

void	s_ins(t_list *a, t_list *b, int head_flag);
void	p_ins(t_list *a, t_list*b, int head_flag);
void	r_ins(t_list *a, t_list *b, int head_flag, int rev_flag);

t_list	*ft_make_list(t_list **head, const int *val, const int size);
void	ft_push(t_list *head, t_list *pop_node, int end_flag);
t_list	*ft_pop(t_list *head, int end_flag);

#endif

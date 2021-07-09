/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:12:48 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/09 11:21:10 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct	s_list
{
	struct s_list	*pre;
	struct s_list	*next;
	struct s_list	*end;
	int		val;
	int		size;
}				t_list;

typedef struct	s_ipair
{
	int first;
	int second;
}				t_ipair;


typedef struct	s_lpair
{
	t_list *a;
	t_list *b;
}				t_lpair;

void	list_swap(t_list **f, t_list **s);
void	ft_make_list(t_list **head, const int *val, const int size);
void	ft_push(t_list *head, t_list *pop_node, int e_flag);
t_list	*ft_pop(t_list *head, int e_flag);
void	ternary_div(t_lpair *head, int s_flag);
void	s_ins(t_lpair *head, int h_flag);
void	p_ins(t_lpair *head, int h_flag);
void	r_ins(t_lpair *head, int h_flag, int rev_flag);
#endif

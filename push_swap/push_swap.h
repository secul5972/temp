/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:12:48 by seungcoh          #+#    #+#             */
/*   Updated: 2021/07/15 21:38:48 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

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

void	l_swap(t_list **f, t_list **s);
void	i_swap(int *f, int *s);
int		ft_max(int a, int b);
long	ft_atoi(const char *str);
void	ft_sort(t_list *head, t_ipair *pivot, int size);
t_list	*ft_lalloc(t_list *head, t_list *pre, const int val);
t_list	*ft_make_list(const int *val, const int size);
void	ft_push(t_list *head, t_list *pop_node, int e_flag);
t_list	*ft_pop(t_list *head, int e_flag);
void	all_free(t_lpair *head, t_list *ins);
void	s_ins(t_lpair *head, int h_flag, t_list *ins);
void	p_ins(t_lpair *head, int h_flag, t_list *ins);
void	r_ins(t_lpair *head, int h_flag, int rev_flag, t_list *ins);
int		les_than_four(t_lpair *head, int s_flag, int size, t_list *ins);
int		ternary_div(t_lpair *head, int s_flag, t_list *ins);
void	ins_merge(t_list *ins);

#endif

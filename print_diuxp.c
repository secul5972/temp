/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diuxp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:17:22 by seungcoh          #+#    #+#             */
/*   Updated: 2021/06/26 19:50:00 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_c_arr(va_list ap, t_cond *stat)
{
	char *ret;

	ret = 0;
	if (stat->spec == 'd' || stat->spec == 'i')
		ret = ft_ntoa(va_arg(ap, int), 10, stat);
	else if (stat->spec == 'u')
		ret = ft_ntoa(va_arg(ap, unsigned int), 10, stat);
	else if (stat->spec == 'x' || stat->spec == 'X')
		ret = ft_ntoa(va_arg(ap, unsigned int), 16, stat);
	else if (stat->spec == 'p')
		ret = ft_ptoa(va_arg(ap, unsigned long long), 16, stat);
	if (ret[0] == '0' && ret[1] == 0 && stat->prec == 0)
		ret[0] = 0;
	if ((stat->h_flag == 2) && ret[2] == '0' && (stat->prec == 0))
		ret[2] = 0;
	return (ret);
}

static void	fill_prec(char **ret, int *i, int len, char **ch_d)
{
	if (**ch_d == '-')
		(*ret)[(*i)++] = *((*ch_d)++);
	if (**ch_d == '0' && *(*ch_d + 1) == 'x')
	{
		(*ret)[(*i)++] = *((*ch_d)++);
		(*ret)[(*i)++] = *((*ch_d)++);
	}
	while (len--)
		(*ret)[(*i)++] = '0';
}

static char	*flag_cal(va_list ap, t_cond *stat, t_idx *idx, char **ch_d)
{
	char *ret;

	if (!(*ch_d = get_c_arr(ap, stat)))
		return (0);
	idx->len = ft_strlen(*ch_d);
	if ((stat->flag == 1) && (stat->m_flag || stat->h_flag) && stat->prec == -1)
	{
		stat->flag = 2;
		stat->prec = stat->width - stat->m_flag - stat->h_flag;
		idx->len -= stat->m_flag + stat->h_flag;
		stat->m_flag = 0;
		stat->h_flag = 0;
	}
	idx->prec = ft_max(idx->len - stat->m_flag - stat->h_flag, stat->prec)\
	+ stat->m_flag + stat->h_flag;
	idx->width = ft_max(stat->width, idx->prec);
	idx->offset = (stat->flag & (1 << 1)) ? 0 : idx->width - idx->prec;
	if (!(ret = (char *)malloc(sizeof(char) * (idx->width + 1))))
	{
		free(*ch_d);
		return (0);
	}
	idx->i = 0;
	return (ret);
}

char		*print_diuxp(va_list ap, t_cond *stat)
{
	char	*ret;
	char	*ch_d;
	char	width_c;
	t_idx	idx;

	if (stat->prec == 2147483648)
		stat->prec = -1;
	ret = flag_cal(ap, stat, &idx, &ch_d);
	width_c = ((stat->flag & (1 << 0)) && (stat->prec == -1)) ? '0' : ' ';
	while (idx.i < idx.offset)
		ret[idx.i++] = width_c;
	fill_prec(&ret, &idx.i, idx.prec - idx.len, &ch_d);
	while (idx.len-- - stat->m_flag - stat->h_flag)
		ret[idx.i++] = *(ch_d++);
	while (idx.i < idx.width)
		ret[idx.i++] = ' ';
	ret[idx.i] = 0;
	if (!ch_d)
		free(ch_d);
	stat->width = ft_strlen(ret);
	return (ret);
}

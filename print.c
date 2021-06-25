/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:17:22 by seungcoh          #+#    #+#             */
/*   Updated: 2021/06/25 19:16:21 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_cpe(va_list ap, t_cond *stat, int c_flag)
{
	char	c;
	char	width_c;
	char	*ret;
	t_idx	idx;

	idx.i = 0;
	idx.width = ft_max(stat->width, 1);
	idx.offset = (stat->flag & (1 << 1)) ? 0 : idx.width - 1;
	if (!(c = c_flag > 0 ? '%' : va_arg(ap, int)))
		idx.width--;
	if (!(ret = (char *)malloc(sizeof(char) * (idx.width + 1))))
		return (0);
	width_c = (stat->flag & (1 << 0)) ? '0' : ' ';
	while (idx.i < idx.offset)
		ret[idx.i++] = width_c;
	if (!c)
		stat->n_flag = 1;
	if (c)
		ret[idx.i++] = c;
	while (idx.i < idx.width)
		ret[idx.i++] = ' ';
	ret[idx.i] = 0;
	return (ret);
}

char	*print_s(va_list ap, t_cond *stat)
{
	char	*s;
	char	*ret;
	t_idx	idx;

	s = va_arg(ap, char *);
	if (!s)
	{
		s = malloc(7);
		s[0] = '(';
		s[1] = 'n';
		s[2] = 'u';
		s[3] = 'l';
		s[4] = 'l';
		s[5] = ')';
		s[6] = 0;
	}
	idx.len = ft_strlen(s);
	idx.prec = ft_min(idx.len, stat->prec);
	idx.width = ft_max(stat->width, idx.prec);
	idx.offset = (stat->flag & (1 << 1)) ? 0 : idx.width - idx.prec;
	if (!(ret = (char *)malloc(sizeof(char) * (idx.width + 1))))
		return (0);
	idx.i = 0;
	while (idx.i < idx.offset)
		ret[idx.i++] = ' ';
	while (idx.prec--)
		ret[idx.i++] = *(s++);
	while (idx.i < idx.width)
		ret[idx.i++] = ' ';
	ret[idx.i] = 0;
	if (!s)
		free(s);
	return (ret);
}

char	*get_c_arr(va_list ap, t_cond *stat)
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
		ret = ft_ntoa(va_arg(ap, unsigned long long), 16, stat);
	if (ret[0] == '0' && ret[1] == 0 && stat->prec == 0)
		ret[0] = 0;
	if ((stat->hex_flag == 2) && ret[2] == '0' && (stat->prec == 0))
		ret[2] = 0;
	return (ret);
}

void	fill_prec(char **ret, int *i, int len, char **ch_d)
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

char	*print_diuxp(va_list ap, t_cond *stat)
{
	char	*ret;
	char	*ch_d;
	char	width_c;
	t_idx	idx;

	if (stat->prec == 2147483648)
		stat->prec = -1;
	if (!(ch_d = get_c_arr(ap, stat)))
		return (0);
	idx.len = ft_strlen(ch_d);
	idx.prec = ft_max(idx.len - stat->m_flag - stat->hex_flag, stat->prec)\
	+ stat->m_flag + stat->hex_flag;
	idx.width = ft_max(stat->width, idx.prec);
	idx.offset = (stat->flag & (1 << 1)) ? 0 : idx.width - idx.prec;
	if (!(ret = (char *)malloc(sizeof(char) * (idx.width + 1))))
	{
		free(ch_d);
		return (0);
	}
	idx.i = 0;
	width_c = ((stat->flag & (1 << 0)) && (stat->prec == -1)) ? '0' : ' ';
	if ((stat->flag & 1) && !(stat->flag & 2) && (stat->m_flag == 1) && stat->width > idx.len && stat->prec == -1)
	{
		ret[idx.i++] = '-';
		stat->m_flag = 0;
		ch_d++;
		idx.len--;
	}
	while (idx.i < idx.offset)
		ret[idx.i++] = width_c;
	fill_prec(&ret, &idx.i, idx.prec - idx.len, &ch_d);
	while (idx.len-- - stat->m_flag - stat->hex_flag)
		ret[idx.i++] = *(ch_d++);
	while (idx.i < idx.width)
		ret[idx.i++] = ' ';
	ret[idx.i] = 0;
	if (!ch_d)
		free(ch_d);
	return (ret);
}

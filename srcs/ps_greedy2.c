/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_greedy2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/14 17:24:10 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

long	*ps_lis(t_dll *sa, const long size)
{
	long		*data;
	long		*lis;
	long		*recode;
	long		idx;
	long		target_idx;

	ps_arr_init(&data, &lis, &recode, size);
	idx = 0;
	while (idx < size)
	{
		data[idx] = ((t_item *)sa->content)->idx;
		target_idx = ps_bin_search(lis, data[idx], size);
		lis[target_idx] = ((t_item *)sa->content)->idx;
		recode[idx] = target_idx;
		idx++;
		sa = sa->next;
	}
	ps_make_check_arr(data, recode, lis, size);
	free(data);
	free(recode);
	return (lis);
}

long	ps_bin_search(long *lis, long data, long size)
{
	long	l_idx;
	long	r_idx;
	long	mid_idx;

	l_idx = 0;
	r_idx = size;
	while (l_idx <= r_idx)
	{
		mid_idx = (l_idx + r_idx) / 2;
		if (lis[mid_idx] < data && l_idx == r_idx)
			return (mid_idx + 1);
		if (lis[mid_idx] > data)
			r_idx = mid_idx - 1;
		else
			l_idx = mid_idx + 1;
	}
	return (l_idx);
}

void	ps_make_check_arr(long *data, long *recode, long *lis, long size)
{
	long	idx;
	long	max;

	max = 0;
	idx = 0;
	while (idx < size)
	{
		if (max < recode[idx] + 1)
			max = recode[idx] + 1;
		idx++;
	}
	while (idx >= 0)
	{
		if (max > 0 && recode[idx] == max - 1)
		{
			lis[data[idx]] = -1;
			max--;
		}
		if (lis[idx] != -1)
			lis[idx] = 0;
		idx--;
	}
}

void	ps_arr_init(long **data, long **lis, long **recode, long size)
{
	long	idx;

	(*data) = ft_calloc(size + 1, sizeof(long));
	if ((*data) == NULL)
		exit_manager(NULL);
	(*lis) = ft_calloc(size + 1, sizeof(long));
	if ((*lis) == NULL)
		exit_manager(NULL);
	(*recode) = ft_calloc(size + 1, sizeof(long));
	if ((*recode) == NULL)
		exit_manager(NULL);
	idx = 0;
	while (idx <= size)
	{
		(*recode)[idx] = -1;
		(*lis)[idx] = (long)INT_MAX * 3;
		idx++;
	}
}

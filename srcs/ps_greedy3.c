/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_greedy3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2023/12/31 21:45:02 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ps_fill_cmd_cnt(t_dll *sa, t_dll *sb)
{
	long		j;
	long		i;
	const long	sa_size = dll_size(sa);

	i = 1;
	while (sb != NULL)
	{
		j = ps_get_idx_j(sa, sb);
		if (j > sa_size)
			j = ps_get_min_idx_in_sa_j(sa);
		ps_set_cmd(sa, sb, i, j);
		sb = sb->next;
		i++;
	}
}

long	ps_get_idx_j(t_dll *sa, t_dll *sb)
{
	t_dll	*prev_node;
	t_dll	*curr_node;
	long	j;

	j = 1;
	curr_node = sa;
	prev_node = sa;
	if (curr_node == NULL)
		return (j);
	while (prev_node->next != NULL)
		prev_node = prev_node->next;
	if (curr_node == prev_node)
		return (j);
	while (curr_node != NULL)
	{
		if (((t_item *)prev_node->content)->idx < \
			((t_item *)sb->content)->idx && \
			((t_item *)sb->content)->idx < ((t_item *)curr_node->content)->idx)
			return (j);
		curr_node = curr_node->next;
		if (curr_node != NULL)
			prev_node = curr_node->prev;
		j++;
	}
	return (j);
}

long	ps_get_min_idx_in_sa_j(t_dll *sa)
{
	long	idx;
	long	min_idx;
	long	min;

	min = 1;
	if (sa != NULL)
		min = ((t_item *)sa->content)->idx;
	min_idx = 1;
	idx = 1;
	while (sa != NULL)
	{
		if (min > ((t_item *)sa->content)->idx)
		{
			min = ((t_item *)sa->content)->idx;
			min_idx = idx;
		}
		idx++;
		sa = sa->next;
	}
	return (min_idx);
}

void	ps_set_cmd(t_dll *sa, t_dll *sb, long i, long j)
{
	const long	rra = dll_size(sa) - j + 1;
	const long	rrb = dll_size(sb) - i + 1;

	((t_item *)sb->content)->cmd_cnt = ps_max(j - 1, i - 1);
	((t_item *)sb->content)->ra_cmd_cnt = j - 1;
	((t_item *)sb->content)->rb_cmd_cnt = i - 1;
	((t_item *)sb->content)->rra_cmd_cnt = 0;
	((t_item *)sb->content)->rrb_cmd_cnt = 0;
	if (((t_item *)sb->content)->cmd_cnt > ps_max(rra, rrb))
	{
		((t_item *)sb->content)->cmd_cnt = ps_max(rra, rrb);
		((t_item *)sb->content)->ra_cmd_cnt = 0;
		((t_item *)sb->content)->rb_cmd_cnt = 0;
		((t_item *)sb->content)->rra_cmd_cnt = rra;
		((t_item *)sb->content)->rrb_cmd_cnt = rrb;
	}
	ps_set_cmd2(sa, sb, i, j);
}

void	ps_set_cmd2(t_dll *sa, t_dll *sb, long i, long j)
{
	const long	rra = dll_size(sa) - j + 1;
	const long	rrb = dll_size(sb) - i + 1;

	if (((t_item *)sb->content)->cmd_cnt > j - 1 + rrb)
	{
		((t_item *)sb->content)->cmd_cnt = j - 1 + rrb;
		((t_item *)sb->content)->ra_cmd_cnt = j - 1;
		((t_item *)sb->content)->rb_cmd_cnt = 0;
		((t_item *)sb->content)->rra_cmd_cnt = 0;
		((t_item *)sb->content)->rrb_cmd_cnt = rrb;
	}
	else if (((t_item *)sb->content)->cmd_cnt > i - 1 + rra)
	{
		((t_item *)sb->content)->cmd_cnt = i - 1 + rra;
		((t_item *)sb->content)->ra_cmd_cnt = 0;
		((t_item *)sb->content)->rb_cmd_cnt = i - 1;
		((t_item *)sb->content)->rra_cmd_cnt = rra;
		((t_item *)sb->content)->rrb_cmd_cnt = 0;
	}
}

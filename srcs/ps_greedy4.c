/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_greedy4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/03 18:55:47 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ps_greedy(t_dll **sa, t_dll **sb, t_dll **cmds)
{
	t_dll	*min_sb;

	while ((*sb) != NULL)
	{
		ps_fill_cmd_cnt(*sa, *sb);
		min_sb = ps_get_min_cmd_dll(*sb);
		ps_sb_sa_move_top(sa, sb, min_sb, cmds);
		pab(sa, sb, "pa", cmds);
	}
	ps_ra_sort(sa, cmds);
}

t_dll	*ps_get_min_cmd_dll(t_dll *sb)
{
	t_dll	*res;

	res = sb;
	while (sb != NULL)
	{
		if (((t_item *)res->content)->cmd_cnt > \
			((t_item *)sb->content)->cmd_cnt)
			res = sb;
		sb = sb->next;
	}
	return (res);
}

void	ps_sb_sa_move_top(t_dll **sa, t_dll **sb, t_dll *min_sb, t_dll **cmds)
{
	long	ra;
	long	rb;
	long	rra;
	long	rrb;

	ra = ((t_item *)min_sb->content)->ra_cmd_cnt;
	rb = ((t_item *)min_sb->content)->rb_cmd_cnt;
	rra = ((t_item *)min_sb->content)->rra_cmd_cnt;
	rrb = ((t_item *)min_sb->content)->rrb_cmd_cnt;
	while (ra > 0 || rb > 0 || rra > 0 || rrb > 0)
	{
		if (ra-- > 0)
			rab(sa, "ra", cmds);
		if (rb-- > 0)
			rab(sb, "rb", cmds);
		if (rra-- > 0)
			rrab(sa, "rra", cmds);
		if (rrb-- > 0)
			rrab(sb, "rrb", cmds);
	}
}

void	ps_ra_sort(t_dll **sa, t_dll **cmds)
{
	long		one;
	const long	size = dll_size(*sa);

	one = ps_get_min_idx_in_sa_j(*sa);
	while (one - 1 <= size - one + 1 && ((t_item *)(*sa)->content)->idx != 1)
		rab(sa, "ra", cmds);
	while (one - 1 > size - one + 1 && ((t_item *)(*sa)->content)->idx != 1)
		rrab(sa, "rra", cmds);
}

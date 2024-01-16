/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_small_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/15 14:23:09 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ps_2_data(t_dll **sa, t_dll **cmds)
{
	if (((t_item *)(*sa)->content)->idx > \
		((t_item *)((*sa)->next)->content)->idx)
		sab(sa, "sa", cmds);
}

void	ps_3_data(t_dll **sa, t_dll **cmds)
{
	const long	min_j = ps_get_min_idx_in_sa_j(*sa);

	if (min_j == 1)
		rab(sa, "ra", cmds);
	else if (min_j == 2)
		rrab(sa, "rra", cmds);
	ps_2_data(sa, cmds);
	rrab(sa, "rra", cmds);
}

void	ps_4_data(t_dll **sa, t_dll **sb, t_dll **cmds)
{
	int	one_two_cnt;

	one_two_cnt = 0;
	while (one_two_cnt != 1)
	{
		if (((t_item *)(*sa)->content)->idx <= 1)
			one_two_cnt++;
		if (((t_item *)(*sa)->content)->idx <= 1)
			pab(sa, sb, "pb", cmds);
		else
			rab(sa, "ra", cmds);
	}
	ps_3_data(sa, cmds);
	pab(sa, sb, "pa", cmds);
}

void	ps_5_data(t_dll **sa, t_dll **sb, t_dll **cmds)
{
	int	one_two_cnt;

	one_two_cnt = 0;
	while (one_two_cnt != 2)
	{
		if (((t_item *)(*sa)->content)->idx <= 2)
			one_two_cnt++;
		if (((t_item *)(*sa)->content)->idx <= 2)
			pab(sa, sb, "pb", cmds);
		else
			rab(sa, "ra", cmds);
	}
	ps_3_data(sa, cmds);
	if (((t_item *)(*sb)->content)->idx == 1)
		sab(sb, "sb", cmds);
	pab(sa, sb, "pa", cmds);
	pab(sa, sb, "pa", cmds);
}

void	ps_small_data(t_dll **sa, t_dll **sb, t_dll **cmds, long size)
{
	t_dll	*tmp_sa;
	int		sorted;

	sorted = 0;
	tmp_sa = *sa;
	while ((tmp_sa->next) != NULL)
	{
		if (((t_item *)(tmp_sa)->content)->idx - \
		((t_item *)((tmp_sa)->next)->content)->idx == -1)
			sorted++;
		tmp_sa = tmp_sa->next;
	}
	if (sorted == size - 1)
		return ;
	if (size == 2)
		ps_2_data(sa, cmds);
	else if (size == 3)
		ps_3_data(sa, cmds);
	else if (size == 4)
		ps_4_data(sa, sb, cmds);
	else if (size == 5)
		ps_5_data(sa, sb, cmds);
}

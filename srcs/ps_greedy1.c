/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_greedy1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/14 19:46:58 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ps_partition(t_dll **sa, t_dll **sb, t_dll **cmds)
{
	const long	sa_size = dll_size(*sa);
	const long	pivot1_3 = sa_size / 3;
	const long	pivot2_3 = (sa_size * 2) / 3;
	long		*lis_check;
	long		iter;

	lis_check = ps_lis(*sa, dll_size(*sa));
	iter = 0;
	while (ps_is_all_in_lis(*sa, lis_check) == FALSE && iter < sa_size)
	{
		if (lis_check[((t_item *)(*sa)->content)->idx] == -1)
			rab(sa, "ra", cmds);
		else if (((t_item *)(*sa)->content)->idx <= pivot1_3)
		{
			pab(sa, sb, "pb", cmds);
			rab(sb, "rb", cmds);
		}
		else if (pivot2_3 < ((t_item *)(*sa)->content)->idx)
			rab(sa, "ra", cmds);
		else
			pab(sa, sb, "pb", cmds);
		iter++;
	}
	ps_partition2(sa, sb, cmds, lis_check);
}

void	ps_partition2(t_dll **sa, t_dll **sb, t_dll **cmds, long *lis_check)
{
	const long	sa_size = dll_size(*sa);
	long		iter;

	iter = 0;
	while (ps_is_all_in_lis(*sa, lis_check) == FALSE && iter < sa_size)
	{
		if (lis_check[((t_item *)(*sa)->content)->idx] == -1)
			rab(sa, "ra", cmds);
		else
			pab(sa, sb, "pb", cmds);
		iter++;
	}
	free(lis_check);
}

int	ps_is_all_in_lis(t_dll *sa, long *lis_check)
{
	while (sa != NULL)
	{
		if (lis_check[((t_item *)sa->content)->idx] != -1)
			return (FALSE);
		sa = sa->next;
	}
	return (TRUE);
}

void	ps_optimize(t_dll **cmds)
{
	t_dll	*curr_node;
	char	*curr_cmd;
	char	*next_cmd;

	curr_node = *cmds;
	while (curr_node != NULL && curr_node->next != NULL)
	{
		curr_cmd = (char *)curr_node->content;
		next_cmd = (char *)(curr_node->next->content);
		if (ps_can_optimize(curr_cmd, next_cmd) == TRUE)
		{
			if (ft_strlen(curr_cmd) == 2)
				curr_cmd[1] = 'r';
			else
				curr_cmd[2] = 'r';
			dll_del_one(curr_node->next);
		}
		curr_node = curr_node->next;
	}
}

int	ps_can_optimize(char *curr_cmd, char *next_cmd)
{
	if ((((ft_strncmp(curr_cmd, "ra", 2) == 0) && \
		(ft_strncmp(next_cmd, "rb", 2) == 0)) || \
		((ft_strncmp(curr_cmd, "rb", 2) == 0) && \
		(ft_strncmp(next_cmd, "ra", 2) == 0))) || \
		(((ft_strncmp(curr_cmd, "rra", 3) == 0) && \
		(ft_strncmp(next_cmd, "rrb", 3) == 0)) || \
		((ft_strncmp(curr_cmd, "rrb", 3) == 0) && \
		(ft_strncmp(next_cmd, "rra", 3) == 0))))
		return (TRUE);
	return (FALSE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_apply_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2023/12/31 21:45:10 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ps_apply_cmds(t_dll **sa, t_dll **sb, t_dll *cmds, int flag)
{
	if (flag == FALSE)
		while (cmds->next != NULL)
			cmds = cmds->next;
	while (cmds != NULL)
	{
		if (flag == TRUE)
			ps_exec_cmd(sa, sb, cmds);
		else if (flag == FALSE)
			ps_exec_cmd_inversion(sa, sb, cmds);
		if (flag == TRUE)
			cmds = cmds->next;
		else if (flag == FALSE)
			cmds = cmds->prev;
	}
}

void	ps_exec_cmd(t_dll **sa, t_dll **sb, t_dll *cmds)
{
	if (ft_strncmp(cmds->content, "sa", 2) == 0)
		sab(sa, "sa", NULL);
	else if (ft_strncmp(cmds->content, "sb", 2) == 0)
		sab(sb, "sb", NULL);
	else if (ft_strncmp(cmds->content, "ss", 2) == 0)
		ss(sa, sb, "ss", NULL);
	else if (ft_strncmp(cmds->content, "ra", 2) == 0)
		rab(sa, "ra", NULL);
	else if (ft_strncmp(cmds->content, "rb", 2) == 0)
		rab(sb, "rb", NULL);
	else if (ft_strlen(cmds->content) == 2 \
	&& ft_strncmp(cmds->content, "rr", 2) == 0)
		rr(sa, sb, "rr", NULL);
	else if (ft_strncmp(cmds->content, "rra", 3) == 0)
		rrab(sa, "rra", NULL);
	else if (ft_strncmp(cmds->content, "rrb", 3) == 0)
		rrab(sb, "rrb", NULL);
	else if (ft_strncmp(cmds->content, "rrr", 3) == 0)
		rrr(sa, sb, "rrr", NULL);
	else if (ft_strncmp(cmds->content, "pa", 2) == 0)
		pab(sa, sb, "pa", NULL);
	else if (ft_strncmp(cmds->content, "pb", 2) == 0)
		pab(sa, sb, "pb", NULL);
}

void	ps_exec_cmd_inversion(t_dll **sa, t_dll **sb, t_dll *cmds)
{
	if (ft_strncmp(cmds->content, "sa", 2) == 0)
		sab(sa, "sa", NULL);
	else if (ft_strncmp(cmds->content, "sb", 2) == 0)
		sab(sb, "sb", NULL);
	else if (ft_strncmp(cmds->content, "ss", 2) == 0)
		ss(sa, sb, "ss", NULL);
	else if (ft_strncmp(cmds->content, "ra", 2) == 0)
		rrab(sa, "rra", NULL);
	else if (ft_strncmp(cmds->content, "rb", 2) == 0)
		rrab(sb, "rrb", NULL);
	else if (ft_strlen(cmds->content) == 2 \
		&& ft_strncmp(cmds->content, "rr", 2) == 0)
		rrr(sa, sb, "rrr", NULL);
	else if (ft_strncmp(cmds->content, "rra", 3) == 0)
		rab(sa, "ra", NULL);
	else if (ft_strncmp(cmds->content, "rrb", 3) == 0)
		rab(sb, "rb", NULL);
	else if (ft_strncmp(cmds->content, "rrr", 3) == 0)
		rr(sa, sb, "rr", NULL);
	else if (ft_strncmp(cmds->content, "pa", 2) == 0)
		pab(sa, sb, "pb", NULL);
	if (ft_strncmp(cmds->content, "pb", 2) == 0)
		pab(sa, sb, "pa", NULL);
}

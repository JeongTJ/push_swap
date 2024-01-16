/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/15 14:22:26 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/push_swap_bonus.h"

int	exit_manager(char *str)
{
	if (str != NULL)
		ft_printf("\033[0;31m%s\033[0m\n", str);
	exit(EXIT_FAILURE);
}

void	print_cmds(t_dll *cmds)
{
	int		idx;
	char	*cmd;

	idx = 0;
	while (cmds != NULL)
	{
		cmd = (char *)cmds->content;
		ft_printf("%s\n", cmd);
		idx++;
		cmds = cmds->next;
	}
}

void	print_cmds_inversion(t_dll *cmds)
{
	int		idx;

	idx = 0;
	while (cmds->next != NULL)
		cmds = cmds->next;
	while (cmds != NULL)
	{
		print_cmd(cmds);
		idx++;
		cmds = cmds->prev;
	}
}

void	print_cmd(t_dll *cmds)
{
	if (ft_strncmp(cmds->content, "sa", 2) == 0)
		ft_printf("sa\n");
	else if (ft_strncmp(cmds->content, "sb", 2) == 0)
		ft_printf("sb\n");
	else if (ft_strncmp(cmds->content, "ss", 2) == 0)
		ft_printf("ss\n");
	else if (ft_strncmp(cmds->content, "ra", 2) == 0)
		ft_printf("rra\n");
	else if (ft_strncmp(cmds->content, "rb", 2) == 0)
		ft_printf("rrb\n");
	else if (ft_strlen(cmds->content) == 2 \
	&& ft_strncmp(cmds->content, "rr", 2) == 0)
		ft_printf("rrr\n");
	else if (ft_strncmp(cmds->content, "rra", 3) == 0)
		ft_printf("ra\n");
	else if (ft_strncmp(cmds->content, "rrb", 3) == 0)
		ft_printf("rb\n");
	else if (ft_strncmp(cmds->content, "rrr", 3) == 0)
		ft_printf("rr\n");
	else if (ft_strncmp(cmds->content, "pa", 2) == 0)
		ft_printf("pb\n");
	else if (ft_strncmp(cmds->content, "pb", 2) == 0)
		ft_printf("pa\n");
}

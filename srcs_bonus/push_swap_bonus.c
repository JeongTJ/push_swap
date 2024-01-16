/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/15 14:36:27 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/push_swap_bonus.h"

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
	else
		exit(EXIT_FAILURE);
}

void	ps_is_sorted(t_dll *sa, t_dll *sb)
{
	long		cnt;
	const long	size = dll_size(sa);

	cnt = 0;
	while (sa != NULL && sa->next != NULL)
	{
		if (((t_item *)sa->content)->idx + 1 == \
			((t_item *)((sa->next)->content))->idx)
			cnt++;
		sa = sa->next;
	}
	if (cnt == size - 1 && sb == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	ps_apply_cmds(t_dll **sa, t_dll **sb, t_dll **cmds)
{
	t_dll	*node;
	t_dll	*tmp_cmds;
	char	*cmd;

	while (1)
	{
		cmd = get_next_line(0);
		if (cmd == NULL)
			break ;
		cmd[ft_strlen(cmd) - 1] = '\0';
		node = dll_new_node(cmd);
		if (node == NULL)
			exit(EXIT_FAILURE);
		dll_add_back(cmds, node);
	}
	tmp_cmds = *cmds;
	while (tmp_cmds != NULL)
	{
		ps_exec_cmd(sa, sb, tmp_cmds);
		tmp_cmds = tmp_cmds->next;
	}
}

int	main(int argc, char **argv)
{
	t_dll	*stack_a;
	t_dll	*stack_b;
	t_dll	*cmds;

	ps_init(argc, argv, &stack_a, &stack_b);
	if (!ps_double_check(stack_a))
		exit_manager("Error");
	if (stack_a == NULL)
		exit_manager(NULL);
	ps_data_normalization(stack_a);
	ps_apply_cmds(&stack_a, &stack_b, &cmds);
	ps_is_sorted(stack_a, stack_b);
	dll_del_all(&stack_a);
	dll_del_all(&stack_b);
	dll_del_all(&cmds);
	return (0);
}

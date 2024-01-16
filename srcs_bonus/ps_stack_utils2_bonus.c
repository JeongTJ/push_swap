/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/15 13:45:19 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/push_swap_bonus.h"

void	rrab(t_dll **s, char *str, t_dll **cmds)
{
	t_dll	*last;

	last = dll_del_back(s);
	dll_add_front(s, last);
	ps_save_cmd(str, cmds);
}

void	rrr(t_dll **sa, t_dll **sb, char *str, t_dll **cmds)
{
	rrab(sa, NULL, NULL);
	rrab(sb, NULL, NULL);
	ps_save_cmd(str, cmds);
}

char	*ps_get_cmd(const char *str)
{
	char	*res;
	size_t	size;

	size = ft_strlen(str);
	res = ft_calloc(size + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_memmove(res, str, size);
	return (res);
}

void	ps_save_cmd(const char *str, t_dll **cmds)
{
	char	*cmd;
	t_dll	*new;

	if (cmds == NULL)
		return ;
	cmd = ps_get_cmd(str);
	if (cmd == NULL)
		exit_manager(NULL);
	new = dll_new_node(cmd);
	if (new == NULL)
		exit_manager(NULL);
	dll_add_back(cmds, new);
}

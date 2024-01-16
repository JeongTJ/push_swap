/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/15 13:45:18 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/push_swap_bonus.h"

void	sab(t_dll **s, char *str, t_dll **cmds)
{
	t_dll	*first;
	t_dll	*second;

	first = dll_del_front(s);
	second = dll_del_front(s);
	dll_add_front(s, first);
	dll_add_front(s, second);
	ps_save_cmd(str, cmds);
}

void	ss(t_dll **sa, t_dll **sb, char *str, t_dll **cmds)
{
	sab(sa, NULL, NULL);
	sab(sb, NULL, NULL);
	ps_save_cmd(str, cmds);
}

void	pab(t_dll **src_s, t_dll **dest_s, char *str, t_dll **cmds)
{
	t_dll	**tmp;
	t_dll	*first;

	if (ft_strncmp(str, "pa", 2) == 0)
	{
		tmp = src_s;
		src_s = dest_s;
		dest_s = tmp;
	}
	first = dll_del_front(src_s);
	dll_add_front(dest_s, first);
	ps_save_cmd(str, cmds);
}

void	rab(t_dll **s, char *str, t_dll **cmds)
{
	t_dll	*first;

	first = dll_del_front(s);
	dll_add_back(s, first);
	ps_save_cmd(str, cmds);
}

void	rr(t_dll **sa, t_dll **sb, char *str, t_dll **cmds)
{
	rab(sa, NULL, NULL);
	rab(sb, NULL, NULL);
	ps_save_cmd(str, cmds);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/15 14:41:09 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ps_init(int argc, char **argv, t_dll **sa, t_dll **sb)
{
	char	**res_split;
	int		idx;

	*sa = NULL;
	*sb = NULL;
	idx = 1;
	while (idx < argc)
	{
		res_split = ft_split(argv[idx], ' ');
		if (res_split == NULL)
			exit_manager(NULL);
		if (*res_split == NULL)
			exit_manager("Error");
		ps_init2(res_split, sa);
		free(res_split);
		idx++;
	}
}

void	ps_init2(char **res_split, t_dll **sa)
{
	t_item	*item;
	t_dll	*node;

	while (*res_split)
	{
		if (!ps_is_valid_data(*res_split))
			exit_manager("Error");
		item = ft_calloc(1, sizeof(t_item));
		if (item == NULL)
			exit_manager(NULL);
		item->data = ft_atoi(*res_split);
		item->idx = 1;
		item->cmd_cnt = 0;
		item->ra_cmd_cnt = 0;
		item->rb_cmd_cnt = 0;
		item->rra_cmd_cnt = 0;
		item->rrb_cmd_cnt = 0;
		node = dll_new_node(item);
		free(*res_split);
		if (node == NULL)
			exit_manager(NULL);
		dll_add_back(sa, node);
		res_split++;
	}
}

int	ps_is_valid_data(const char *s)
{
	int		idx;
	long	res_atol;

	if (s[0] == '\0')
		return (FALSE);
	res_atol = ps_atol(s);
	if (res_atol > INT_MAX || res_atol < INT_MIN)
		return (FALSE);
	if (!((!ft_isalpha(s[0]) && ft_isalnum(s[0])) \
		|| s[0] == '-' || s[0] == '+'))
		return (FALSE);
	idx = 0;
	if (s[0] == '-' || s[0] == '+')
		idx++;
	while (s[idx])
	{
		if (!(!ft_isalpha(s[idx]) && ft_isalnum(s[idx])))
			return (FALSE);
		idx++;
	}
	if (idx == 1 && (s[0] == '-' || s[0] == '+'))
		return (FALSE);
	return (TRUE);
}

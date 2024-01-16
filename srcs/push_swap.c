/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/15 14:23:38 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ps_sort(t_dll **sa, t_dll **sb, t_dll **cmds_p, t_dll **cmds_q)
{
	ps_data_normalization(*sa);
	if (dll_size(*sa) <= 5)
		ps_small_data(sa, sb, cmds_p, dll_size(*sa));
	else
	{
		ps_partition(sa, sb, cmds_p);
		ps_greedy(sa, sb, cmds_p);
	}
	ps_optimize(cmds_p);
	ps_apply_cmds(sa, sb, *cmds_p, TRUE);
	if (dll_size(*sa) <= 5)
		ps_small_data(sa, sb, cmds_q, dll_size(*sa));
	else
	{
		ps_partition(sa, sb, cmds_q);
		ps_greedy(sa, sb, cmds_q);
	}
	ps_optimize(cmds_q);
}

int	main(int argc, char **argv)
{
	t_dll	*stack_a;
	t_dll	*stack_b;
	t_dll	*cmds_p;
	t_dll	*cmds_q;

	cmds_p = NULL;
	cmds_q = NULL;
	ps_init(argc, argv, &stack_a, &stack_b);
	if (!ps_double_check(stack_a))
		exit_manager("Error");
	if (stack_a == NULL)
		exit_manager(NULL);
	ps_sort(&stack_a, &stack_b, &cmds_p, &cmds_q);
	if (dll_size(cmds_p) <= dll_size(cmds_q))
		print_cmds(cmds_p);
	else
		print_cmds_inversion(cmds_q);
	dll_del_all(&stack_a);
	dll_del_all(&stack_b);
	dll_del_all(&cmds_p);
	dll_del_all(&cmds_q);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_dll2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2023/12/31 21:45:07 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

long	dll_size(t_dll *dll)
{
	long	res;

	res = 0;
	while (dll != NULL && dll->prev != NULL)
		dll = dll->prev;
	while (dll != NULL)
	{
		res++;
		dll = dll->next;
	}
	return (res);
}

int	dll_empty(t_dll *dll)
{
	return (dll == NULL);
}

void	dll_del_one(t_dll *del_node)
{
	t_dll	*prev_node;
	t_dll	*next_node;

	prev_node = del_node->prev;
	next_node = del_node->next;
	if (prev_node != NULL)
		prev_node->next = next_node;
	if (next_node != NULL)
		next_node->prev = prev_node;
	free(del_node->content);
	free(del_node);
}

void	dll_del_all(t_dll **dll)
{
	t_dll	*curr_node;
	t_dll	*del_node;

	curr_node = *dll;
	while (curr_node != NULL)
	{
		del_node = curr_node;
		curr_node = curr_node->next;
		dll_del_one(del_node);
	}
}

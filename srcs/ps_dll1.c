/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_dll1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2023/12/31 21:45:08 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_dll	*dll_new_node(void *item)
{
	t_dll	*node;

	node = ft_calloc(1, sizeof(t_dll));
	if (node == NULL)
		return (NULL);
	node->content = item;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	dll_add_front(t_dll **dll, t_dll *new)
{
	if (new == NULL)
		return ;
	if ((*dll) == NULL)
	{
		(*dll) = new;
		return ;
	}
	(*dll)->prev = new;
	new->next = (*dll);
	new->prev = NULL;
	(*dll) = new;
}

void	dll_add_back(t_dll **dll, t_dll *new)
{
	t_dll	*tmp;

	if (new == NULL)
		return ;
	if ((*dll) == NULL)
	{
		(*dll) = new;
		return ;
	}
	tmp = *dll;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	new->next = NULL;
}

t_dll	*dll_del_front(t_dll **dll)
{
	t_dll	*res;

	res = (*dll);
	if (res == NULL)
		return (NULL);
	(*dll) = (*dll)->next;
	res->next = NULL;
	if ((*dll) == NULL)
		return (res);
	(*dll)->prev = NULL;
	return (res);
}

t_dll	*dll_del_back(t_dll **dll)
{
	t_dll	*tail;
	t_dll	*res;

	tail = (*dll);
	if (tail == NULL)
		return (NULL);
	while (tail->next != NULL)
		tail = tail->next;
	res = tail;
	tail = tail->prev;
	if (res == NULL)
		return (NULL);
	res->prev = NULL;
	if (tail == NULL)
	{
		(*dll) = NULL;
		return (res);
	}
	tail->next = NULL;
	return (res);
}

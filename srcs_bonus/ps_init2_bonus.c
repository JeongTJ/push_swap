/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/15 13:44:01 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/push_swap_bonus.h"

long	ps_atol(const char *str)
{
	long			sign;
	unsigned long	res;

	sign = 1;
	res = 0;
	while (ft_strchr("\t\n\v\f\r ", *str) && *str)
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (ft_isalnum(*str) && !ft_isalpha(*str) && *str)
	{
		if (res * 10 + (unsigned long)(*str - '0') > \
			(unsigned long)9223372036854775807 || \
			res > (unsigned long)9223372036854775807 / 10)
			return ((1 - 2 * (sign == -1)) * \
			9223372036854775807 - (sign == -1));
		res *= 10;
		res += (unsigned long)(*str - '0');
		str++;
	}
	return (sign * (long)res);
}

int	ps_double_check(t_dll *sa)
{
	t_item	*sa_items;
	t_item	*tmp_items;
	t_dll	*tmp_sa;
	int		count;

	while (sa != NULL)
	{
		tmp_sa = sa;
		count = 0;
		while (tmp_sa != NULL)
		{
			sa_items = (t_item *)sa->content;
			tmp_items = (t_item *)tmp_sa->content;
			if (sa_items->data == tmp_items->data)
				count++;
			tmp_sa = tmp_sa->next;
		}
		if (count != 1)
			return (FALSE);
		sa = sa->next;
	}
	return (TRUE);
}

void	ps_data_normalization(t_dll *sa)
{
	t_item	*pivot_items;
	t_item	*moving_ptr_items;
	t_dll	*pivot;
	t_dll	*moving_ptr;

	pivot = sa;
	while (pivot != NULL)
	{
		moving_ptr = sa;
		while (moving_ptr != NULL)
		{
			pivot_items = (t_item *)pivot->content;
			moving_ptr_items = (t_item *)moving_ptr->content;
			if (pivot_items->data < moving_ptr_items->data)
				moving_ptr_items->idx++;
			moving_ptr = moving_ptr->next;
		}
		pivot = pivot->next;
	}
}

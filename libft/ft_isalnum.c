/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:49:48 by tajeong           #+#    #+#             */
/*   Updated: 2023/10/06 21:00:32 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (('a' <= uc && uc <= 'z') || \
			('A' <= uc && uc <= 'Z') || \
			('0' <= uc && uc <= '9'))
		return (1);
	return (0);
}
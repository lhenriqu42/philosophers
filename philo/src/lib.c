/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:07:00 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/24 13:16:39 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	ft_atost(const char *nptr)
{
	size_t	i;
	size_t	result;
	int		is_negative;

	i = 0;
	result = 0;
	is_negative = 1;
	while (((nptr[i] >= 9) && (nptr[i] <= 13)) || ((nptr[i]) == 32))
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if ((nptr[i] == '-'))
			is_negative *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	return (result * is_negative);
}

size_t ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

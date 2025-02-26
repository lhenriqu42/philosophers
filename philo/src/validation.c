/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:59:11 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/26 08:00:53 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_bool	ft_validate_args(int ac, char *av[])
{
	int	i;
	int	j;

	if (ac < 5)
		return (handle_error(E_FEW_ARGS));
	if (ac > 6)
		return (handle_error(E_MANY_ARGS));
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (handle_error(E_INVALID_ARGS));
			j++;
		}
		i++;
	}
	return (false);
}

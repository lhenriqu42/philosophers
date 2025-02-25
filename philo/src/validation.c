/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:59:11 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/25 14:42:10 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_validate_args(int ac, char *av[])
{
	int	i;
	int	j;

	if (ac < 5)
		handle_error(E_FEW_ARGS);
	if (ac > 6)
		handle_error(E_MANY_ARGS);
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				handle_error(E_INVALID_ARGS);
			j++;
		}
		i++;
	}
}

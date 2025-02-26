/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:59:11 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/26 13:20:34 by lhenriqu         ###   ########.fr       */
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

t_bool	check_philo_dead(void)
{
	ft_mutex_lock(&get_mutex()->philo_dead);
	if (get_rules()->philo_dead)
	{
		ft_mutex_unlock(&get_mutex()->philo_dead);
		return (true);
	}
	ft_mutex_unlock(&get_mutex()->philo_dead);
	return (false);
}

t_bool	ft_all_eaten(void)
{
	ft_mutex_lock(&get_mutex()->meals);
	if (get_rules()->finished)
	{
		ft_mutex_unlock(&get_mutex()->meals);
		return (true);
	}
	ft_mutex_unlock(&get_mutex()->meals);
	return (false);
}

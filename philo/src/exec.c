/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:00:39 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/26 11:01:40 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_bool	start_philo_task(t_rules *rules)
{
	t_philo	philo;
	size_t	i;

	i = 0;
	while (i < rules->philos_qnt)
	{
		philo = rules->philos[i];
		if (init_thread(philo.thread))
			return (true);
		i++;
	}
	return (false);
}
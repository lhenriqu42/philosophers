/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:39:45 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/26 11:02:42 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_task(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	(void)philo;
	// while (1)
	// {
	// 	philo_take_fork(philo);
	// 	philo_eat(philo);
	// 	philo_sleep(philo);
	// 	philo_think(philo);
	// }
	return (NULL);
}
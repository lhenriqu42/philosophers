/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:30:29 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/26 16:20:51 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "string.h"

void	thread_build(t_thread *thread, t_philo *philo)
{
	thread->fun = &philo_task;
	thread->args = philo;
}

t_bool	init_thread(t_thread thread)
{
	if (pthread_create(&thread.thread, NULL, thread.fun, thread.args))
		return (true);
	return (false);
}

void	*solo_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	print_status(*philo, S_FORK);
	ft_msleep(get_rules()->die_time);
	print_status(*philo, S_DEAD);
	return (NULL);
}

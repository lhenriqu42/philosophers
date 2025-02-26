/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:30:29 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/26 11:04:32 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:39:45 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/28 07:46:59 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_take_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		ft_mutex_lock(philo->forks.right);
		print_status(*philo, S_FORK);
		ft_mutex_lock(philo->forks.left);
		print_status(*philo, S_FORK);
	}
	else
	{
		ft_mutex_lock(philo->forks.left);
		print_status(*philo, S_FORK);
		ft_mutex_lock(philo->forks.right);
		print_status(*philo, S_FORK);
	}
}

static void	philo_eat(t_philo *philo)
{
	print_status(*philo, S_EATING);
	ft_msleep(get_rules()->eat_time);
	ft_mutex_lock(&get_mutex()->meals);
	philo->last_meal = ft_get_time();
	philo->rounds++;
	ft_mutex_unlock(&get_mutex()->meals);
	ft_mutex_unlock(philo->forks.left);
	ft_mutex_unlock(philo->forks.right);
}

static void	philo_sleep(t_philo *philo)
{
	print_status(*philo, S_SLEEPING);
	ft_msleep(get_rules()->sleep_time);
}

static void	philo_think(t_philo *philo)
{
	print_status(*philo, S_THINKING);
	ft_msleep(get_rules()->think_time);
}

void	*philo_task(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->id % 2 == 0)
		ft_msleep(1);
	while (!check_philo_dead())
	{
		if (ft_all_eaten())
			break ;
		philo_take_fork(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

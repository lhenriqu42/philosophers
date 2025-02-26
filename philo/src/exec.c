/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:00:39 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/26 13:48:12 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_bool	is_dead(t_philo philo)
{
	ft_mutex_lock(&get_mutex()->meals);
	if (ft_get_time() - philo.last_meal > get_rules()->die_time)
	{
		ft_mutex_unlock(&get_mutex()->meals);
		print_status(philo, S_DEAD);
		ft_mutex_lock(&get_mutex()->philo_dead);
		get_rules()->philo_dead = true;
		ft_mutex_unlock(&get_mutex()->philo_dead);
		return (true);
	}
	ft_mutex_unlock(&get_mutex()->meals);
	return (false);
}

static size_t	ft_how_many_finished(void)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (i < get_rules()->philos_qnt)
	{
		ft_mutex_lock(&get_mutex()->meals);
		if (get_rules()->philos[i].rounds >= get_rules()->must_eat_times)
			count++;
		ft_mutex_unlock(&get_mutex()->meals);
		i++;
	}
	return (count);
}

static t_bool	all_finished(t_rules *rules)
{
	if (ft_how_many_finished() == rules->philos_qnt)
	{
		ft_mutex_lock(&get_mutex()->meals);
		rules->finished = true;
		ft_mutex_unlock(&get_mutex()->meals);
		return (true);
	}
	return (false);
}

static void	ft_monitor(void)
{
	t_rules	*rules;
	size_t	i;

	rules = get_rules();
	while (1)
	{
		i = 0;
		while ((i < rules->philos_qnt))
		{
			if (is_dead(rules->philos[i]))
				return ;
			if ((all_finished(rules)))
				return ;
			i++;
		}
	}
}

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
	ft_monitor();
	return (false);
}

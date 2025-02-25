/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:18:49 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/25 15:34:22 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_rules(int argc, char *argv[])
{
	t_rules	*rules;

	rules = get_rules();
	rules->philo_dead = false;
	rules->philos_qnt = ft_atost(argv[1]);
	if (rules->philos_qnt < 1)
		handle_error(E_INVALID_PHILOS);
	if (rules->philos_qnt > 200)
		handle_error(E_INVALID_PHILOS);
	rules->die_time = ft_atost(argv[2]);
	rules->eat_time = ft_atost(argv[3]);
	rules->sleep_time = ft_atost(argv[4]);
	if (argc == 6)
		rules->must_eat_times = ft_atost(argv[5]);
	else
		rules->must_eat_times = __SIZE_MAX__;
	rules->philos = ft_malloc(sizeof(t_philo) * rules->philos_qnt);
}

static void	ft_init_forks(t_forks *forks, size_t i)
{
	static t_forks			*first_forks;
	static pthread_mutex_t	*last;

	if (i == 0)
	{
		forks->right = ft_malloc(sizeof(pthread_mutex_t));
		if (ft_mutex_init(forks->right))
		handle_error(E_MUTEX_FAILED);
		last = forks->right;
		first_forks = forks;
	}
	else
	{
		forks->right = ft_malloc(sizeof(pthread_mutex_t));
		if (ft_mutex_init(forks->right))
			handle_error(E_MUTEX_FAILED);
		forks->left = last;
		last = forks->right;
		if (i == get_rules()->philos_qnt - 1)
			first_forks->left = forks->right;
	}
}

void	init_philos(t_rules *rules)
{
	size_t	i;

	i = 0;
	while (i < rules->philos_qnt)
	{
		rules->philos[i].id = i + 1;
		ft_init_forks(&rules->philos[i].forks, i);
		i++;
	}
}

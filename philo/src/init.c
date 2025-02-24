/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:18:49 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/24 15:01:30 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_rules(int argc, char *argv[])
{
	t_rules	*rules;
	size_t	i;

	i = 0;
	rules = get_rules();
	rules->philo_dead = false;
	rules->philos_qnt = ft_atost(argv[1]);
	rules->die_time = ft_atost(argv[2]);
	rules->eat_time = ft_atost(argv[3]);
	rules->sleep_time = ft_atost(argv[4]);
	if (argc == 6)
		rules->must_eat_times = ft_atost(argv[5]);
	else
		rules->must_eat_times = __SIZE_MAX__;
	rules->philos = malloc(sizeof(t_philo) * rules->philos_qnt);
}

static void ft_init_forks(t_forks *forks, size_t i)
{
	static t_forks			*first_forks;
	static pthread_mutex_t	*last;

	forks->left = malloc(sizeof(pthread_mutex_t));
	forks->right = malloc(sizeof(pthread_mutex_t));
	if (i == 0)
	{
		if(pthread_mutex_init(forks->right, NULL))
			handle_error(E_MUTEX_FAILED);
		last = forks->right;
		first_forks = forks;
	}
	else
	{
		if(pthread_mutex_init(forks->right, NULL))
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
		rules->philos[i].forks.left = i;
		rules->philos[i].forks.right = (i + 1) % rules->philos_qnt;
		ft_init_forks(&rules->philos[i].forks, i);
		i++;
	}
}
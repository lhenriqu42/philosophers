/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:44:49 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/27 11:39:55 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_rules	*get_rules(void)
{
	static t_rules	rules;

	return (&rules);
}

t_utils_mutex	*get_mutex(void)
{
	static t_utils_mutex	mutex;

	return (&mutex);
}

static void	print_msg(int id, char *msg)
{
	if (!check_philo_dead())
	{
		ft_mutex_lock(&get_mutex()->print);
		printf(C_WHT C_BLD "%zu " C_RST "%d %s\n", ft_get_time(), id, msg);
		ft_mutex_unlock(&get_mutex()->print);
	}
}

void	print_status(t_philo philo, t_status status)
{
	if (status == S_FORK)
		print_msg(philo.id, C_WHT C_BLD "has taken a fork" C_RST);
	if (status == S_SLEEPING)
		print_msg(philo.id, C_CYA C_BLD "is sleeping" C_RST);
	if (status == S_THINKING)
		print_msg(philo.id, C_BLU C_BLD "is thinking" C_RST);
	if (status == S_EATING)
		print_msg(philo.id, C_YEL C_BLD "is eating" C_RST);
	if (status == S_DEAD)
		print_msg(philo.id, C_RED C_BLD "died" C_RST);
}
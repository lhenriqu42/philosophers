/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:05:33 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/26 10:05:43 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static long long	get_now_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long	ft_get_time(void)
{
	static long long	start_time;

	if (!start_time)
	{
		start_time = get_now_time();
		return (0);
	}
	return (get_now_time() - start_time);
}

void	ft_msleep(long long ms)
{
	usleep(ms * 1000);
}

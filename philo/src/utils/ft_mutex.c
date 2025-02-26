/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 08:19:48 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/25 13:19:41 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mutex.h"

static t_mutex	*get_mutex(void)
{
	static t_mutex	mutex;

	return (&mutex);
}

int	ft_mutex_init(pthread_mutex_t *mutex)
{
	t_mutex	*mtx;

	mtx = get_mutex();
	if (pthread_mutex_init(mutex, NULL) != 0)
	{
		mtx->list[mtx->i] = mutex;
		mtx->i++;
		return (1);
	}
	return (0);
}

void	ft_mutex_destroy_all(void)
{
	t_mutex	*mtx;

	mtx = get_mutex();
	while (mtx->i > 0)
	{
		mtx->i--;
		pthread_mutex_destroy(mtx->list[mtx->i]);
		mtx->list[mtx->i] = NULL;
	}
}

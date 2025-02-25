/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 08:15:58 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/25 09:23:44 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MUTEX_H
# define FT_MUTEX_H

# include <stdlib.h>
# include <pthread.h>

typedef struct s_mutex
{
	pthread_mutex_t *list[1000];
	size_t	i;
}			t_mutex;

int		ft_mutex_init(pthread_mutex_t *mutex);
void	ft_mutex_destroy_all(void);

#endif
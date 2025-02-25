/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:43:15 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/25 14:41:48 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "colors.h"
# include "ft_malloc.h"
# include "ft_mutex.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_bool
{
	false,
	true
}					t_bool;

typedef enum e_error
{
	E_SUCCESS,
	E_FEW_ARGS,
	E_MANY_ARGS,
	E_INVALID_ARGS,
	E_MUTEX_FAILED,
	E_MALLOC_FAILED,
}					t_error;

typedef struct s_custom_mutex
{
	pthread_mutex_t	waiting_for_philo_take_fork;
	pthread_mutex_t	philo_dead_verification;
	pthread_mutex_t	meals_verification;
	pthread_mutex_t	write_rights;
}					t_custom_mutex;

typedef struct s_forks
{
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
}					t_forks;

typedef struct s_philo
{
	int				id;
	t_forks			forks;
}					t_philo;

typedef struct s_rules
{
	size_t			die_time;
	size_t			eat_time;
	size_t			sleep_time;
	size_t			must_eat_times;
	size_t			philos_qnt;
	t_philo			*philos;
	t_bool			philo_dead;
}					t_rules;

// UTILS
t_rules				*get_rules(void);
void				handle_error(t_error error);

// VALIDATE
void				ft_validate_args(int ac, char *av[]);

// LIBFT
size_t				ft_strlen(const char *str);
size_t				ft_atost(const char *nptr);
t_bool				ft_isdigit(int c);

// INIT
void				init_rules(int argc, char *argv[]);
void				init_philos(t_rules *rules);

#endif
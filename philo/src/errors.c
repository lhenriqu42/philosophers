/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:56:57 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/27 08:17:17 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	clear_all(char *error)
{
	ft_free_all();
	ft_mutex_destroy_all();
	write(2, error, ft_strlen(error));
}

static void	print_guide(void)
{
	const char	*usage_guide = "\n " C_CYA C_BLD "Usage:" C_RST
		C_WHT " ./philo " C_RST
		C_CYA C_BLD "[" C_RST "number_of_philosophers" C_CYA C_BLD "] " C_RST
		C_CYA C_BLD "[" C_RST "time_to_die" C_CYA C_BLD "]\n" C_RST
		"\t\t" C_CYA C_BLD "[" C_RST "time_to_eat" C_CYA C_BLD "] " C_RST
		C_CYA C_BLD "[" C_RST "time_to_sleep" C_CYA C_BLD "]\n" C_RST
		"\t\t" C_CYA C_BLD "[" C_RST "times_each_philosopher_must_eat"
		C_CYA C_BLD "] " C_RST	"(optional)\n\n";

	write(2, usage_guide, ft_strlen(usage_guide));
}

void	print_error(char *error)
{
	write(2, C_RED, ft_strlen(C_RED));
	write(2, error, ft_strlen(error));
	write(2, C_RST, ft_strlen(C_RST));
	print_guide();
}

static void	exit_succes(void)
{
	size_t		i;
	pthread_t	thread;

	i = 0;
	while (i < get_rules()->philos_qnt)
	{
		thread = get_rules()->philos[i].thread.thread;
		if (pthread_join(thread, NULL))
			perror("pthread_join");
		i++;
	}
	ft_free_all();
	ft_mutex_destroy_all();
}

t_bool	handle_error(t_error error)
{
	if (error == E_SUCCESS)
		exit_succes();
	if (error == E_INVALID_ARGS)
		print_error("Arguments must be numbers !\n");
	if (error == E_FEW_ARGS)
		print_error("Too few arguments !\n");
	if (error == E_MANY_ARGS)
		print_error("Too many arguments !\n");
	if (error == E_INVALID_PHILOS)
		print_error("Number of philosophers must be between 1 and 200 !\n");
	if (error == E_MUTEX_FAILED)
		clear_all("Mutex failed !\n");
	if (error == E_THREAD_FAILED)
		clear_all("Thread failed !\n");
	if (error == E_MALLOC_FAILED)
		clear_all("Malloc failed !\n");
	return (true);
}

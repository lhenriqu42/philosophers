/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:56:57 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/25 13:29:08 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	clear_all(char *error)
{
	ft_free_all();
	ft_mutex_destroy_all();
	write(2, error, ft_strlen(error));
}

void	print_guide(void)
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

void	handle_error(t_error error)
{
	if (error == E_SUCCESS)
		clear_all("");
	if (error == E_INVALID_ARGS)
		print_error("Invalid arguments !\n");
	if (error == E_MUTEX_FAILED)
		clear_all("Mutex failed !\n");
	if (error == E_MALLOC_FAILED)
		clear_all("Malloc failed !\n");
	exit(error);
}

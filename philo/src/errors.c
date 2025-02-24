/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:56:57 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/24 15:07:28 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "utils.h"

void print_guide()
{
	const char	*usage_guide = \
		"\n " C_CYA C_BLD "Usage:" C_RST C_WHT " ./philo" C_RST
		" " OPEN_SBRACKET "number_of_philosophers" CLOSE_SBRACKET
		" " OPEN_SBRACKET "time_to_die" CLOSE_SBRACKET "\n"
		"\t\t" OPEN_SBRACKET "time_to_eat" CLOSE_SBRACKET
		" " OPEN_SBRACKET "time_to_sleep" CLOSE_SBRACKET "\n"
		"\t\t" OPEN_SBRACKET "times_each_philosopher_must_eat" CLOSE_SBRACKET
		" (optional)\n\n";
	write(2, usage_guide, ft_strlen(usage_guide));
}

void print_error(char *error)
{
	write(2, C_RED, ft_strlen(C_RED));
	write(2, error, ft_strlen(error));
	write(2, C_RST, ft_strlen(C_RST));
	print_guide();
}

void handle_error(t_error error)
{
	if (error == E_INVALID_ARGS)
		print_error("Invalid arguments !\n");
	if (error == E_MUTEX_FAILED)
		clean_all();
	exit(error);
}
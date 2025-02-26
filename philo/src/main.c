/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:24:30 by xluizikax         #+#    #+#             */
/*   Updated: 2025/02/26 16:04:33 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	if (ft_validate_args(argc, argv))
		return (1);
	if (init_rules(argc, argv))
		return (1);
	if (init_philos(get_rules()))
		return (1);
	if (init_utils_mutex(get_mutex()))
		return (1);
	if (start_philo_task(get_rules()))
		return (1);
	handle_error(E_SUCCESS);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:24:30 by xluizikax         #+#    #+#             */
/*   Updated: 2025/02/26 08:00:00 by lhenriqu         ###   ########.fr       */
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
	handle_error(E_SUCCESS);
	return (0);
}

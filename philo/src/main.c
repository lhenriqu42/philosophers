/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:24:30 by xluizikax         #+#    #+#             */
/*   Updated: 2025/02/25 13:58:55 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	ft_validate_args(argc, argv);	
	init_rules(argc, argv);
	init_philos(get_rules());
	handle_error(E_SUCCESS);
}

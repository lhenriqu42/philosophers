/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:38:36 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/24 09:41:22 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		handle_error(E_INVALID_ARGS);
	init_rules(argc, argv);
	init_philos(get_rules());

	handle_error(E_SUCCESS);
}
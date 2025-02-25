/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 07:50:42 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/25 08:54:16 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static t_malloc	*get_malloc(void)
{
	static t_malloc	mlc;

	return (&mlc);
}

void	*ft_malloc(size_t size)
{
	t_malloc	*mlc;
	void		*ptr;

	mlc = get_malloc();
	ptr = malloc(size);
	mlc->list[mlc->i] = ptr;
	mlc->i++;
	return (ptr);
}

void	ft_free_all(void)
{
	t_malloc	*mlc;

	mlc = get_malloc();
	while (mlc->i > 0)
	{
		mlc->i--;
		free(mlc->list[mlc->i]);
		mlc->list[mlc->i] = NULL;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 07:48:05 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/25 08:29:20 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdlib.h>

typedef struct s_malloc
{
	void	*list[1000];
	size_t	i;
}			t_malloc;

void		*ft_malloc(size_t size);
void		ft_free_all(void);

#endif
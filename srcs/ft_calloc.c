/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:27:05 by julcalde          #+#    #+#             */
/*   Updated: 2024/12/15 18:48:19 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	tot_mem;
	void	*p;

	tot_mem = count * size;
	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, tot_mem);
	return (p);
}

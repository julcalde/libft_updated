/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:50:50 by julcalde          #+#    #+#             */
/*   Updated: 2024/12/15 18:49:17 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	size_t	n;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	n = dstsize - dstlen - 1;
	if (n == 0)
		return (ft_strlen(src) + dstsize - 1);
	while (src[i] != '\0' && n != 0)
	{
		dst[dstlen + i] = src[i];
		i++;
		n--;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

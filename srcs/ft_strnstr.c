/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:46:04 by julcalde          #+#    #+#             */
/*   Updated: 2024/12/15 18:49:29 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	ndllen;

	i = 0;
	ndllen = ft_strlen(needle);
	if (ndllen == 0)
		return ((char *) haystack);
	if (*haystack == '\0' || ndllen > len)
		return (NULL);
	while (i <= len - ndllen)
	{
		if (haystack[i] == needle[0])
		{
			if (ft_strncmp(&haystack[i], needle, ndllen) == 0)
				return ((char *) &haystack[i]);
		}
		i++;
	}
	return (NULL);
}

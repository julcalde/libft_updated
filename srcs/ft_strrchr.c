/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:43:43 by julcalde          #+#    #+#             */
/*   Updated: 2024/12/15 18:49:31 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*lc;
	int			i;

	i = 0;
	lc = NULL;
	if ((char)c == '\0')
	{
		while (*s != '\0')
			s++;
		return ((char *) &s[i]);
	}
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			lc = &s[i];
		i++;
	}
	if (s[i] == c)
		return ((char *) &s[i]);
	return ((char *) lc);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:49:01 by julcalde          #+#    #+#             */
/*   Updated: 2024/12/15 18:49:24 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	size_t	s_len;
	char	*new_s;

	s_len = ft_strlen(s);
	new_s = malloc((s_len + 1) * sizeof(char));
	if (new_s == NULL)
		return (NULL);
	i = 0;
	while (i < (int) s_len)
	{
		new_s[i] = (*f)(i, s[i]);
		i++;
	}
	new_s[i] = 0;
	return (new_s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:30:12 by julcalde          #+#    #+#             */
/*   Updated: 2025/01/12 18:38:23 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*new_s1;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (s1 == NULL || set == NULL)
		return ((char *) s1);
	while (s1[i] != '\0' && (ft_strchr(set, s1[i]) != NULL))
		i++;
	while (j > i && (ft_strchr(set, s1[j]) != NULL))
		j--;
	new_s1 = malloc(j - i + 2);
	if (new_s1 == NULL)
		return (NULL);
	new_s1 = ft_memcpy(new_s1, s1 + i, j - i + 1);
	new_s1[j - i + 1] = '\0';
	return (new_s1);
}

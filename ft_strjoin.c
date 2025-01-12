/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:06:04 by julcalde          #+#    #+#             */
/*   Updated: 2025/01/12 18:38:02 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	s1_len;
	size_t	s2_len;
	size_t	c1;
	size_t	c2;

	c1 = 0;
	c2 = 0;
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	while (s1[c1])
		s3[c2++] = s1[c1++];
	c1 = 0;
	while (s2[c1])
		s3[c2++] = s2[c1++];
	s3[c2] = '\0';
	return (s3);
}

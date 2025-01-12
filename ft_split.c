/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:23:48 by julcalde          #+#    #+#             */
/*   Updated: 2025/01/12 18:37:50 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counter(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			while (s[i] && s[i] != c)
				i++;
			counter++;
		}
	}
	return (counter);
}

static void	ft_free(char **str_set)
{
	int	i;

	i = 0;
	while (str_set[i])
	{
		free(str_set[i]);
		i++;
	}
	free(str_set);
}

// static char	*ft_zawarudo(int temp_len, char **str_set, const char *s)
// {
// 	char	*res;

// 	res = malloc(temp_len + 1);
// 	if (res == NULL)
// 		return (ft_free(str_set), NULL);
// 	res = ft_memcpy(res, s, temp_len);
// 	res[temp_len] = '\0';
// 	return (res);
// }

static char	**ft_warudo_arr(const char *s, char c, char **str_set)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		start = i;
		if (s[i])
		{
			while (s[i] && s[i] != c)
				i++;
			str_set[j] = malloc(i - start + 1);
			if (str_set[j] == NULL)
				return (ft_free(str_set), NULL);
			str_set[j] = ft_memcpy(str_set[j], s + start, i - start);
			str_set[j][i - start] = '\0';
			j++;
		}
	}
	str_set[j] = NULL;
	return (str_set);
}

char	**ft_split(char const *s, char c)
{
	char	**str_set;

	if (!s)
		return (NULL);
	str_set = (char **)malloc((counter(s, c) + 1) * sizeof(char *));
	if (str_set == NULL)
		return (NULL);
	str_set[counter(s, c)] = NULL;
	return (ft_warudo_arr(s, c, str_set));
}

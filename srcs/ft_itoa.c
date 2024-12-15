/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:00:08 by julcalde          #+#    #+#             */
/*   Updated: 2024/12/15 18:48:34 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_countd(int n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		counter++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

static char	*checkint(int n)
{
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	return (NULL);
}

char	*ft_itoa(int n)
{
	size_t	s_len;
	char	*s;
	int		i;

	i = 0;
	s_len = ft_countd(n);
	if (n == 2147483647 || n == -2147483648 || n == 0)
		return (checkint(n));
	s = malloc((s_len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	if (n < 0)
	{
		s[i++] = '-';
		n = -n;
	}
	s[s_len] = '\0';
	while ((int) s_len - 1 >= i)
	{
		s[s_len - 1] = (n % 10) + '0';
		n /= 10;
		s_len--;
	}
	return (s);
}

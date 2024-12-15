/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:57:42 by julcalde          #+#    #+#             */
/*   Updated: 2024/12/15 18:35:27 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p(size_t p, int *count)
{
	char		chars[30];
	int			i;
	const char	*b16;

	b16 = "0123456789abcdef";
	i = 0;
	if (ft_s("0x", count) == -1 || (p == 0 && ft_c('0', count) == -1))
		return (-1);
	if (p == 0)
		return (0);
	while (p != 0)
	{
		chars[i] = b16[p % 16];
		p /= 16;
		i++;
	}
	while (i--)
	{
		if (ft_c(chars[i], count) == -1)
			return (-1);
	}
	return (0);
}

int	ft_d_i(int n, int *count)
{
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		(*count) += 11;
		return (0);
	}
	else if (n < 0)
	{
		if (ft_c('-', count) == -1)
			return (-1);
		n *= -1;
		if (ft_d_i(n, count) == -1)
			return (-1);
	}
	else
	{
		if (n > 9)
			if (ft_d_i(n / 10, count) == -1)
				return (-1);
		if (ft_c(n % 10 + '0', count) == -1)
			return (-1);
	}
	return (0);
}

int	ft_u(unsigned int u, int *count)
{
	if (u >= 10)
	{
		if (ft_u(u / 10, count))
			return (-1);
	}
	if (ft_c(u % 10 + '0', count) == -1)
		return (-1);
	return (0);
}

int	ft_lx_ux(unsigned int x, int *count, char lx_ux)
{
	char	chars[30];
	char	*ptr;
	char	*b16;

	b16 = "0123456789abcdef";
	if (lx_ux == 'X')
		b16 = "0123456789ABCDEF";
	ptr = chars;
	if (x == 0)
	{
		if (ft_c('0', count) == -1)
			return (-1);
		return (0);
	}
	while (x)
	{
		*ptr++ = b16[x % 16];
		x /= 16;
	}
	while (ptr-- > chars)
	{
		if (ft_c(*ptr, count) == -1)
			return (-1);
	}
	return (0);
}

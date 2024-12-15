/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:53:05 by julcalde          #+#    #+#             */
/*   Updated: 2024/12/15 18:35:24 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_c(char c, int *count)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	(*count)++;
	return (0);
}

int	ft_s(char *args, int *count)
{
	int	i;

	i = 0;
	if (args == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		(*count) += 6;
		return (0);
	}
	while (args[i] != '\0')
	{
		if (ft_c(args[i], count) == -1)
			return (-1);
		i++;
	}
	return (0);
}

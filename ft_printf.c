/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:13:47 by julcalde          #+#    #+#             */
/*   Updated: 2024/12/15 18:35:29 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Here are the requirements:
• Don’t implement the buffer management of the original printf().
• Your function has to handle the following conversions: cspdiuxX%
*/

static int	format_check(char specifier, va_list *args, int *char_count, int *i)
{
	if (specifier == 'c')
		return (ft_c(va_arg(*args, int), char_count));
	else if (specifier == 's')
		return (ft_s(va_arg(*args, char *), char_count));
	else if (specifier == 'p')
		return (ft_p(va_arg(*args, size_t), char_count));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_d_i(va_arg(*args, int), char_count));
	else if (specifier == 'u')
		return (ft_u(va_arg(*args, unsigned int), char_count));
	else if (specifier == 'x')
		return (ft_lx_ux(va_arg(*args, unsigned int), char_count, 'x'));
	else if (specifier == 'X')
		return (ft_lx_ux(va_arg(*args, unsigned int), char_count, 'X'));
	else if (specifier == '%')
		return (ft_c('%', char_count));
	else
		(*i)--;
	return (-1);
}

int	ft_printf(const char *user_input, ...)
{
	va_list	args;
	int		i;
	int		char_count;

	va_start(args, user_input);
	i = 0;
	char_count = 0;
	while (user_input[i] != '\0')
	{
		if (user_input[i] == '%')
		{
			i++;
			if (format_check(user_input[i], &args, &char_count, &i) == -1)
				return (-1);
			i++;
		}
		else
		{
			if (ft_c((char) user_input[i], &char_count) == -1)
				return (-1);
			i++;
		}
	}
	va_end(args);
	return (char_count);
}

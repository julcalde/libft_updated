/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:55:34 by julcalde          #+#    #+#             */
/*   Updated: 2025/01/12 19:06:13 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *user_input, ...);

int		ft_c(char c, int *count);
int		ft_s(char *args, int *count);

int		ft_d_i(int n, int *count);
int		ft_lx_ux(unsigned int x, int *count, char lx_ux);
int		ft_p(size_t p, int *count);
int		ft_u(unsigned int u, int *count);

#endif
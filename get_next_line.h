/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:50:22 by julcalde          #+#    #+#             */
/*   Updated: 2025/01/12 19:05:39 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
/*
	You will compile your code as follows (a buffer size of 42 is used as an
	example):
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

// Principal function
char	*get_next_line(int fd);

// Helper functions
// char	*line_storage(char	*line, char	*tmp_buffer);
// char	*extract_newline(char *line);
// char	*ex_sa_rest(char **line);

// Utils functions
size_t	ft_gnl_strlen(const char *s);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_strcpy(char *dest, char *src);
char	*ft_gnl_strdup(const char *s1);
char	*ft_gnl_strncpy(char *dest, char *src, unsigned int n);

#endif
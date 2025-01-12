/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:48:58 by julcalde          #+#    #+#             */
/*   Updated: 2025/01/12 18:39:59 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Goal
DESC:	Write a function that returns a line read from a
		file descriptor.
RETURN:	Read line if correct behavior.
		NULL if there is nothing else to read, or an error occurred.
NOTE:	The returned line should include the terminating \n
		character, except if the end of file was reached and
		does not end with a \n character.
NOTE:	Add all the helper functions you need in the get_next_line_utils.c file
*/
/* Read function prototype
int read(int fd, char buffer[], int bytes);
fd:		file descriptor.
buffer:	array where to stock the read chars.
bytes:	number of bytes to read per iteration.
*/

static char	*line_storage(char *line, char *tmp_buffer);
static char	*extract_newline(char *line);
static char	*ex_sa_rest(char **line);

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char		tmp_buffer[BUFFER_SIZE + 1];
	int			read_chunk;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		read_chunk = read(fd, tmp_buffer, BUFFER_SIZE);
		if (read_chunk < 0)
			return (free(line), line = NULL, line);
		tmp_buffer[read_chunk] = '\0';
		line = line_storage(line, tmp_buffer);
		if (!line)
			return (NULL);
		if (ft_gnl_strchr(line, '\n') || read_chunk == 0)
			break ;
	}
	return (ex_sa_rest(&line));
}

// Appends tmp_buffer content to line, handling memory reallocation
static char	*line_storage(char	*line, char	*tmp_buffer)
{
	char	*new_line;
	size_t	line_len;
	size_t	buff_len;

	line_len = 0;
	buff_len = ft_gnl_strlen(tmp_buffer);
	if (line)
		line_len = ft_gnl_strlen(line);
	if (line_len == 0 && buff_len == 0)
		return (NULL);
	new_line = malloc((line_len + buff_len + 1));
	if (!new_line)
		return (NULL);
	if (line)
	{
		ft_gnl_strcpy(new_line, line);
		free(line);
	}
	ft_gnl_strcpy(new_line + line_len, tmp_buffer);
	return (new_line);
}

// Function t extract the '\n' in the 'ex_sa_rest' function
static char	*extract_newline(char *line)
{
	char	*newline_loc;
	size_t	get_to_newline;
	char	*new_storage;

	newline_loc = ft_gnl_strchr(line, '\n');
	if (newline_loc)
		get_to_newline = (size_t)(newline_loc - line + 1);
	else
		get_to_newline = ft_gnl_strlen(line);
	new_storage = malloc((get_to_newline + 1) * sizeof(char));
	if (!new_storage)
		return (NULL);
	ft_gnl_strncpy(new_storage, line, get_to_newline);
	new_storage[get_to_newline] = '\0';
	return (new_storage);
}

// Extracts the current line up to the '\n', saves the leftover data
static char	*ex_sa_rest(char **line)
{
	char	*new_storage;
	char	*rest;

	new_storage = extract_newline(*line);
	if (!new_storage)
		return (NULL);
	if (ft_gnl_strchr(*line, '\n'))
	{
		rest = ft_gnl_strdup(*line + ft_gnl_strlen(new_storage));
		free(*line);
		*line = rest;
	}
	else
	{
		free(*line);
		*line = NULL;
	}
	return (new_storage);
}

// int	main(void)
// {
//  	int fd = open("text.txt", O_RDONLY);
// 		printf("%s", get_next_line(fd));
// 		return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:54:43 by tde-souz          #+#    #+#             */
/*   Updated: 2022/07/12 06:17:09 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	valid_buffer_len(char *buffer)
{
	size_t	len;

	len = 0;
	while (buffer[len] != 0)
		if (buffer[len++] == '\n')
			break ;
	return (len);
}

size_t	write_buffer(char *buffer, int fd)
{	
	ssize_t	bytes_read;

	bytes_read = 0;
	if (*buffer == 0)
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	return (bytes_read);
}

size_t	is_line_ready(char *line)
{
	size_t	i;

	if (line == NULL)
		return (0);
	i = 0;
	while (line[i])
		if (line[i++] == '\n')
			return (1);
	return (0);
}

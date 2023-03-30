/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:54:50 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/12 21:45:58 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*next_line;
	ssize_t		bytes_read;

	if (fd < 0)
		return (NULL);
	next_line = NULL;
	while (is_line_ready(next_line) == 0)
	{	
		bytes_read = write_buffer(buffer, fd);
		if (bytes_read <= 0 && *buffer == 0)
			break ;
		if (next_line == 0)
			next_line = build_line(buffer);
		else
			next_line = append_line(next_line, buffer);
		offset_buffer(buffer);
	}
	return (next_line);
}

char	*build_line(char *buffer)
{
	char	*ret;
	size_t	blen;
	size_t	i;

	i = 0;
	blen = valid_buffer_len(buffer);
	ret = (char *)malloc(sizeof(char) * (blen + 1));
	if (ret == NULL)
		return (NULL);
	while (i < blen)
	{
		ret[i] = buffer[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	*append_line(char *line, char *buffer)
{
	char	*ret;
	size_t	blen;
	size_t	i;

	i = 0;
	blen = valid_buffer_len(buffer);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(line) + blen + 1));
	if (ret == NULL)
		return (NULL);
	while (line[i])
	{
		ret[i] = line[i];
		i++;
	}
	while (blen--)
	{
		ret[i] = *buffer++;
		i++;
	}
	ret[i] = 0;
	free(line);
	return (ret);
}

void	offset_buffer(char *buffer)
{
	size_t	i;
	size_t	blen;

	i = 0;
	blen = valid_buffer_len(buffer);
	while (buffer[i + blen])
	{
		buffer[i] = buffer[i + blen];
		i++;
	}
	while (buffer[i])
		buffer[i++] = 0;
}

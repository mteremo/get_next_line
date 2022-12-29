/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matavare <matavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:12:50 by matavare          #+#    #+#             */
/*   Updated: 2022/12/29 15:06:47 by matavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

	line = 0;
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		gnl_strjoin(line, buffer);
		gnl_buffer_clear(buffer);
	}
	return (line);
}

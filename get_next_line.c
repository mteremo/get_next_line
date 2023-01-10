/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matavare <matavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:12:50 by matavare          #+#    #+#             */
/*   Updated: 2023/01/10 16:26:10 by matavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			i;
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

	i = 0;
	line = 0;
	if (buffer[i])
		line = gnl_strchange(line, buffer);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = gnl_strchange(line, buffer);
		if (gnl_newline(buffer) == 1)
			return (line);
	}
	return (line);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		printf("\n");
		free(str);
		str = get_next_line(fd);
	}
	free(str);
}

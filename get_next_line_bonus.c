/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matavare <matavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:16:01 by matavare          #+#    #+#             */
/*   Updated: 2023/01/13 16:24:35 by matavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	int			i;
	int			j;
	int			flag;
	char		*line;
	static char	buffer[fd][BUFFER_SIZE + 1];

	line = NULL;
	flag = 0;
	while (!flag && (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0))
	{
		line = gnl_strjoin(line, buffer);
		i = 0;
		j = 0;
		while (buffer[i])
		{
			if (flag == 1)
				buffer[fd][j++] = buffer[i];
			if (buffer[fd][i] == '\n')
				flag = 1;
			buffer[fd][i++] = 0;
		}
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
		//printf("\n");
		free(str);
		str = get_next_line(fd);
	}
	free(str);
}

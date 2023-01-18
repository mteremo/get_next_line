/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matavare <matavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:34:50 by matavare          #+#    #+#             */
/*   Updated: 2023/01/18 14:59:49 by matavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			i;
	int			j;
	int			flag;
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

	line = NULL;
	flag = 0;
	while (!flag && !(read(fd, 0, 0) < 0) && \
			(buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0))
	{
		line = gnl_strjoin(line, buffer);
		i = 0;
		j = 0;
		while (buffer[i])
		{
			if (flag == 1)
				buffer[j++] = buffer[i];
			if (buffer[i] == '\n')
				flag = 1;
			buffer[i++] = 0;
		}
	}
	return (line);
}

/* int	main(void)
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
 */
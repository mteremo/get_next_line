/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matavare <matavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:16:01 by matavare          #+#    #+#             */
/*   Updated: 2023/01/18 15:09:45 by matavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	int			i;
	int			j;
	int			flag;
	char		*line;
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	flag = 0;
	while (!flag && (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0))
	{
		line = gnl_strjoin(line, buffer[fd]);
		i = 0;
		j = 0;
		while (buffer[fd][i])
		{
			if (flag == 1)
				buffer[fd][j++] = buffer[fd][i];
			if (buffer[fd][i] == '\n')
				flag = 1;
			buffer[fd][i++] = 0;
		}
	}
	return (line);
}

/* int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*str1;
	char	*str2;
	char	*str3;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("teeeeeee.txt", O_RDONLY);
	fd3 = open("tt.txt", O_RDONLY);
	str1 = get_next_line(fd1);
	str2 = get_next_line(fd2);
	str3 = get_next_line(fd3);
	while (str1)
	{
		printf("%s", str1);
		free(str1);
		str1 = get_next_line(fd1);
	}
	free(str1);
	while (str2)
	{
		printf("%s", str2);
		free(str2);
		str2 = get_next_line(fd2);
	}
	free(str2);
	while (str3)
	{
		printf("%s", str3);
		free(str3);
		str3 = get_next_line(fd3);
	}
	free(str3);
} */
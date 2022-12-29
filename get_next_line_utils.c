/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matavare <matavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:58:19 by matavare          #+#    #+#             */
/*   Updated: 2022/12/29 15:09:03 by matavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char *line, char *buffer)
{
	int	il;
	int	ib;
	int	new_len;

	il = gnl_strlen(line);
	if (il != 0)
		il--;
	ib = 0;
	new_len = il + gnl_strlen(buffer);
	line = (char *)malloc(sizeof(char) * (new_len + 1));
	if (!line)
		return (0);
	while (buffer[ib] && buffer[ib] != '\n')
	{
		line[il] = buffer[ib];
		il++;
		ib++;
	}
	return (line);
}

char	*gnl_buffer_clear(char *buffer)
{
	int	i;
	int	ii;

	i = 0;
	ii = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		buffer[i] = '\0';
		i++;
		if (buffer[i] == '\n')
		{
			buffer[i] = '\0';
			i++;
			while (buffer[i] != '\0')
			{
				buffer[ii] = buffer[i];
				buffer[i] = 0;
				i++;
				ii++;
			}
		}
	}
	return (buffer);
}

int	gnl_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
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
		free(str);
		str = get_next_line(fd);
	}
	free(str);
}

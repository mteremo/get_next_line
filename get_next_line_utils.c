/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matavare <matavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:58:19 by matavare          #+#    #+#             */
/*   Updated: 2023/01/09 14:48:18 by matavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char *line, char *buffer)
{
	int		il;
	int		ib;
	int		new_len;

	il = 0;
	ib = 0;
	new_len = gnl_strlen(buffer);
	line = (char *)malloc(sizeof(char) * (new_len + 1));
	if (!line)
		return (0);
	while (buffer[ib])
	{
		line[ib] = buffer[ib];
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matavare <matavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:58:19 by matavare          #+#    #+#             */
/*   Updated: 2023/01/10 16:31:10 by matavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strchange(char *line, char *buffer)
{
	int		i;
	int		ii;
	int		new_len;
	char	*new_line;

	i = 0;
	ii = 0;
	new_len = gnl_strlen(buffer) + gnl_strlen(line);
	new_line = (char *)malloc(sizeof(char) * (new_len + 1));
	if (!new_line)
		return (0);
	while (line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	while (buffer[ii] != '\n' && buffer[ii])
	{
		new_line[i] = buffer[ii];
		i++;
		ii++;
		if (buffer[ii] == '\n')
		{
			new_line[i] = buffer[ii];
			i++;
			ii++;
		}
	}	
	gnl_buffer_move(buffer, ii);
	return (new_line);
}

char	*gnl_buffer_move(char *buffer, int i)
{
	int	ii;

	ii = 0;
	while (buffer[i])
	{
		buffer[ii] = buffer[i];
		i++;
		ii++;
	}
	buffer[ii] = '\0';
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

int	gnl_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matavare <matavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:16:05 by matavare          #+#    #+#             */
/*   Updated: 2023/01/13 16:18:23 by matavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_strjoin(char *line, char *buffer)
{
	char	*new_line;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = gnl_strlen(line) + gnl_strlen(buffer);
	new_line = (char *)malloc(sizeof(char) * (len + 3));
	if (!new_line)
		return (0);
	if (line)
	{
		while (line[j])
			new_line[i++] = line[j++];
	}
	j = 0;
	while (buffer[j] && buffer[j] != '\n')
		new_line[i++] = buffer[j++];
	if (buffer[j] == '\n')
		new_line[i++] = buffer[j++];
	new_line[i] = 0;
	free(line);
	return (new_line);
}

int	gnl_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matavare <matavare@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:09:50 by matavare          #+#    #+#             */
/*   Updated: 2023/01/10 16:32:00 by matavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*gnl_strchange(char *line, char *buffer);
char	*gnl_buffer_move(char *buffer, int i);
int		gnl_strlen(char *str);
int		gnl_newline(char *line);

#endif

// gcc -o app get_next_line.c get_next_line_utils.c
// ./app
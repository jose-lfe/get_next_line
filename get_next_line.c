/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-lfe <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:28:17 by jose-lfe          #+#    #+#             */
/*   Updated: 2023/12/13 14:51:17 by jose-lfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_line(char *buffer, char *line);
static int	ft_strlen(char *s);
char	*get_next_line(int fd)
{
	char	*line;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (find_line(buffer, line) != 1)
	{
		read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE - 1] = '\0';
	}
	return (line);
}

static int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	find_line(char *buffer, char *line)
{
	int		i;
	int		j;
	char	*stock;

	i = 0;
	stock = malloc((ft_strlen(buffer)))
}

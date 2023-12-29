/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-lfe <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:39:30 by jose-lfe          #+#    #+#             */
/*   Updated: 2023/12/29 14:40:57 by jose-lfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_check_line(char *stach);
void	*ft_calloc(size_t count, size_t size);
void	ft_free(char *buffer, char *stach, int end);
char	*ft_strjoin(char *s1, char *s2);

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*res;
	static char	*stach;
	int			end;

	end = BUFFER_SIZE;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (ft_check_line(stach) == 1 && end == BUFFER_SIZE)
	{
		end = read(fd, buffer, BUFFER_SIZE);
		if (end <= 0)
		{
			ft_free(buffer, stach, end);
			return (NULL);
		}
		stach = ft_strjoin(stach, buffer);
	}
	res = ft_substr(stach, 0, ft_strlen(stach));
	ft_free(buffer, stach, end);
	return (res);
}

int	ft_check_line(char *stach)
{
	int	i;

	i = 0;
	if (stach != NULL && stach[0] != '\0')
	{
		while (stach[i] != '\0')
		{
			if (stach[i] == '\n')
				return (0);
			i++;
		}
	}
	return (1);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = (void *)malloc(count * size);
	if (!tmp)
		return (NULL);
	while (i < count * size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}

void	ft_free(char *buffer, char *stach, int end)
{
	char	*tmp;

	if (end <= 0)
	{
		free(buffer);
		free(stach);
	}
	else
	{
		tmp = stach;
		stach = ft_substr(tmp, ft_strlen(stach), BUFFER_SIZE);
		free(buffer);
		free(tmp);
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		j;
	int		i;
	char	*res;

	i = 0;
	if (s1 == NULL)
		return (ft_strdup(s2));
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	while (s1 && s1[j] != '\0')
		res[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j] != '\0' && s2[j] != '\n')
		res[i++] = s2[j++];
	if (s2[j] == '\n')
		res[i++] = s2[j++];
	res[i] = '\0';
	if (s1)
		free(s1);
	return (res);
}

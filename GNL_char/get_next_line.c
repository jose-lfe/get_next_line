/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-lfe <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:39:30 by jose-lfe          #+#    #+#             */
/*   Updated: 2024/01/09 13:21:38 by jose-lfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_check_line(char *stach);
void	*ft_calloc(size_t count, size_t size);
char	*ft_free(char *stach, int end);
char	*ft_strjoin(char *s1, char *s2);

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*res;
	static char	*stach;
	int			end;

	end = BUFFER_SIZE;
	while (ft_check_line(stach) == 1 && end > 0)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
		end = read(fd, buffer, BUFFER_SIZE);
		if (end > 0)
		{
			stach = ft_strjoin(stach, buffer);
		}
		free(buffer);
	}
	res = ft_substr(stach, 0, ft_strlen(stach));
	stach = ft_free(stach, end);
	if (end >= 0)
		return (res);
	free(res);
	return (NULL);
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

char	*ft_free(char *stach, int end)
{
	if (end <= 0)
	{
		free(stach);
		return (NULL);
	}
	else
	{
		stach = ft_substr(stach, ft_strlen(stach), BUFFER_SIZE);
		return (stach);
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
	res = malloc((ft_strlen_true(s1) + ft_strlen_true(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	while (s1 && s1[j] != '\0')
		res[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	if (s1)
		free(s1);
	return (res);
}

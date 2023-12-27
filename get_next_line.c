/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-lfe <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:28:17 by jose-lfe          #+#    #+#             */
/*   Updated: 2023/12/27 11:05:02 by jose-lfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_check_n(t_list *lst);
char	*ft_fill(t_list *moustache);
void	ft_free_moustache(t_list *moustache);
void	*ft_calloc(size_t count, size_t size);

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*line;
	static t_list	*moustache;
	int				fin;

	fin = BUFFER_SIZE;
	while (fin == BUFFER_SIZE || ft_check_n(ft_lstlast(moustache)) == 1)
	{
		buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!buffer)
			return (NULL);
		fin = read(fd, buffer, BUFFER_SIZE);
		if (fin < 0)
		{
			free(buffer);
			return (NULL);
		}
		ft_lstadd_back(&moustache, ft_lstnew(buffer));
	}
	line = ft_fill(moustache);
	free(buffer);
	ft_free_moustache(moustache);
	return (line);
}

void	ft_free_moustache(t_list *moustache)
{
	t_list	*tmp_t;
	int		i;
	int		j;
	char	*tmp_c;

	while (moustache->next)
	{
		tmp_t = moustache->next;
		free(moustache->content);
		free(moustache);
		moustache = tmp_t;
	}
	i = 0;
	while (moustache->content[i] != '\0')
		i++;
	j = ft_strlen(moustache->content);
	tmp_c = ft_calloc((i + 1 - j), sizeof(char));
	while (i > j)
	{
		tmp_c[(i) - j -1] = moustache->content[i - 1];
		i--;
	}
	free(moustache->content);
	moustache->content = tmp_c;
}

/*
void	ft_free_moustache(t_list *moustache)
{
	t_list	*tmp_t;
	char	*tmp_c;
	int		i;
	int		j;
	char	*res;

	while (moustache->next)
	{
		tmp_t = moustache->next;
		tmp_c = moustache->content;
		free(tmp_c);
		free(moustache);
		moustache = tmp_t;
	}
	i = 0;
	while (moustache->content[i] != '\0')
		i++;
	j = ft_strlen(moustache->content);
	tmp_c = ft_calloc((i + 1 - j), sizeof(char));
	while (i > j)
		tmp_c[(i--) - j -1] = moustache->content[i - 1];
	res = moustache->content;
	free(res);
	moustache->content = tmp_c;
}
*/
/*	tmp_c = moustache->content;
	while (tmp_c[i] != '\0' || tmp_c[i] != '\n')
		i++;
	if (tmp_c[i] == '\0');
	{
		free(tmp_c);
		free(moustache);
	}*/

int	ft_check_n(t_list *lst)
{
	char	*check;
	int		i;

	i = 0;
	check = lst->content;
	if (check != NULL && check[0] != '\0')
	{
		while (check[i] != '\0')
		{
			if (check[i] == '\n')
				return (0);
			i++;
		}
	}
	return (1);
}

char	*ft_fill(t_list *moustache)
{
	char	*line;
	t_list	*tmp;

	tmp = moustache;
	while (tmp)
	{
		line = ft_strjoin(line, tmp->content);
		tmp = tmp->next;
	}
	return (line);
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
/*
char	*ft_fill(t_list *moustache)
{
	char	*res;
	char	*line;
	int		i;
	char	*tmp;

	while (moustache->next)
	{
		line = ft_strjoin(line, moustache->content);
		moustache = moustache->next;
	}
	tmp = moustache->content;
	while (tmp[i] != '\0' || tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i++;
	res = malloc((ft_strlen(line) + i) * sizeof(char));
	if (!res)
		return (NULL);
	while (line)
		*res = *line;
	
	free(line);
	return (res);
}
*/

/*
int	find_line();

char	*get_next_line(int fd)
{
	char	*line;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);
	return (line);
}
*/
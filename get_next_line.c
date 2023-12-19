/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-lfe <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:28:17 by jose-lfe          #+#    #+#             */
/*   Updated: 2023/12/12 14:02:18 by jose-lfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_n(t_list *lst);
char	*ft_fill(t_list *moustache);

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*line;
	static	t_list	*moustache;
	int				fin;

	fin = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE - 1] = '\0';
	while (fin != 0 || ft_check_n(ft_lstlast(moustache)) == 1)
	{
		fin = read(fd, buffer, BUFFER_SIZE);
		if (fin < 0)
			return (NULL);
		ft_lstadd_back(moustache, ft_lstnew(buffer)); // exemple : hello , world , stp\nd
	}
	line = ft_fill(moustache);
	free(buffer);
	moustache = ft_free_moustache(*moustache); // transforme la derniere perle en la premiere
	return (line);
}

int    ft_check_n(t_list *lst)
{
    char    *check;

    check = lst->content;
    while (*check)
    {
        if (*check == '\n')
            return (0);
        check++;
    }
    return (1);
}

char	*ft_fill(t_list *moustache)
{
	char	*res;
	char	*line;
	int		i;
	char	*tmp;
	//t_list	*tmp;

	//tmp = moustache;
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
	return (res);
}

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
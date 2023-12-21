/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-lfe <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:28:17 by jose-lfe          #+#    #+#             */
/*   Updated: 2023/12/19 16:28:30 by jose-lfe         ###   ########.fr       */
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
	while (fin != BUFFER_SIZE || ft_check_n(ft_lstlast(moustache)) == 1)
	{
		buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!buffer)
			return (NULL);
		fin = read(fd, buffer, BUFFER_SIZE);
		if (fin < 0)
			return (NULL);
		ft_lstadd_back(moustache, ft_lstnew(buffer)); // exemple : hello , world , stp\nd
		free (buffer);
	}
	line = ft_fill(moustache);
	free(buffer);
	ft_free_moustache(moustache); // transforme la derniere perle en la premiere
	return (line);
}

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
	tmp_c = calloc((i + 1 - j), sizeof(char));
	while (i > j)
		tmp_c[(i--) - j -1] = moustache->content[i - 1];
	res = moustache->content;
	free(res);
	moustache->content = tmp_c;
}
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
    unsigned char	*tmp; // on déclare une string sur un pointeur temporaire
    size_t			i; // on déclare un index

    i = 0; // on initialise l'index à 0
    tmp = (void *)malloc (count * size); // on alloue de la mémoire au pointeur en void de la taille du compte multiplié par la taille
    if (!tmp) // si le pointeur n'existe pas, qu'il n'y a rien dedans
        return (NULL); // on retourne NULL
    while (i < count * size) // tant que l'index est plus petit que le compte fois la taille
    {
        tmp[i] = 0; // alors on met 0 à la place de l'index
        i++; // et on continue d'incrémenter l'index
    }
    return (tmp); // on retourne enfin la string temporaire
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
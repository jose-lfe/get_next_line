/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-lfe <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:38:07 by jose-lfe          #+#    #+#             */
/*   Updated: 2024/01/03 15:33:18 by jose-lfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		ft_check_line(char *stach);
void	*ft_calloc(size_t count, size_t size);
char	*ft_free(char *buffer, char *stach, int end);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *s);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strdup(const char *s1);

#endif
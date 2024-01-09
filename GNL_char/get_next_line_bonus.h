/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-lfe <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:52:43 by jose-lfe          #+#    #+#             */
/*   Updated: 2024/01/09 14:42:52 by jose-lfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		ft_check_line(char *stach);
void	*ft_calloc(size_t count, size_t size);
char	*ft_free(char *stach, int end, char *res);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen_true(const char *s);
int		ft_strlen(const char *s);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(const char *s1);

#endif
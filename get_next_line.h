/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-cham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:47:08 by ade-cham          #+#    #+#             */
/*   Updated: 2020/10/08 15:19:14 by ade-cham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE	32
# endif

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);

int		get_next_line(int fd, char **line);

#endif

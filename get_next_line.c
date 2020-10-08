/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-cham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:38:02 by ade-cham          #+#    #+#             */
/*   Updated: 2020/10/08 15:35:43 by ade-cham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_find_n(char *save)
{
	int		i;

	i = 0;
	if (!save)
		return (0);
	while (save[i] != '\0')
	{
		if (save[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_line(char *save, char	**line, int i)
{
	char	*temp;

	if (!save)
		return (NULL);
	save[i] = '\n';
	*line = ft_strdup(save);
	temp = ft_strdup(save + i + 1);
	free(save);
	save = temp;
	free(temp);
	return (save);
}

char	*get_last_line(char *save, char** line, int i, int reader)
{
	char	*temp;

	if (reader == 0 && i != -1)
	{
		save[i] = '\0';
		*line = ft_strdup(save);
		temp = ft_strdup(save + i + 1);
		free(save);
		save = temp;
		free(temp);
		return (save);
	}
	else if (reader == 0)
	{
		*line = ft_strdup(save);
		free(save);
		save = NULL;
		return (save);
	}
	return (save);
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		buf[BUFFER_SIZE + 1];
	int 		i;
	int 		reader;

	save = NULL;
	i = 0;
	if (fd > 0 || !line || BUFFER_SIZE < 0)
		return (-1);
	while ((reader = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (!save)
			save = ft_strdup(buf);
		else
		{
			buf[reader] = '\0';
			save = ft_strjoin(save, buf);
			i = ft_find_n(save);
			if (i >= 0)
			{
				save = get_line(save, line, i);
				return (1);
			}
			save = get_last_line(save, line, i, reader);
			return (0);
		}	
		return (0);
	}
	return (0);
}

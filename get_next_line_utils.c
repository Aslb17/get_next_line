/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-cham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 11:45:53 by ade-cham          #+#    #+#             */
/*   Updated: 2020/10/08 16:20:55 by ade-cham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t		i;
	char		*dest;

	if (!s1)
		return (0);
	i = ft_strlen((char *)s1);
	if (!(dest = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	free((char *)s1);
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len_s1;
	unsigned int	len_s2;
	unsigned int	i;
	unsigned int	j;
	char			*s3;

	i = 0;
	j = 0;
	if (s1 == NULL)
		len_s1 = 0;
	else
		len_s1 = ft_strlen((char *)s1);
		len_s2 = ft_strlen((char *)s2);
	if (!(s3 = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	while (i < len_s1)
	{
		s3[i] = s1[i];
		i++;
	}
	while (j < len_s2)
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free((char *)s1);
	return (s3);
}

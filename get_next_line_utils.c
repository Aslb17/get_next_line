/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-cham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 11:45:53 by ade-cham          #+#    #+#             */
/*   Updated: 2020/10/07 16:39:49 by ade-cham         ###   ########.fr       */
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
//	free((char *)s1);
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	unsigned int	i;
	unsigned int	j;
	char			*s3;

	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(s3 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[j] != '\0')
		s3[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free((char *)s1);
	return (s3);
}

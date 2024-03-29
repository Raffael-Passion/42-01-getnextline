/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhortens <rhortens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:41:21 by rhortens          #+#    #+#             */
/*   Updated: 2023/02/07 18:25:48 by rhortens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*backup;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	backup = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!backup)
		return (0);
	while (s1[i])
	{
		backup[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		backup[i] = s2[j];
		i++;
		j++;
	}
	backup[i] = '\0';
	return (backup);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)str + i);
		else
			i++;
	}
	if (str[i] == (unsigned char)c)
	{
		return ((char *)str + i);
	}
	return (0);
}

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	counter;

	i = 0;
	counter = 0;
	while (src[counter] != '\0')
	{
		counter++;
	}
	if (size != 0)
	{
		while (src[i] != '\0' && size - 1 > i)
		{
			dest[i] = src[i];
			i++;
		}
		dest [i] = '\0';
	}
	return (counter);
}

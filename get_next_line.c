/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhortens <rhortens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:18:16 by rhortens          #+#    #+#             */
/*   Updated: 2022/12/06 17:49:48 by rhortens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	*check_new_line(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(str, 1);
	while (i < j)
	{
		if (str[i] == '\n')
			return (1);
	}
	return (0);
}

char	*ft_line(int fd,char *str)
{
	char	*buffer;
	int		i;

	str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	i = 1;
	while (i)
	{
		if (check_new_line(str))
		{
			free(buffer);
			return (str);
		}
		i = read(fd, buffer, BUFFER_SIZE);
		buffer[i] = 0;
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;

	if (fd < 0)
		return (NULL);
	str = ft_line(fd, str);
	if (!str)
		return (NULL);
	
}
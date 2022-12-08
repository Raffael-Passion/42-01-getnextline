/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhortens <rhortens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:18:16 by rhortens          #+#    #+#             */
/*   Updated: 2022/12/08 17:18:48 by rhortens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* int	*check_new_line(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(str);
	while (i < j)
	{
		if (str[i] == '\n')
			return (1);
	}
	return (0);
}*/

char	*next_line(char *str)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	j = ft_strlen(str);
	if (!str[j])
	{
		free(str);
		return (NULL);
	}
	next = malloc(ft_strlen(str) - j + 1);
	if (!next)
		return (NULL);
	ft_strlcpy(next, str, ft_strlen(str) + 1);
	next[i] = '\0';
	free(str);
	return (next);
}

char	*break_line(char *str)
{
	int		i;
	char	*tmp;

	if (!*str)
		return (NULL);
	i = 0;
	tmp = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, str, ft_strlen(str) + 1);
	if (str[i] == '\n')
		tmp[i++] = '\n';
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_line(int fd, char *str)
{
	char	*buffer;
	char	*tmp;
	int		i;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	i = 1;
	while (i > 0 && !ft_strchr(str, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			if (str)
				free(str);
			free(buffer);
			return (NULL);
		}
		buffer[i] = 0;
		tmp = ft_strjoin(str, buffer);
		free(str);
		tmp = str;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = ft_line(fd, str);
	if (!str)
		return (NULL);
	line = break_line(str);
	str = next_line(str);
	return (line);
}

/*
int	main(void)
{
	int		fd;
	char	*solution;

	
}
*/
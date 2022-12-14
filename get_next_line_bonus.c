/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhortens <rhortens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:41:25 by rhortens          #+#    #+#             */
/*   Updated: 2022/12/14 20:18:35 by rhortens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
For the bonus part of get_next_line you must use just one static variable. 
I already did that in the main part, so the functions and the logic itself are almost identically.
Also the project should manage multiple file descriptors at the same time. 
This can be ensured through some small changes in the get_next_line.
I therefor added a double pointer to my static char. 
The array now contains the max size of file descriptors and ensures that everything can relate
to the belonged file descriptor.
*/

char	*next_line(char *str)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	next = malloc(sizeof(char) * ft_strlen(str) - i + 1);
	if (!next)
		return (NULL);
	i++;
	while (str[i])
		next[j++] = str[i++];
	next[j] = '\0';
	free(str);
	return (next);
}

char	*break_line(char *str)
{
	int		i;
	char	*tmp;

	if (!(*str))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	tmp = malloc(sizeof(char) * (i + 2));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, str, i + 1);
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

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	i = 1;
	while (!ft_strchr(str, '\n') && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			if (str)
				free(str);
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		tmp = ft_strjoin(str, buffer);
		free(str);
		str = tmp;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (str[fd] == NULL)
	{
		str[fd] = malloc(sizeof(char) * 1);
		if (!str[fd])
			return (NULL);
		str[fd][0] = '\0';
	}
	str[fd] = ft_line(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = break_line(str[fd]);
	str[fd] = next_line(str[fd]);
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*solution;

	fd = open("test.txt", O_RDONLY);
	solution = get_next_line(fd);
	printf("%s", solution);
	free(solution);
	solution = get_next_line(fd);
	printf("%s", solution);
	free(solution);
	solution = get_next_line(fd);
	printf("%s", solution);
	free(solution);
	solution = get_next_line(fd);
	printf("%s", solution);
	free(solution);
	solution = get_next_line(fd);
	printf("%s", solution);
	free(solution);
	solution = get_next_line(fd);
	printf("%s", solution);
	free(solution);
	close(fd);
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhortens <rhortens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:41:25 by rhortens          #+#    #+#             */
/*   Updated: 2022/12/11 18:42:03 by rhortens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (str == NULL)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	str = ft_line(fd, str);
	if (!str)
		return (NULL);
	line = break_line(str);
	str = next_line(str);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhortens <rhortens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:18:16 by rhortens          #+#    #+#             */
/*   Updated: 2023/07/24 17:20:13 by rhortens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
get_next_line shall read the text file pointed to by the file descriptor, one line at a time.
After that the line should be returned. If there is nothing to read or an error -> NULL
The function is reading from a file or from the stdinput (0) -> fd < 0
The returned line should also include '\n' except if the end of the file and does not
end with '\n'.
The function does still work if the BUFFER_SIZE value is 9999, 1 or 10000000. 
This is because the memory gets allocated with (sizeof(char) * BUFFER_SIZE + 1). So it changes dynamically.
*/

/*
next_line is called to assign str to the value of the next_line, if there is any.
integer i gets incremented to the length of str. if there is no str[i], str gets freed and NULL returned.
after that memory for next gets allocated with sizeof(char) *ft_strlen(str) - i + 1. protection checked.
then i gets incremented again. it enters the while loop if (str[i]). then next[j] = str[i], while both
integers get incremented. in the end the '\0' is appended to next[j].
after that str gets freed and next gets returned.
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

/*
the break_line function is called to copy the string str to tmp and then return tmp.
first the protection gets checked. after assigning int i to 0, a while loop is entered to increment i.
memory for tmp is allocated with sizeof(char) * (i + 2). +2 because to get enough memory allocated.
after that ft_strlcpy copies str to tmp up to the size of i + 1.
if str contains and '\n' at the end, it will also be added to tmp.
after that '\0' shall also be appended at the end of tmp. tmp will be returned.
*/

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
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(tmp, str, i + 1);
	if (str[i] == '\n')
		tmp[i++] = '\n';
	tmp[i] = '\0';
	return (tmp);
}

/*
in ft_line(fd, str) at first allocates memory with (sizeof(char) * (BUFFER_SIZE + 1)), then protection.
int i is assigned to 1. The while loop is entered if !ft_strchr(str, '\n' && i > 0).
ft_strchr searches for the first occurence of '\n' in the given string and returns a pointer to it.
in the while loop, i = read(...) with file decriptor to read from, into the buffer with BUFFER_SIZE.
if read is interrupted by a signal before it reads any data, it returns -1. Everything should be freed.
after reading the '\0' will get attached to the buffer. tmp is assigned to ft_strjoin(str, buffer).
ft_strjoin returns a new string which is the result of the concatenation of str and buffer.
after that, str should be freed and then get assigned back to tmp. also free buffer.
so in the end this functions returns str.
*/

char	*ft_line(int fd, char *str)
{
	char	*buffer;
	char	*tmp;
	int		i;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(str);
		return (NULL);
	}
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

/*
the static char *str is used. also a char *line is used to print out the line.
at first the function gets protected and checks the input.
if str == NULL, memory gets allocated and the '\0' ist attached to str[0].
other than that, ft_line gets called with (fd, str).
after that line = break_line and str = next_line gets called.
in the end line will be returned.
*/

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
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

#include <fcntl.h>

int	main(void)
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
}

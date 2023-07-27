/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhortens <rhortens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:18:20 by rhortens          #+#    #+#             */
/*   Updated: 2023/07/24 17:19:50 by rhortens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>


char			*get_next_line(int fd);
size_t			ft_strlen(const char *str);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_line(int fd, char *str);
char			*break_line(char *str);
char			*next_line(char *str);
char			*ft_strchr(const char *str, int c);
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);

#endif
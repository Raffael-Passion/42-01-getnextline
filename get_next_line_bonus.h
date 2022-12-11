/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhortens <rhortens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:43:04 by rhortens          #+#    #+#             */
/*   Updated: 2022/12/11 18:43:49 by rhortens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_FILE_DESCRIPTOR
#  define MAX_FILE_DESCRIPTOR 4096
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
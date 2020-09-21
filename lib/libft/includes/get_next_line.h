/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:57:10 by nlafarge          #+#    #+#             */
/*   Updated: 2020/05/26 12:04:12 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "unistd.h"
# include <stdlib.h>

# include <fcntl.h>
# include <stdio.h>

# define BUFFER_SIZE 1000

int		get_next_line(int fd, char **line);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		cpy_last_line(int ret, char **line, char *rest);
void	ft_place(char *rest, char *tmp);

#endif

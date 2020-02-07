/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:58:51 by mravily           #+#    #+#             */
/*   Updated: 2019/11/27 19:24:21 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int			get_next_line(int fd, char **line);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *s);
void		*ft_memcpy(void *dest, const void *src, size_t n);
size_t		ft_strlen(const char *s);

#endif

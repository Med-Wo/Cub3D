/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:54:30 by mravily           #+#    #+#             */
/*   Updated: 2020/03/04 16:54:34 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		check_backslash_n(char *buf, char *rest)
{
	size_t			i;
	size_t			len_rest;

	i = 0;
	len_rest = 0;
	if (rest[0] == '\n')
		return (len_rest);
	while (rest[len_rest] != '\n' && rest[len_rest])
		len_rest++;
	while (buf[i] || rest[len_rest] == '\n')
	{
		if (buf[i] == '\n' || rest[len_rest] == '\n')
			return (len_rest);
		i++;
	}
	return (-1);
}

int				cpy_lastline(char **line, char *rest)
{
		*line = ft_strdup(rest);
		if (*line == NULL)
			return (-1);
		free(rest);
		rest = NULL;
		return (0);
}

int				return_value_ruler(int return_value)
{
	if (return_value == 1)
		return (1);
	if (return_value == 0)
		return (0);
	else
		return (-1);

}

int				get_next_line_brother(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*rest = NULL;
	int				i[2];
	char			*tmp;

	while ((i[1] = read(fd, buf, BUFFER_SIZE)) > 0 || i[0] != -1)
	{
		buf[i[1]] = '\0';
		rest = ft_strjoin(rest, buf);
		if (rest == NULL)
			return (-1);
		i[0] = check_backslash_n(buf, rest);
		if (i[0] >= 0)
		{
			rest[i[0]] = '\0';
			*line = ft_strdup(rest);
			tmp = ft_strdup(rest + (i[0] + 1));
			if (*line == NULL || tmp == NULL)
				return (-1);
			free(rest);
			rest = tmp;
			return (1);
		}
	}
	return (return_value_ruler(cpy_lastline(line, rest)));
}

int				get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	return (return_value_ruler(get_next_line_brother(fd, line)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_shot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 17:30:58 by mravily           #+#    #+#             */
/*   Updated: 2020/05/29 14:53:24 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		set_int_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

static int		write_bmp_header(int fd, int filesize, t_engine *engine)
{
	int				i;
	int				tmp;
	unsigned char	bmpfileheader[54];

	i = 0;
	while (i < 54)
		bmpfileheader[i++] = (unsigned char)(0);
	bmpfileheader[0] = (unsigned char)('B');
	bmpfileheader[1] = (unsigned char)('M');
	set_int_in_char(bmpfileheader + 2, filesize);
	bmpfileheader[10] = (unsigned char)(54);
	bmpfileheader[14] = (unsigned char)(40);
	tmp = engine->config->resolution.x;
	set_int_in_char(bmpfileheader + 18, tmp);
	tmp = engine->config->resolution.y;
	set_int_in_char(bmpfileheader + 22, tmp);
	bmpfileheader[26] = (unsigned char)(1);
	bmpfileheader[28] = (unsigned char)(24);
	return (!(write(fd, bmpfileheader, 54) < 0));
}

static int		get_color_bmp(t_engine *engine, int x, int y)
{
	int	color;

	color = *(int*)(engine->image->addr + (4
		* (int)engine->config->resolution.x *
				((int)engine->config->resolution.y - 1 - y)) + (4 * x));
	return (color);
}

static int		write_bmp_data(int file, t_engine *engine)
{
	int					i;
	int					j;
	int					color;

	i = 0;
	while (i < (int)engine->config->resolution.y)
	{
		j = 0;
		while (j < (int)engine->config->resolution.x)
		{
			color = get_color_bmp(engine, j, i);
			if (write(file, &color, 3) < 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int				screen_shot(t_engine *engine)
{
	int			filesize;
	int			file;

	filesize = 54 + (3 * (int)engine->config->resolution.x
		* (int)engine->config->resolution.y);
	if ((file = open("screenshot.bmp"
		, O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0644)) < 0)
		return (0);
	if (!write_bmp_header(file, filesize, engine))
		return (0);
	if (!write_bmp_data(file, engine))
		return (0);
	close(file);
	return (1);
}

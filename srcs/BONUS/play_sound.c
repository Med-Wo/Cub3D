/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_sound.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 02:58:40 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 16:12:04 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			play_sound(char *file_name)
{
	char	command[256];
	int		status;

	wait_time(1);
	sprintf(command, "afplay %s", file_name);
	status = system(command);
	return (status);
}

void		sound_put_on_helmet(t_helmet *helmet)
{
	static int		i = 0;

	if (i == 1)
	{
		if (helmet->put_helmet == 0 && helmet->id_part_helmet == 18)
		{
			play_sound("./sound/UDVTPUT.wav");
			play_sound("./sound/UDVTBEP.wav");
			helmet->put_helmet += 1;
		}
	}
	if (i != 1)
		i++;
}

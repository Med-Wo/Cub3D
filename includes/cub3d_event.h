/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_event.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 16:20:11 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 10:12:54 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_EVENT_H
# define CUB3D_EVENT_H

# include <stdbool.h>

typedef struct	s_event
{
	bool		start;
	bool		open_map;
	bool		run;
	bool		forward;
	bool		backward;
	bool		left;
	bool		right;
	bool		rotate_left;
	bool		rotate_right;
	bool		shoot_left;
	bool		shoot_right;
	bool		fuck;
	bool		fuck_right;
	bool		fuck_left;
}				t_event;

t_event			create_event(void);
t_event			*malloc_event(void);
void			free_event(t_event *to_free);

#endif

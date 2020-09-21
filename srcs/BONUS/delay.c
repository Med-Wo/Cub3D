/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delay.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 03:11:44 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 16:54:45 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Function qui permet de generer un temps d'attente
*/

void		delay(int number_of_seconds)
{
	int			milli_seconds;
	clock_t		start_time;

	milli_seconds = 1000 * number_of_seconds;
	start_time = clock();
	while (1)
	{
		if (clock() > start_time + milli_seconds)
			break ;
	}
}

/*
** Function qui permets de boucler pendant le temps indiquer
*/

void		wait_time(int numbers_of_seconds)
{
	int		i;

	i = 0;
	while (i < numbers_of_seconds)
	{
		delay(1);
		i++;
	}
}

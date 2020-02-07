/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 01:58:49 by mravily           #+#    #+#             */
/*   Updated: 2020/02/07 16:35:56 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void		init_appli(t_appli *appli)
{
	appli->vars->mlx_ptr = mlx_init();
	appli->vars->win_ptr = mlx_new_window(appli->vars->mlx_ptr,
		appli->config->resolution_size.x, appli->config->resolution_size.y,
		appli->config->title);

	appli->data->img = mlx_new_image(appli->vars->mlx_ptr, appli->config->resolution_size.x, appli->config->resolution_size.y);
	appli->data->addr = mlx_get_data_addr(appli->data->img,
		&appli->data->bits_per_pixel, &appli->data->line_length,
		&appli->data->endian);
}

int     handle_input_key(int key, void *params)
 {
	t_appli 	*appli;
	int 		radius;

	appli = (t_appli *)params;
	radius = appli->player->rad_play;
	if (key == ESC_KEY)
	 	close_cub(appli);
	if (key == W_KEY || key == S_KEY || key == A_KEY || key == D_KEY)
	{
		if (appli->event->map == true)
			move_player_on_map(key, appli);
		// else if (appli->event->test == true)
		// 	move_test(key, appli);
	}
	if (key == T_KEY)
	{
		if (appli->event->test == false)
		{
			appli->event->test = true;
			destroy_n_birth(appli);
			draw_circle(appli, appli->player->test, 10, create_color(0, 0, 255));
			draw_line(appli, appli->player->test,
				create_vector(appli->player->test.x, appli->player->test.y + 50),
				create_color(0, 0, 255));
		}
		if (appli->event->test == true)
		{
			appli->event->test = false;
			destroy_n_birth(appli);
		}
	}
	if (key == M_KEY)
	{
		if (appli->event->map == false)
		{
			appli->event->map = true;
			draw_map(appli);
			appli->player->dir = create_vector((radius - 1) * cos(degree_to_radiant(appli->player->dir_angle)) + appli->player->pos_map.x, -(radius + 1) * sin(degree_to_radiant(appli->player->dir_angle)) + appli->player->pos_map.y);
			printf("player.pos_map.x = %f\n", appli->player->pos_map.x);
			printf("player.pos_map.y = %f\n", appli->player->pos_map.y);
			printf("player.dir.x = %f\n", appli->player->dir.x);
			printf("player.dir.y = %f\n", appli->player->dir.y);
			draw_circle(appli, create_vector(appli->player->pos_map.x,
					appli->player->pos_map.y), radius, create_color(0, 0, 255));
			draw_line(appli, appli->player->pos_map, appli->player->dir,
					create_color(0, 0, 0));

		}
		else if (appli->event->map == true)
		{
			appli->event->map = false;
			destroy_n_birth(appli);
		}
		printf("event_map : %s\n", (appli->event->map == true ? "true" : "false"));
		printf("event_len_pixel : %s\n", (appli->event->len_pixel == true ? "true" : "false"));
	}
 	return (0);
 }

int		refresh_image(t_appli *appli)
{
	mlx_put_image_to_window(appli->vars->mlx_ptr, appli->vars->win_ptr,
		appli->data->img, 0, 0);
	return (0);
}

void	parsing_cub(t_appli *appli)
{
	int x;
	int y;
	char *map[] =
	 {
		 "1111111111111111111111111",
		 "1000000000000000000000001",
		 "1000000000000000000000001",
		 "1000000000000000000000001",
		 "1000000000000000000000001",
		 "1000000000000000000000001",
		 "1000000000000000000000001",
		 "1000000000000000000000001",
		 "1000000000000000000000001",
		 "1000000000000000000000001",
		 "1111111111100011111111111",
		 "1100000011000001111101111",
		 "1111011111110111111101111",
		 "1111011111110010110000001",
		 "1100000111000000110000001",
		 "1000000011000000110000001",
		 "1000000011111110111000101",
		 "1000000011111111111101001",
		 "1100000111000111111000111",
		 "1000000010000011010101001",
		 "1000000000000000000000001",
		 "1000000010000011010101001",
		 "1100000111000111111000111",
		 "1100000111000111111000111",
		 "1111111111111111111111111",
		 ""

		// "11111111111111111111111111111",
		// "10000000001100000000000000001",
		// "10110000011100000020000010001",
		// "10010000000000000000000010001",
		// "10110000011100000000000010001",
		// "10000000001100000111011110001",
		// "11110111111111011100000010001",
		// "11110111111111011101010010001",
		// "11000000110101011100000010001",
		// "10002000000000001100000010001",
		// "10000000000000001101010010001",
		// "11000000110101011111011110N01",
		// "11110111111101011111011110001",
		// "11111111111111111111111111111",
		// ""
	};
	appli->config->resolution_size = create_vector((int)640, (int)480);
	appli->player->pos = create_vector(5, 5);
	appli->player->pos_map = create_vector(27, 12);
	appli->player->dir_angle = 90.0f;
	appli->player->dir = create_vector(cos(degree_to_radiant(appli->player->dir_angle)) + appli->player->pos_map.x, sin(degree_to_radiant(appli->player->dir_angle)) + appli->player->pos_map.y);
	appli->player->test = create_vector(300, 300);
	appli->config->north_texture = "./textures/xpm/MARBLE3.xpm";
	appli->config->south_texture = "./textures/xpm/MARBLE3.xpm";
	appli->config->west_texture = "./textures/xpm/MARBLE3.xpm";
	appli->config->east_texture = "./textures/xpm/MARBLE3.xpm";
	appli->config->sprite_texture = "./textures/xpm/MARBFACE.xpm";
	appli->texture_path = "./textures/xpm/WELCOME.xpm";
	appli->config->floor =  create_color(220, 100, 0);
	appli->config->ceiling = create_color(225, 30, 0);
	// printf("set_pos.x = %f\n", appli->player->pos.x);
	// printf("set_pos.y = %f\n", appli->player->pos.y);
	x = 0;
	y = 0;
	while (map[y][x])
		y++;
	appli->config->map = (char **)malloc(sizeof(char *) * (y + 1));
	appli->config->map[y] = NULL;
	while (--y >= 0)
		appli->config->map[y] = ft_strdup(map[y]);
}

int 	main(void)
{
	 t_appli 	appli;
	 char		*title;

	 /*     CREATION ALL STRUCT   */
	 title = "Daaaaaaammmm !!!!!";
	 appli.vars = malloc_vars();
	 appli.data = malloc_data();
	 appli.player = malloc_player(0, 0);
	 appli.config = malloc_config(title);
	 appli.event = malloc_event();
	 //appli.texture = malloc_texture();



	 /*   PARSING MAP   */
	 parsing_cub(&appli);

		/*   INIT APPLI   */
		init_appli(&appli);

	// t_texture *tmp = malloc_texture(appli.texture_path);
	// draw_texture(&appli, tmp, create_vector(0, appli.config->resolution_size.y / 2.5), create_vector(appli.config->resolution_size.x, appli.config->resolution_size.y / 5));

	 /*  DRAW BACKGROUND */
	 //draw_rectangle(&appli, create_vector(0, 0), create_vector(appli.config->resolution_size.x, appli.config->resolution_size.y), create_color(0, 100, 0));

	 /*   DRAW MAP  */
	//draw_map(&appli);

	/*	  CATCH EVENT KEY PRESS  */
	mlx_hook(appli.vars->win_ptr, 2, 0, handle_input_key, &appli);

	/*  CATCH EVENT KEY RELEASE  */
	//mlx_hook(appli.vars->win_ptr, 3, 0, handle_key_release, &appli);

	/*   EXIT GAME WITH ESC_KEY   */
	mlx_hook(appli.vars->win_ptr, 17, 0, close_cub, &appli);

	render(&appli);

	// printf("player.pos_map.x = %f\n", appli.player->pos_map.x);
	// printf("player.pos_map.y = %f\n", appli.player->pos_map.y);
	// printf("player.dir.x = %f\n", appli.player->dir.x);
	// printf("player.dir.y = %f\n", appli.player->dir.y);
	// draw_line(&appli, create_vector(300, 300), appli.player->dir, create_color(0, 0, 255));


	// appli.data->img =  mlx_xpm_file_to_image(appli.vars->mlx_ptr,
 	// 	appli.texture->path, &appli.texture->width, &appli.texture->height);
	// appli.data->addr = mlx_get_data_addr(appli.data->img,
	// 	&appli.data->bits_per_pixel, &appli.data->line_length,
	//  	&appli.data->endian);

	// mlx_put_image_to_window(appli.vars->mlx_ptr, appli.vars->win_ptr,
	//  		appli.data->img, 0, 0);

	// draw_line(&appli, create_vector(300, 300), create_vector(300, 400), create_color(0, 0, 255));
	// draw_line(&appli, create_vector(280, 300), create_vector(320, 300), create_color(255, 0, 0));
	//mlx_key_hook(appli.vars->win_ptr,render_next_frame,&appli);
	//draw_rectangle(&appli, create_vector(0, 12), create_vector(10, 10), create_color(255, 0, 0));
	//mlx_hook(appli.vars->win_ptr, 3, 0, refresh_image, &appli);

	mlx_loop_hook(appli.vars->mlx_ptr, refresh_image, &appli);
	mlx_loop(appli.vars->mlx_ptr);

	return (0);
}

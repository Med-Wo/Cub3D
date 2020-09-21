/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:57:48 by mravily           #+#    #+#             */
/*   Updated: 2020/05/29 14:57:19 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit_cub(char *line, char *str, char *message)
{
	ft_putstr_fd("Error:\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[\"", 2);
	ft_putstr_fd(line, 2);
	ft_putstr_fd("\"] <- ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	exit(0);
}

int		exit_cub(void)
{
	ft_putstr("\nClosing the Cub3D application without error\n");
	exit(EXIT_SUCCESS);
}

int		exit_screen_shot(t_engine *engine)
{
	ft_putstr("A screen_shot was taken\n");
	free_engine(engine);
	exit(EXIT_SUCCESS);
}
static void		do_save(t_engine *engine)
{
	if (engine->config->save == true)
	{
		render_game(engine);
		if (screen_shot(engine) == 0)
			error_exit_cub("Screen_shot", "During the screen_shot", "Check Function");
		exit_screen_shot(engine);
	}
}

void	render_game(t_engine *engine)
{
	if (engine->player->health != 0)
	{
		/* Algo du Raycasting */
		raycasting(engine);
		if (engine->event->start == false)
			/* Ecran de demarrage */
			start_screen(engine);
		else
		{
			/* Animation mise en place du casque */
			put_on_the_helmet(engine);
		}
	}
	else
	{
		clear_screen(engine);
		game_over_screen(engine);
	}
	render_screen(engine);
}

/* Initialisation des structures bonus */
void 	engine_bonus(t_engine *engine)
{
	int			width_welcome;
	int 		height_welcome;
	
	width_welcome = engine->config->resolution.x;
	height_welcome = engine->config->resolution.y;
	/* Creation d'une image pour le start_screen */
	engine->bonus->img_welc = malloc_img_welc(engine, width_welcome
		, height_welcome);
	engine->bonus->helmet = malloc_helmet(engine);
	engine->bonus->weapon = malloc_weapon(engine);
}

int 	main(int argc, char **argv)
{

	t_engine 	*engine;

	/* Creation de l'engine */
	engine = malloc_engine("Cub3D (c)");
	
	/* Initialisation de l'appli */
	open_appli(engine);
	
	/* Verification du fichier .cub */
	pre_check_file(engine, argc, argv);
	parsing_cub(argv[1], engine);

	/* Debug Parsing */
	//print_parsing_cub(engine->config, engine->player);
	
	/* Mise au bonne dimension fourni par le fichier .cub */
	resize_appli(engine);
		
	if (!(engine->sprite_cast->z_buffer = malloc(sizeof(float *)
		* engine->config->resolution.x + 1)))
			error_exit_cub("", "malloc z_buffer failed", "");
	
	/* Initialisation de la structure bonus de Cub3D */
	engine_bonus(engine);

	/* Catch des events keyboard */
	appli_key_hook(engine, KEYPRESS, &handle_key_pressed, (void *)engine);
	appli_key_hook(engine, KEYRELEASE, &handle_key_release, (void *)engine);
	
	/* Update le player */
	appli_update(engine, &update_player, (void *)engine);

	/* Quitte le jeu des que l'utilisateur clique sur la croix rouge */
	application_add_exit_control(engine, DESTROYNOTIFY, &exit_cub);
	
	do_save(engine);
	
	run_appli(engine);
	
	return (0);
}

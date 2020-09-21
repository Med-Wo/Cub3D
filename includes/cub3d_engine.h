/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_engine.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:19:49 by mravily           #+#    #+#             */
/*   Updated: 2020/05/27 18:51:42 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ENGINE_H
# define CUB3D_ENGINE_H

# include "cub3d_vars.h"
# include "cub3d_image.h"
# include "cub3d_player.h"
# include "cub3d_config.h"
# include "cub3d_event.h"
# include "cub3d_ray_cast.h"
# include "cub3d_sprite_cast.h"
# include "cub3d_bonus.h"

typedef struct	s_engine
{
	t_vars			*vars;
	t_image			*image;
	t_ray_cast		*ray_cast;
	t_sprite_cast	*sprite_cast;
	t_player		*player;
	t_config		*config;
	t_event			*event;
	t_bonus			*bonus;
}				t_engine;

void			init_engine(t_engine *engine);
t_engine		create_engine(char *title);
t_engine		*malloc_engine(char *title);
void			destroy_engine(t_engine to_destroy);
void			free_engine(t_engine *to_free);
void			raycasting(t_engine *engine);
void			render_game(t_engine *engine);
t_texture		*malloc_texture(t_engine *engine, char *path);
t_texture		create_texture(t_engine *engine, char *path);
void			init_image(t_engine *engine, t_image *image
	, int width, int height);
char			**init_tab_path_helmet_tex(void);
t_helmet		create_helmet(t_engine *engine);
t_helmet		*malloc_helmet(t_engine *engine);
void			free_helmet(t_helmet *to_free);
t_img_hlmt		create_img_hlmt(t_engine *engine, int width, int height);
t_img_hlmt		*malloc_img_hlmt(t_engine *engine, int width, int height);
void			free_img_hlmt(t_img_hlmt *to_free);
t_helmet_tex	create_helmet_tex(t_engine *engine, char *path);
t_helmet_tex	*malloc_helmet_tex(t_engine *engine, char *path);
void			destroy_helmet_tex(t_helmet_tex to_destroy);
void			my_mlx_pixel_put_hlmt(t_img_hlmt *img_hlmt, int x, int y
	, t_color color);
t_color			hlmt_get_color(t_helmet_tex *helmet, int x, int y);
void			draw_hlmt_texture(t_engine *engine, int nb, t_vector coord
	, t_vector size);
void			put_on_the_helmet(t_engine *engine);
t_img_welc		create_img_welc(t_engine *engine, int width, int height);
t_img_welc		*malloc_img_welc(t_engine *engine, int width, int height);
t_welcome_tex	create_welcome_tex(t_engine *engine, char *path);
t_welcome_tex	*malloc_welcome_tex(t_engine *engine, char *path);
void			draw_welcome_texture(t_engine *engine, t_welcome_tex *welcome
	, t_vector coord, t_vector size);
void			my_mlx_pixel_put_welcome(t_engine *engine, int x, int y
	, t_color color);
void			start_screen(t_engine *engine);
void			render_welcome(t_engine *engine);
t_mini_map		create_mini_map(t_engine *engine, int width, int height);
t_mini_map		*malloc_mini_map(t_engine *engine, int width, int height);
void			my_mlx_pixel_put_on_mini_map(t_mini_map *mini_map, int x
	, int y, t_color color);
void			draw_rectangle_on_mini_map(t_engine *engine, t_vector coord
	, t_vector size, t_color color);
void			draw_circle_on_mini_map(t_engine *engine, t_vector coord
	, int radius, t_color color);
void			draw_line_on_mini_map(t_engine *engine, t_vector start
	, t_vector end, t_color color);
void			set_player_map_2d(t_engine *engine, int call);
void			draw_player(t_engine *engine, int call);
void			draw_fov(t_engine *engine, int call);
void			render_map(t_engine *engine, int call);
void			floor_casting(t_engine *engine, int height, int x);
void			sprite_casting(t_engine *engine);
void			calculate_sprite(t_sprite_cast *sprite_cast, t_config *config
	, int i);
void			draw_sprite(t_engine *engine, int i);
bool			is_not_wall_sprite(t_vector index, char **map);
void			simple_move(t_player *player, t_event *event
	, float mov_speed, char **world_map);
void			diagonal_movement(t_player *player, t_event *event
	, float mov_speed, char **world_map);
void			draw_ath_texture(t_engine *engine, int nb, t_vector coord
	, t_vector size);
void			render_ath(t_engine *engine);
void			compteur_shield(t_engine *engine);
void			compteur_health(t_engine *engine);
void			draw_blue_shield(t_engine *engine);
void			draw_green_shield(t_engine *engine);
void			draw_health(t_engine *engine);
t_weapon		*malloc_weapon(t_engine *engine);
t_weapon_tex	create_weapon_tex(t_engine *engine, char *path);
void			draw_weapon_texture(t_engine *engine, int nb, t_vector coord
	, t_vector size);
void			fuck(t_engine *engine);
void			melee(t_engine *engine);
void			mini_gun_firing(t_engine *engine, t_vector pos, t_vector size);
void			mini_gun(t_engine *engine);
void			weapon(t_engine *engine);
void			game_over_screen(t_engine *engine);
void 			init_tex_x(t_sprite_cast *sprite_cast, t_config *config
	, int stripe, int i);
void 			init_tex_y(t_sprite_cast *sprite_cast, t_config *config
	, int draw_start_y, int i);
int				screen_shot(t_engine *engine);
void			event_pressed_bonus(int key, t_engine *engine);
void		pre_check_file(t_engine *engine, int argc, char **argv);
#endif

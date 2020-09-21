/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 01:55:36 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 19:14:33 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <time.h>

# include "cub3d_floor_cast.h"

# define HELMET_PART 17
# define ATH_PART 45
# define WEAPON_PART 20

typedef struct	s_welcome_tex
{
	void		*img;
	char		*path;
	char		*addr;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_welcome_tex;

typedef t_welcome_tex	t_weapon_tex;
typedef t_welcome_tex	t_helmet_tex;
typedef t_welcome_tex	t_ath_tex;

typedef struct	s_helmet
{
	int					put_helmet;
	int					id_part_helmet;
	t_img_hlmt			*img_hlmt;
	t_helmet_tex		helmet_part[HELMET_PART];
	t_ath_tex			ath_part[ATH_PART];
}				t_helmet;

typedef struct	s_weapon
{
	int					part_mini_gun;
	t_weapon_tex		weapon[WEAPON_PART];
}				t_weapon;

typedef	struct	s_bonus
{
	t_floor_cast		*floor_cast;
	t_mini_map			*mini_map;
	t_img_welc			*img_welc;
	t_helmet			*helmet;
	t_weapon			*weapon;
}				t_bonus;

char			**init_tab_path_ath_tex(void);
t_bonus			create_bonus(t_ray_cast *ray_cast);
t_bonus			*malloc_bonus(t_ray_cast *ray_cast);
void			destroy_bonus(t_bonus to_destroy);
void			free_bonus(t_bonus *to_free);
int				play_sound(char *filename);
void			delay(int number_of_seconds);
void			wait_time(int numbers_of_seconds);
void			sound_put_on_helmet(t_helmet *helmet);
void			calculate_other_sprite_height(t_sprite_cast *sprite_cast
	, t_config *config, int i);
void			calculate_other_sprite_width(t_sprite_cast *sprite_cast
	, t_config *config, int i);
char			**init_tab_path_weapon_tex(void);
void			destroy_weapon_tex(t_weapon_tex to_destroy);
void			free_weapon(t_weapon *to_free);
void			re_set_dir_player(int key, t_player *player, t_event *event);
bool 			is_shield_sprite(t_config *config, t_player *player, int i);
bool			is_medkit_sprite(t_config *config, t_player *player, int i);
bool 			is_backpack_sprite(t_config *config, t_player *player, int i);
bool 			is_weapon_sprite(t_config *config, t_player *player, int i);
void			get_item(t_player *player, t_config *config, int i);
void			hit_by_enemy(t_player *player);
#endif

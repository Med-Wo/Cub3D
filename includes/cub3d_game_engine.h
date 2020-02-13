#ifndef CUB3D_GAME_ENGINE_H
#define CUB3D_GAME_ENGINE_H

#define CEILING 0
#define FLOOR 1

typedef struct		s_game_engine
{
	t_image			**texture;
	t_image			*sprite;

	t_color			*ceiling;
	t_color			*floor;

	t_tile			*empty_tile;
	t_tile			*wall_tile;

	t_list			*map_content;
	struct s_map	*map;
	struct s_actor	*player;
}					t_game_engine;

t_game_engine create_game_engine();
bool set_texture_image(t_game_engine *engine, t_direction dir, char *path);
bool set_sprite_image(t_game_engine *engine, char *path);
bool set_color_type(t_game_engine *engine, int type, char *content);
bool is_engine_full(t_game_engine *engine);
void parse_game_engine();
#endif

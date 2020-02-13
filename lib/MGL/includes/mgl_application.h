#ifndef MGL_APPLICATION_H
#define MGL_APPLICATION_H

typedef int (*t_key_funct)(int key, void *param);
typedef int (*t_render_funct)(void *param);

typedef struct	s_application
{
	char		*title;
	void		*mlx_ptr;
	void		*win_ptr;
	t_vector2	size;
	t_image		*image;
}				t_application;

void start_application(int size_x, int size_y, char *title);
void close_application();
void clear_application(t_color color);
void render_application();
int run_application();
void render_funct_application(t_render_funct funct, void *param);
void add_interaction_to_application(int event, t_key_funct funct, void *param);
void resize_application(int size_x, int size_y);

#endif

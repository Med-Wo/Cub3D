#include "mgl.h"

t_application *g_app;

void start_application(int size_x, int size_y, char *title)
{
	g_app = malloc(sizeof(t_application));
	if (g_app == NULL)
		error_exit(1, "Can't malloc a t_applciation");

	g_app->title = ft_strdup(title);
	g_app->mlx_ptr = mlx_init();
	g_app->size = create_vector2(size_x, size_y);
	g_app->win_ptr = mlx_new_window(g_app->mlx_ptr, g_app->size.x, g_app->size.y, title);
	g_app->image = malloc_image(g_app->size.x, g_app->size.y);
}

void close_application()
{
	free_image(g_app->image);
	mlx_destroy_window(g_app->mlx_ptr, g_app->win_ptr);
	free(g_app);
	exit(0);
}

void clear_application(t_color color)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < (size_t)(g_app->size.x))
	{
		j = 0;
		while (j < (size_t)(g_app->size.y))
		{
			put_pixel(g_app->image, i, j, color);
			j++;
		}
		i++;
	}
}

void render_application()
{
	mlx_put_image_to_window(g_app->mlx_ptr, g_app->win_ptr, g_app->image->img_ptr, 0, 0);
}

void render_funct_application(t_render_funct funct, void *param)
{
	mlx_loop_hook(g_app->mlx_ptr, funct, param);
}

void add_interaction_to_application(int event, t_key_funct funct, void *param)
{
	mlx_hook(g_app->win_ptr, event, 0, funct, param);
}

int run_application()
{
	mlx_loop(g_app->mlx_ptr);
	return (0);
}

void resize_application(int size_x, int size_y)
{
	free_image(g_app->image);
	mlx_destroy_window(g_app->mlx_ptr, g_app->win_ptr);

	g_app->size = create_vector2(size_x, size_y);
	g_app->win_ptr = mlx_new_window(g_app->mlx_ptr, g_app->size.x, g_app->size.y, g_app->title);
	g_app->image = malloc_image(g_app->size.x, g_app->size.y);
}

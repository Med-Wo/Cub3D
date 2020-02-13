#ifndef LIBFT_VECTOR_H
# define LIBFT_VECTOR_H

typedef struct	s_vector2
{
	float	x;
	float	y;
}				t_vector2;

t_vector2		create_vector2(int p_x, int p_y);
t_vector2		create_vector2f(float p_x, float p_y);
t_vector2		*malloc_vector2(int p_x, int p_y);
t_vector2		*malloc_vector2f(float p_x, float p_y);
void			swap_t_vector2(t_vector2 *a, t_vector2 *b);
bool			is_t_vector2_equal(t_vector2 a, t_vector2 b);
float			distance_vector2(t_vector2 a, t_vector2 b);
t_vector2		add_vector2_to_vector2(t_vector2 a, t_vector2 b);
t_vector2		substract_vector2_to_vector2(t_vector2 a, t_vector2 b);
t_vector2		mult_vector2_by_vector2(t_vector2 a, t_vector2 b);
t_vector2		divide_vector2_by_vector2(t_vector2 a, t_vector2 b);

#endif

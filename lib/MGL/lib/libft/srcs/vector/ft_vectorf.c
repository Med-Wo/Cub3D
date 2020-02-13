#include "libft.h"

t_vector2	create_vector2f(float p_x, float p_y)
{
	t_vector2 result;

	result.x = p_x;
	result.y = p_y;
	return (result);
}

t_vector2	*malloc_vector2f(float p_x, float p_y)
{
	t_vector2	*result;

	result = (t_vector2 *)malloc(sizeof(t_vector2));
	if (result == NULL)
		error_exit(111, "Can't malloc a t_vector2");
	*result = create_vector2(p_x, p_y);
	return (result);
}

#include "libft.h"

t_vector2	add_vector2_to_vector2(t_vector2 a, t_vector2 b)
{
	return (create_vector2f(a.x + b.x, a.y + b.y));
}

t_vector2	substract_vector2_to_vector2(t_vector2 a, t_vector2 b)
{
	return (create_vector2f(a.x - b.x, a.y - b.y));
}

t_vector2	mult_vector2_by_vector2(t_vector2 a, t_vector2 b)
{
	return (create_vector2f(a.x * b.x, a.y * b.y));
}

t_vector2	divide_vector2_by_vector2(t_vector2 a, t_vector2 b)
{
	if (b.x == 0 || b.y == 0)
		error_exit(1, "Can't divide a vector2 by 0");
	return (create_vector2f(a.x / b.x, a.y / b.y));
}

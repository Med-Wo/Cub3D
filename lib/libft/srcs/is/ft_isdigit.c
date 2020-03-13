#include "libft.h"

bool	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (false);
	return (true);
}

bool	ft_strisdigit(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

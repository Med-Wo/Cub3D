#include "libft.h"

bool	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (true);
	return (false);
}

bool	ft_strisalnum(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalnum(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

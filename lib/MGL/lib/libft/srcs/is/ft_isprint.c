#include "libft.h"

bool	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (true);
	return (false);
}

bool	ft_strisprint(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isprint(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

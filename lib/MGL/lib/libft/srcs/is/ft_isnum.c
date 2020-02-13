#include "libft.h"

bool	ft_isnum(int c)
{
	if ((c < '0' || c > '9') && c != '-' && c != '+')
		return (false);
	return (true);
}

bool	ft_strisnum(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isnum(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

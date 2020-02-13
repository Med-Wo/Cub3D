#include "libft.h"

bool	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (true);
	return (false);
}

bool	ft_strisascii(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isascii(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

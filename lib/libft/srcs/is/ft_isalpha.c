#include "libft.h"

bool	ft_isalpha(int c)
{
	if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
		return (false);
	return (true);
}

bool	ft_strisalpha(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

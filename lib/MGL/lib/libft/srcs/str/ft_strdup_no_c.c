#include "libft.h"

char *ft_strdup_no_c(char *str, char c)
{
	size_t i;
	size_t j;
	char *result;

	result = ft_strnew(ft_strlen(str));
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			result[j] = str[i];
			j++;
		}
		i++;
	}
	result[j] = str[i];
	return (result);
}

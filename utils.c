#include "so_long.h"

void	error_messager(int result)
{
	if (result != 1)
		printf("Error\n");
	if (result % 3 == 0)
		printf("***The map must contain exactly one starting point(P).\n");
	if (result % 5 == 0)
		printf("***The map must contain exactly one exit point(E).\n");
	if (result % 7 == 0)
		printf("***The map must be rectangular.\n");
	if (result % 11 == 0)
		printf("***The map must contain only 1, 0, P, C, E characters.\n");
	if (result % 13 == 0)
		printf("***The map must be surrounded by walls correctly.\n");
	if (result % 17 == 0)
		printf("***The map must contain at least one colloctable(C).\n");
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*result;
	char	*str;
	int		i;

	str = (char *)s1;
	len = 0;
	while (str[len])
		len++;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

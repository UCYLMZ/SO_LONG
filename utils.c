#include "so_long.h"
#include <stdio.h>

void	error_messager(int result)
{
	if (result != 1)
		printf("Error\n");
	if (result % 2 == 0)
		printf("***There is no playable valid path in the map.\n");
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

char	**map_duplicator(void)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (t_map.map_line_count + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (t_map.map[i])
	{
		copy[i] = ft_strdup(t_map.map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	shortest_line_func(char **map)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
			j++;
		if (j < len)
			len = j;
		i++;
	}
	t_map.shortest_line = len;
}

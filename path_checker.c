#include "so_long.h"
#include <stdio.h>

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

int	side_wall_check(char **map)
{
	int	i;

	i = 0;
	while (map[i] && i < t_map.map_line_count)
	{
		if (map[i][0] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[i] && i < t_map.map_line_count)
	{
		if (map[i][t_map.line_length - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	wall_checker13(char **map)
{
	int	i;
	int len;
	int	count;

	//printf("%s\n", map[count - 1]);
	len = t_map.line_length;
	count = t_map.map_line_count;
	i = 0;
	while (map[0][i] != '\n' && map[0][i] && i < len)
	{
		if (map[0][i] != '1')
			return (13);
		i++;
	}
	i = 0;
	while (map[count - 1][i] != '\n' && map[count - 1][i] && i < len)
	{
		if (map[count - 1][i] != '1')
			return (13);
		i++;
	}
	if (!side_wall_check(map))
		return (13);
	return (1);
}

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

/*int	path_checker(char **map)
{
	map = malloc(sizeof(char *) * (t_map.map_line_count + 1));
	if (!map)
		return (2);
	i = 0;
	while (t_map.map[i])
	{
		map[i] = ft_strdup(t_map.map[i]);
		i++;
	}
	map[i] = NULL;

}*/
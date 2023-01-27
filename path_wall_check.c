#include "so_long.h"
#include <stdio.h>

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
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

void	path_recursive(char **map, int col, int row)
{
	map[row][col] = '*';
	if (map[row + 1][col] && map[row + 1][col] != '1' && map[row + 1][col] != '*')
		path_recursive(map, col, row + 1);
	if (map[row - 1][col] && map[row - 1][col] != '1' && map[row - 1][col] != '*')
		path_recursive(map, col, row - 1);
	if (map[row][col + 1] && map[row][col + 1] != '1' && map[row][col + 1] != '*')
		path_recursive(map, col + 1, row);
	if (map[row][col - 1] && map[row][col - 1] != '1' && map[row][col - 1] != '*')
		path_recursive(map, col - 1, row);
}

int	path_checker(void)
{
	char	**map;
	int		row;
	int		col;
	int		j;
	int		i;

	row = t_map.plyr_row;
	col = t_map.plyr_col;
	map = map_duplicator();
	path_recursive(map, col, row);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '*' && map[i][j] != '\n' && map[i][j] != '1')
			{
				map_free (map);
				return (2);
			}
		}
	}
	map_free (map);
	return (1);
}

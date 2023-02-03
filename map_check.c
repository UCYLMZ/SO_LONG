#include "so_long.h"
#include <stdio.h>

int	player_check3(char **map)
{
	int	i;
	int	j;
	int	p_count;

	p_count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				p_count++;
			j++;
		}
		i++;
	}
	if (p_count != 1)
		return (wall_checker13(map) * 3);
	return (wall_checker13(map));
}

int	exit_check5(char **map)
{
	int	i;
	int	j;
	int	e_count;

	e_count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				e_count++;
			j++;
		}
		i++;
	}
	if (e_count == 1)
		return (player_check3(map));
	return (player_check3(map) * 5);
}

int	is_it_rectangular7(char **map)
{
	int	length;
	int	i;
	int	j;

	length = 0;
	while (map[0][length] != '\n' && map[0][length])
		length++;
	t_map.line_length = length;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j])
			j++;
		if (j != length)
			return (exit_check5(map) * 7);
		if (map[t_map.map_line_count - 1][length] == '\n')
			return (exit_check5(map) * 7);
		i++;
	}
	return (exit_check5(map));
}

int	char_check11(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C')
			{
				if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '\n')
					return (is_it_rectangular7(map) * 11);
			}
			j++;
		}
		i++;
	}
	return (is_it_rectangular7(map));
}

int	map_check(void)
{	
	int	result;
	int	coin_info17;

	shortest_line_func(t_map.map);
	if (t_map.coin_count > 0)
		coin_info17 = 1;
	else
		coin_info17 = 17;
	result = 1;
	result *= char_check11(t_map.map) * coin_info17;
	if (result == 1)
		result *= path_checker();
	error_messager(result);
	if (result == 1)
		return (0);
	else
		return (result);
}

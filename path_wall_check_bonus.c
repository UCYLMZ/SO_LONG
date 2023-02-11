/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_wall_check_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:34:43 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/02/11 18:34:44 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		if (map[i][t_map.shortest_line - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	wall_checker13(char **map)
{
	int	i;
	int	len;
	int	count;

	len = t_map.shortest_line;
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

void	path_recursive(char **map, int c, int r)
{
	map[r][c] = '*';
	if (map[r + 1][c] != '1' && map[r + 1][c] != '*' && map[r + 1][c] != 'X')
		path_recursive(map, c, r + 1);
	if (map[r - 1][c] != '1' && map[r - 1][c] != '*' && map[r - 1][c] != 'X')
		path_recursive(map, c, r - 1);
	if (map[r][c + 1] != '1' && map[r][c + 1] != '*' && map[r][c + 1] != 'X')
		path_recursive(map, c + 1, r);
	if (map[r][c - 1] != '1' && map[r][c - 1] != '*' && map[r][c - 1] != 'X')
		path_recursive(map, c - 1, r);
}

int	path_checker(void)
{
	char	**map;
	int		j;
	int		i;

	map = map_duplicator();
	path_recursive(map, t_map.plyr_col, t_map.plyr_row);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '*' && map[i][j] != '\n' &&
			map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'X')
			{
				map_free (map);
				return (2);
			}
		}
	}
	map_free (map);
	return (1);
}

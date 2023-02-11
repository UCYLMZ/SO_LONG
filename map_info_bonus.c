/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:36:05 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/02/11 18:36:06 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	map_line_count(void)
{
	int		fd;
	char	*line;
	int		count;

	fd = open ("map_bonus.ber", O_RDONLY);
	line = get_next_line(fd);
	free (line);
	count = 0;
	while (line)
	{
		line = get_next_line(fd);
		free (line);
		count++;
	}
	close (fd);
	return (count);
}

void	gate_finder(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				t_map.gate_col = j;
				t_map.gate_row = i;
			}
			if (map[i][j] == 'X')
			{
				t_map.enemy_count++;
				t_map.enemy_col = j;
				t_map.enemy_row = i;
			}
			j++;
		}
		i++;
	}
}

char	**get_map(void)
{
	char	*line;
	int		fd;
	int		i;

	t_map.map_line_count = map_line_count();
	t_map.map = malloc(sizeof(char *) * (t_map.map_line_count + 1));
	if (!t_map.map)
		return (NULL);
	fd = open ("map_bonus.ber", O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		t_map.map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	t_map.map[i] = NULL;
	gate_finder(t_map.map);
	return (t_map.map);
}

void	map_info_bonus(void)
{
	int	i;
	int	j;

	t_map.map = get_map();
	i = -1;
	while (t_map.map[++i])
	{
		j = 0;
		while (t_map.map[i][j])
		{
			if (t_map.map[i][j] == 'P')
			{
				t_map.plyr_col = j;
				t_map.plyr_row = i;
			}
			else if (t_map.map[i][j] == 'E')
			{
				t_map.exit_col = j;
				t_map.exit_row = i;
			}
			else if (t_map.map[i][j] == 'C')
				t_map.coin_count++;
			j++;
		}
	}
}

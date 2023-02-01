#include "so_long.h"
#include <stdio.h>

int	map_line_count(void)
{
	int		fd;
	char	*line;
	int		count;

	fd = open ("map.ber", O_RDONLY);
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
	free (line);
	return (count);
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
	fd = open ("map.ber", O_RDONLY);
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
	return (t_map.map);
}

void	map_info(void)
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
			if (t_map.map[i][j++] == 'C')
				t_map.coin_count++;
		}
	}
}

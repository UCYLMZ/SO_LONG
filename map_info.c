#include "so_long.h"
#include <stdio.h>

int	map_line_count(void)
{
	int		fd;
	char	*line;
	int		count;

	fd = open ("map.ber", O_RDONLY);
	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		line = get_next_line(fd);
		count++;
	}
	close (fd);
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

void	coin_indexer(int col, int row, int till_coin)
{
	t_map.coin_index[till_coin] = malloc (sizeof(int) * 2);
	if (!t_map.coin_index[till_coin])
		return ;
	t_map.coin_index[till_coin][0] = col;
	t_map.coin_index[till_coin][1] = row;
}

void	coin_handler(void)
{
	int		col;
	int		row;
	int		till_coin;

	t_map.coin_index = malloc(sizeof(int *) * (t_map.coin_count + 1));
	if (!t_map.coin_index)
		return ;
	till_coin = 0;
	row = 0;
	while (t_map.map[row])
	{
		col = 0;
		while (t_map.map[row][col])
		{
			if (t_map.map[row][col] == 'C')
			{
				coin_indexer(col, row, till_coin);
				till_coin++;
			}
			col++;
		}
		row++;
	}
	t_map.coin_index[till_coin] = NULL;
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
	coin_handler();
}

/*int main ()
{
	map_info();
	printf("plyr:%d, %d\nexit:%d, %d\ncoin:%d\n", t_map.plyr_col, t_map.plyr_row, t_map.exit_col, t_map.exit_row, t_map.coin_count);
	
	//printf("coinindex:%d, %d\n", t_map.coin_index[0][0], t_map.coin_index[0][1]);
	//printf("coinindex:%d, %d\n", t_map.coin_index[1][0], t_map.coin_index[1][1]);
	//printf("coinindex:%d, %d\n", t_map.coin_index[2][0], t_map.coin_index[2][1]);
	int i = 0;
	while (t_map.coin_index[i])
	{
		printf("coinindex:%d, ", t_map.coin_index[i][0]);
		printf("%d", t_map.coin_index[i][1]);
		i++;
		printf("#i:%d#\n", i);
	}
}*/
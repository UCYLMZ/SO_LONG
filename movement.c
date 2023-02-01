#include "so_long.h"
#include <stdio.h>

void move_left(t_mlx *mlx, char **map, int *step)
{
	if (map[t_map.plyr_row][t_map.plyr_col - 1] != '1')
	{
		if (map[t_map.plyr_row][t_map.plyr_col - 1] == 'C')
			t_map.current_coin++;
		map[t_map.plyr_row][t_map.plyr_col] = '0';
		map[t_map.plyr_row][t_map.plyr_col - 1] = 'P';
		t_map.plyr_col--;
		printf("step: %d\n", ++(*step));
		put_img(mlx, map);
	}
}

void move_right(t_mlx *mlx, char **map, int *step)
{
	if (map[t_map.plyr_row][t_map.plyr_col + 1] != '1')
	{
		if (map[t_map.plyr_row][t_map.plyr_col + 1] == 'C')
			t_map.current_coin++;
		map[t_map.plyr_row][t_map.plyr_col] = '0';
		map[t_map.plyr_row][t_map.plyr_col + 1] = 'P';
		t_map.plyr_col++;
		printf("step: %d\n", ++(*step));
		put_img(mlx, map);
	}
}

void move_down(t_mlx *mlx, char **map, int *step)
{
	if (map[t_map.plyr_row + 1][t_map.plyr_col] != '1')
	{
		if (map[t_map.plyr_row + 1][t_map.plyr_col] == 'C')
			t_map.current_coin++;
		map[t_map.plyr_row][t_map.plyr_col] = '0';
		map[t_map.plyr_row + 1][t_map.plyr_col] = 'P';
		t_map.plyr_row++;
		printf("step: %d\n", ++(*step));
		put_img(mlx, map);
	}
}

void move_up(t_mlx *mlx, char **map, int *step)
{
	if (map[t_map.plyr_row - 1][t_map.plyr_col] != '1')
	{
		if (map[t_map.plyr_row - 1][t_map.plyr_col] == 'C')
			t_map.current_coin++;
		map[t_map.plyr_row][t_map.plyr_col] = '0';
		map[t_map.plyr_row - 1][t_map.plyr_col] = 'P';
		t_map.plyr_row--;
		printf("step: %d\n", ++(*step));
		put_img(mlx, map);
	}
}


int	ft_movement(int key, t_mlx *mlx)
{
	static int	step;

	if (key == 0)
		move_left(mlx, t_map.map, &step);
	else if (key == 2)
		move_right(mlx, t_map.map, &step);
	else if (key == 1)
		move_down(mlx, t_map.map, &step);
	else if (key == 13)
		move_up(mlx, t_map.map, &step);
	else if (key == 53)
		ft_exit(17, mlx);
	return (0);
}
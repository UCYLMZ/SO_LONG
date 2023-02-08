#include "so_long_bonus.h"

void	enemy_left(int a, t_mlx *mlx, char **map)
{
	int	row;
	int	col;

	row = t_map.enemy_row * 128;
	col = t_map.enemy_col * 128;
	if (t_map.enemy_row == t_map.plyr_row
		&& t_map.enemy_col - 1 == t_map.plyr_col)
		ft_exit(404, mlx);
	put_img('0', t_map.enemy_col, t_map.enemy_row, mlx);
	if (a == 1)
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->e2, col - 64, row);
	else if (a == 2)
	{
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->e1, col - 128, row);
		t_map.enemy_col--;
	}
}

void	enemy_right(int a, t_mlx *mlx, char **map)
{
	int	row;
	int	col;

	row = t_map.enemy_row * 128;
	col = t_map.enemy_col * 128;
	if (t_map.enemy_row == t_map.plyr_row
		&& t_map.enemy_col + 1 == t_map.plyr_col)
		ft_exit(404, mlx);
	put_img('0', t_map.enemy_col, t_map.enemy_row, mlx);
	if (a == 1)
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->e2, col + 64, row);
	else if (a == 2)
	{
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->e1, col + 128, row);
		t_map.enemy_col++;
	}
}
#include <stdio.h>
void	enemy_up(int a, t_mlx *mlx, char **map)
{
	int	row;
	int	col;

	row = t_map.enemy_row * 128;
	col = t_map.enemy_col * 128;
	if (t_map.enemy_row - 1 == t_map.plyr_row
		&& t_map.enemy_col == t_map.plyr_col)
		ft_exit(404, mlx);
	put_img('0', t_map.enemy_col, t_map.enemy_row, mlx);
	if (a == 1)
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->e2, col, row - 64);
	else if (a == 2)
	{
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->e1, col, row - 128);
		t_map.enemy_row--;
		if (map[t_map.enemy_row - 1][t_map.enemy_col] != '0' && map[t_map.enemy_row - 1][t_map.enemy_col] != 'P')
		{
			printf("GİRDİM");
			getchar();
			t_map.enemy_flag = 1;
		}
	}
}

void	enemy_down(int a, t_mlx *mlx, char **map)
{
	int	row;
	int	col;

	row = t_map.enemy_row * 128;
	col = t_map.enemy_col * 128;
	if (t_map.enemy_row + 1 == t_map.plyr_row
		&& t_map.enemy_col == t_map.plyr_col)
		ft_exit(404, mlx);
	put_img('0', t_map.enemy_col, t_map.enemy_row, mlx);
	if (a == 1)
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->e2, col, row + 64);
	else if (a == 2)
	{
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->e1, col, row + 128);
		t_map.enemy_row++;
		if (map[t_map.enemy_row + 1][t_map.enemy_col] != '0'
		&& map[t_map.enemy_row + 1][t_map.enemy_col] != 'P')
			t_map.enemy_flag = 0;
	}
}

void	enemy_animate(int a, t_mlx **mlx, char **map)
{
	if (t_map.enemy_way == 'v')
	{
		// printf("%s\n", map[t_map.enemy_row]);
		// printf("%s\n", map[t_map.enemy_row - 1]);
		if ((map[t_map.enemy_row - 1][t_map.enemy_col] == '0'
		|| map[t_map.enemy_row - 1][t_map.enemy_col] == 'P') && t_map.enemy_flag == 0)
		{
			printf("yukarı");
			getchar();
			enemy_up(a, *mlx, map);
		}
		else if (map[t_map.enemy_row + 1][t_map.enemy_col] == '0'
		|| map[t_map.enemy_row + 1][t_map.enemy_col] == 'P')
		{
			printf("aşşağı");
			enemy_down(a, *mlx, map);
		}
	}
	else if (t_map.enemy_way == 'h')
	{
		if (map[t_map.enemy_row][t_map.enemy_col - 1] == '0'
		|| map[t_map.enemy_row][t_map.enemy_col - 1] == 'P')
			enemy_left(a, *mlx, map);
		else if (map[t_map.enemy_row][t_map.enemy_col + 1] == '0'
		|| map[t_map.enemy_row][t_map.enemy_col + 1] == 'P')
			enemy_right(a, *mlx, map);
	}
	// if (map[t_map.enemy_row][t_map.enemy_col - 1] == '0'
	// 	|| map[t_map.enemy_row][t_map.enemy_col - 1] == 'P')
	// 	enemy_left(a, *mlx, map);
	// else if (map[t_map.enemy_row - 1][t_map.enemy_col] == '0'
	// 	|| map[t_map.enemy_row - 1][t_map.enemy_col - 1] == 'P')
	// 	enemy_up(a, *mlx, map);
	// else if (map[t_map.enemy_row][t_map.enemy_col + 1] == '0'
	// 	|| map[t_map.enemy_row][t_map.enemy_col + 1] == 'P')
	// 	enemy_right(a, *mlx, map);
	// else if (map[t_map.enemy_row + 1][t_map.enemy_col] == '0'
	// 	|| map[t_map.enemy_row + 1][t_map.enemy_col] == 'P')
	// 	enemy_down(a, *mlx, map);
}

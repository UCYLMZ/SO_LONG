#include "so_long_bonus.h"
#include <stdio.h>

void	move_enemy_up(int a, t_mlx *mlx, char **map, int col, int row)
{
	put_img('0', t_map.enemy_col, t_map.enemy_row, mlx);
	if (a == 1)
	{
		if (t_map.enemy_col == t_map.plyr_col && t_map.enemy_row - 1 == t_map.plyr_row)
			ft_exit(404, mlx);
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->e2, col * 128, (row * 128) - 64);
	}
	else if (a == 2)
	{
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->e1, col * 128, (row * 128) - 128);
		t_map.enemy_row--;
		if (map[t_map.enemy_row - 1][t_map.enemy_col] != '0' && map[t_map.enemy_row - 1][t_map.enemy_col] != 'P')
			t_map.enemy_flag = 1;
	}
}

void	move_ver(int a, t_mlx *mlx, char **map, int col, int row)
{
	if ((map[row + 1][col] == '0' || map[row + 1][col] == 'P')
	&& t_map.enemy_flag == 1)
	{
		put_img('0', t_map.enemy_col, t_map.enemy_row, mlx);
		if (a == 1)
		{
			if (t_map.enemy_col == t_map.plyr_col 
			&& t_map.enemy_row + 1 == t_map.plyr_row)
				ft_exit(404, mlx);
			mlx_put_image_to_window(mlx->init, mlx->win, mlx->e2,
			col * 128, (row * 128) + 64);
		}
		else if (a == 2)
		{
			mlx_put_image_to_window(mlx->init, mlx->win, mlx->e1,
			col * 128, (row * 128) + 128);
			t_map.enemy_row++;
			if (map[t_map.enemy_row + 1][t_map.enemy_col] != '0'
			&& map[t_map.enemy_row + 1][t_map.enemy_col] != 'P')
				t_map.enemy_flag = 0;
		}
	}
	else if ((map[row - 1][col] == '0' || map[row - 1][col] == 'P')
	&& t_map.enemy_flag == 0)
		move_enemy_up(a, mlx, map, col, row);
}

void	move_enemy_left(int a, t_mlx *mlx, char **map, int col, int row)
{
	put_img('0', t_map.enemy_col, t_map.enemy_row, mlx);
	if (a == 1)
	{
		if (t_map.enemy_col - 1 == t_map.plyr_col && t_map.enemy_row == t_map.plyr_row)
			ft_exit(404, mlx);
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->e2, (col * 128) - 64, row * 128);
	}
	else if (a == 2)
	{
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->e1, (col * 128) - 128, row * 128);
		t_map.enemy_col--;
		if (map[t_map.enemy_row][t_map.enemy_col - 1] != '0' && map[t_map.enemy_row][t_map.enemy_col - 1] != 'P')
			t_map.enemy_flag = 1;
	}
}

void	move_hor(int a, t_mlx *mlx, char **map, int col, int row)
{
	if ((map[row][col + 1] == '0' || map[row][col + 1] == 'P') && t_map.enemy_flag == 1)
	{
		put_img('0', t_map.enemy_col, t_map.enemy_row, mlx);
		if (a == 1)
		{
			if (t_map.enemy_col + 1 == t_map.plyr_col && t_map.enemy_row == t_map.plyr_row)
				ft_exit(404, mlx);
			mlx_put_image_to_window(mlx->init, mlx->win, mlx->e2, (col * 128) + 64, row * 128);
		}
		else if (a == 2)
		{
			mlx_put_image_to_window(mlx->init, mlx->win, mlx->e1, (col * 128) + 128, row * 128);
			t_map.enemy_col++;
			if (map[t_map.enemy_row][t_map.enemy_col + 1] != '0' && map[t_map.enemy_row][t_map.enemy_col + 1] != 'P')
				t_map.enemy_flag = 0;
		}
	}
	else if ((map[row][col - 1] == '0' || map[row][col - 1] == 'P') && t_map.enemy_flag == 0)
		move_enemy_left(a, mlx, map, col, row);
}

void	enemy_animator(t_mlx *mlx)
{
	if (mlx->enemy_anim_count == 6000)
	{
		if (t_map.enemy_way == 'u' || t_map.enemy_way == 'd')
			move_ver(1, mlx, t_map.map, t_map.enemy_col, t_map.enemy_row);
		else if (t_map.enemy_way == 'r' || t_map.enemy_way == 'l')
			move_hor(1, mlx, t_map.map, t_map.enemy_col, t_map.enemy_row);
	}
	else if (mlx->enemy_anim_count == 12000)
	{
		if (t_map.enemy_way == 'u' || t_map.enemy_way == 'd')
			move_ver(2, mlx, t_map.map, t_map.enemy_col, t_map.enemy_row);
		else if (t_map.enemy_way == 'r' || t_map.enemy_way == 'l')
			move_hor(2, mlx, t_map.map, t_map.enemy_col, t_map.enemy_row);
		mlx->enemy_anim_count = 0;
	}
	mlx->enemy_anim_count++;
}
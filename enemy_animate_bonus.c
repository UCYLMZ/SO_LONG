/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animate_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:34:06 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/02/11 18:47:44 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_enemy_up(int a, t_mlx *mlx, int col, int row)
{
	put_img('0', col, row, mlx);
	if (a == 1)
	{
		if (col == t_map.plyr_col && row - 1 == t_map.plyr_row)
			ft_exit(404, mlx);
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->e2,
			col * 128, (row * 128) - 64);
	}
	else if (a == 2)
	{
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->e1,
			col * 128, (row * 128) - 128);
		t_map.enemy_row--;
		if (t_map.map[row - 2][col] != '0' && t_map.map[row - 2][col] != 'P')
			t_map.enemy_flag = 1;
	}
}

void	move_ver(int a, t_mlx *mlx, int c, int r)
{
	if ((t_map.map[r + 1][c] == '0' || t_map.map[r + 1][c] == 'P')
	&& t_map.enemy_flag == 1)
	{
		put_img('0', c, r, mlx);
		if (a == 1)
		{
			if (c == t_map.plyr_col && r + 1 == t_map.plyr_row)
				ft_exit(404, mlx);
			mlx_put_image_to_window(mlx->init, mlx->win, mlx->e2,
				c * 128, (r * 128) + 64);
		}
		else if (a == 2)
		{
			mlx_put_image_to_window(mlx->init, mlx->win, mlx->e1,
				c * 128, (r * 128) + 128);
			t_map.enemy_row++;
			if (t_map.map[r + 2][c] != '0' && t_map.map[r + 2][c] != 'P')
				t_map.enemy_flag = 0;
		}
	}
	else if ((t_map.map[r - 1][c] == '0' || t_map.map[r - 1][c] == 'P')
	&& t_map.enemy_flag == 0)
		move_enemy_up(a, mlx, c, r);
	else
		t_map.enemy_flag = 1;
}

void	move_enemy_left(int a, t_mlx *mlx, int col, int row)
{
	put_img('0', t_map.enemy_col, t_map.enemy_row, mlx);
	if (a == 1)
	{
		if (col - 1 == t_map.plyr_col && row == t_map.plyr_row)
			ft_exit(404, mlx);
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->e2,
			(col * 128) - 64, row * 128);
	}
	else if (a == 2)
	{
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->e1,
			(col * 128) - 128, row * 128);
		t_map.enemy_col--;
		if (t_map.map[row][col - 2] != '0' && t_map.map[row][col - 2] != 'P')
			t_map.enemy_flag = 2;
	}
}

void	move_hor(int a, t_mlx *mlx, int c, int r)
{
	if ((t_map.map[r][c + 1] == '0' || t_map.map[r][c + 1] == 'P')
	&& t_map.enemy_flag == 2)
	{
		put_img('0', t_map.enemy_col, t_map.enemy_row, mlx);
		if (a == 1)
		{
			if (c + 1 == t_map.plyr_col && r == t_map.plyr_row)
				ft_exit(404, mlx);
			mlx_put_image_to_window(mlx->init, mlx->win, mlx->e2,
				(c * 128) + 64, r * 128);
		}
		else if (a == 2)
		{
			mlx_put_image_to_window(mlx->init, mlx->win, mlx->e1,
				(c * 128) + 128, r * 128);
			t_map.enemy_col++;
			if (t_map.map[r][c + 2] != '0' && t_map.map[r][c + 2] != 'P')
				t_map.enemy_flag = 3;
		}
	}
	else if ((t_map.map[r][c - 1] == '0' || t_map.map[r][c - 1] == 'P')
	&& t_map.enemy_flag == 3)
		move_enemy_left(a, mlx, c, r);
	else
		t_map.enemy_flag = 2;
}

void	enemy_animator(t_mlx *mlx)
{
	if (mlx->enemy_anim_count == 8000)
	{
		if (t_map.enemy_way == 'u' || t_map.enemy_way == 'd')
			move_ver(1, mlx, t_map.enemy_col, t_map.enemy_row);
		else if (t_map.enemy_way == 'r' || t_map.enemy_way == 'l')
			move_hor(1, mlx, t_map.enemy_col, t_map.enemy_row);
	}
	else if (mlx->enemy_anim_count == 16000)
	{
		if (t_map.enemy_way == 'u' || t_map.enemy_way == 'd')
			move_ver(2, mlx, t_map.enemy_col, t_map.enemy_row);
		else if (t_map.enemy_way == 'r' || t_map.enemy_way == 'l')
			move_hor(2, mlx, t_map.enemy_col, t_map.enemy_row);
		mlx->enemy_anim_count = 0;
	}
	mlx->enemy_anim_count++;
}

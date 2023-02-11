/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:36:23 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/02/11 18:39:46 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(char **map, int *step)
{
	if (map[t_map.plyr_row][t_map.plyr_col - 1] != '1')
	{
		if (map[t_map.plyr_row][t_map.plyr_col - 1] == 'C')
			t_map.current_coin++;
		map[t_map.plyr_row][t_map.plyr_col] = '0';
		map[t_map.plyr_row][t_map.plyr_col - 1] = 'P';
		t_map.plyr_col--;
		ft_putstr("step:");
		ft_putnbr(++(*step));
		ft_putstr("\n");
	}
}

void	move_right(char **map, int *step)
{
	if (map[t_map.plyr_row][t_map.plyr_col + 1] != '1')
	{
		if (map[t_map.plyr_row][t_map.plyr_col + 1] == 'C')
			t_map.current_coin++;
		map[t_map.plyr_row][t_map.plyr_col] = '0';
		map[t_map.plyr_row][t_map.plyr_col + 1] = 'P';
		t_map.plyr_col++;
		ft_putstr("step:");
		ft_putnbr(++(*step));
		ft_putstr("\n");
	}
}

void	move_down(char **map, int *step)
{
	if (map[t_map.plyr_row + 1][t_map.plyr_col] != '1')
	{
		if (map[t_map.plyr_row + 1][t_map.plyr_col] == 'C')
			t_map.current_coin++;
		map[t_map.plyr_row][t_map.plyr_col] = '0';
		map[t_map.plyr_row + 1][t_map.plyr_col] = 'P';
		t_map.plyr_row++;
		ft_putstr("step:");
		ft_putnbr(++(*step));
		ft_putstr("\n");
	}
}

void	move_up(char **map, int *step)
{
	if (map[t_map.plyr_row - 1][t_map.plyr_col] != '1')
	{
		if (map[t_map.plyr_row - 1][t_map.plyr_col] == 'C')
			t_map.current_coin++;
		map[t_map.plyr_row][t_map.plyr_col] = '0';
		map[t_map.plyr_row - 1][t_map.plyr_col] = 'P';
		t_map.plyr_row--;
		ft_putstr("step:");
		ft_putnbr(++(*step));
		ft_putstr("\n");
	}
}

int	ft_movement(int key, t_mlx *mlx)
{
	static int	step;

	if (key != 0 && key != 2 && key != 1 && key != 13 && key != 53)
		return (1);
	if (key == 0)
		move_left(t_map.map, &step);
	else if (key == 2)
		move_right(t_map.map, &step);
	else if (key == 1)
		move_down(t_map.map, &step);
	else if (key == 13)
		move_up(t_map.map, &step);
	else if (key == 53)
		ft_exit(17, mlx);
	if (t_map.gate_col != t_map.plyr_col || t_map.gate_row != t_map.plyr_row)
		t_map.map[t_map.gate_row][t_map.gate_col] = 'E';
	put_img(mlx, t_map.map);
	return (0);
}

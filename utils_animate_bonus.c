/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_animate_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:34:54 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/02/11 18:39:10 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	first_kicker(char way)
{
	if (way == 'd')
		t_map.enemy_flag = 1;
	else if (way == 'u')
		t_map.enemy_flag = 0;
	else if (way == 'l')
		t_map.enemy_flag = 3;
	else if (way == 'r')
		t_map.enemy_flag = 2;
}

void	way_setter(void)
{
	char	w;

	w = t_map.enemy_way;
	if (w == 'v' || w == 'd' || w == 'u')
	{
		if (t_map.map[t_map.enemy_row - 1][t_map.enemy_col] != 'P'
			&& t_map.map[t_map.enemy_row - 1][t_map.enemy_col] != '0')
			t_map.enemy_way = 'd';
		else
			t_map.enemy_way = 'u';
	}
	else if (w == 'h' || w == 'r' || w == 'l')
	{
		if (t_map.map[t_map.enemy_row][t_map.enemy_col - 1] != 'P'
			&& t_map.map[t_map.enemy_row][t_map.enemy_col - 1] != '0')
			t_map.enemy_way = 'r';
		else
			t_map.enemy_way = 'l';
	}
	first_kicker(t_map.enemy_way);
}

void	enemy_way_check(char **map, int c, int r)
{
	int	h;
	int	v;

	h = 0;
	while (map[r][(c++) + 1] == '0')
		h++;
	c = t_map.enemy_col;
	while (map[r][(c--) - 1] == '0')
		h++;
	c = t_map.enemy_col;
	v = 0;
	while (map[(r++) + 1][c] == '0')
		v++;
	r = t_map.enemy_row;
	while (map[(r--) - 1][c] == '0')
		v++;
	if (v >= h)
		t_map.enemy_way = 'v';
	else
		t_map.enemy_way = 'h';
	way_setter();
}

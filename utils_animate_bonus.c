#include "so_long_bonus.h"

void	way_setter(void)
{
	char	w;

	w = t_map.enemy_way;
	if (w == 'v' || w == 'd' || w == 'v')
	{
		if (t_map.map[t_map.enemy_row - 1][t_map.enemy_col] != 'P'
			|| t_map.map[t_map.enemy_row - 1][t_map.enemy_col] != '0')
			t_map.enemy_way = 'd';
		else
			t_map.enemy_way = 'u';
	}
	else if (w == 'h' || w == 'r' || w == 'l')
	{
		if (t_map.map[t_map.enemy_row][t_map.enemy_col - 1] != 'P'
			|| t_map.map[t_map.enemy_row][t_map.enemy_col - 1] != '0')
			t_map.enemy_way = 'r';
		else
			t_map.enemy_way = 'l';
	}
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
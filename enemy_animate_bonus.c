#include "so_long_bonus.h"

void	enemy_left(int a, t_mlx **mlx, char **map)
{
	if (t_map.enemy_row == t_map.plyr_row
		&& t_map.enemy_col - 1 == t_map.plyr_col)
		ft_exit(404, *mlx);
	if (a == 2)
	{
		put_img('0', t_map.enemy_col, t_map.enemy_row, *mlx); // working on here!!!
	}
}

void	enemy_animate(int a, t_mlx **mlx, char **map)
{
	if (map[t_map.enemy_row][t_map.enemy_col - 1] != 'E'
		&& map[t_map.enemy_row][t_map.enemy_col - 1] != '1'
		&& map[t_map.enemy_row][t_map.enemy_col - 1] != 'C')
		enemy_left(a, mlx, map);
	// else if (map[t_map.enemy_row][t_map.enemy_col + 1] != 'E'
	// 	&& map[t_map.enemy_row][t_map.enemy_col + 1] != '1'
	// 	&& map[t_map.enemy_row][t_map.enemy_col - 1] != 'C')
	// 	enemy_right(a, **mlx, map);
	// else if (map[t_map.enemy_row - 1][t_map.enemy_col] != 'E'
	// 	&& map[t_map.enemy_row - 1][t_map.enemy_col - 1] != '1'
	// 	&& map[t_map.enemy_row][t_map.enemy_col - 1] != 'C')
	// 	enemy_up(a, **mlx, map);
	// else if (map[t_map.enemy_row + 1][t_map.enemy_col] != 'E'
	// 	&& map[t_map.enemy_row + 1][t_map.enemy_col] != '1'
	// 	&& map[t_map.enemy_row][t_map.enemy_col - 1] != 'C')
	// 	enemy_down(a, **mlx, map);
}

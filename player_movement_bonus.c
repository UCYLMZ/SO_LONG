#include "so_long_bonus.h"

void	left_action(void)
{
	int i;

	i = 0;
	while (i <= 3)
	{
		if (i == 0)
			mlx_put_image_to_window(mlx->init, mlx->win, mlx->pll, (t_map.plyr_col * 128) - 32, t_map.plyr_row * 128);
		if (i == 1)
			mlx_put_image_to_window(mlx->init, mlx->win, mlx->pl, (t_map.plyr_col * 128) - 64, t_map.plyr_row * 128);
		if (i == 2)
			mlx_put_image_to_window(mlx->init, mlx->win, mlx->plr, (t_map.plyr_col * 128) - 96, t_map.plyr_row * 128);
		if (i == 3)
			mlx_put_image_to_window(mlx->init, mlx->win, mlx->pl, (t_map.plyr_col * 128) - 128, t_map.plyr_row * 128);
		usleep(150000);
		i++;
	}
}

void	move_left(int *step)
{
	if (t_map.map[t_map.plyr_row][t_map.plyr_col - 1] != '1')
	{
		(*step)++;
		if (t_map.map[t_map.plyr_row][t_map.plyr_col - 1] == 'X')
			ft_exit(404, mlx);
		if (t_map.map[t_map.plyr_row][t_map.plyr_col - 1] == 'C')
			t_map.current_coin++;
		t_map.map[t_map.plyr_row][t_map.plyr_col - 1] = '0';
		left_action();
		t_map.plyr_col--;
	}
}

int	player_movement(int key, void *ptr)
{
	static int step;

	if (key != 0 && key != 2 && key !=1 && key != 13 && key != 53)
		return (1);
	if (key == 0)
		move_left(&step);
	// else if (key == 2)
	// 	move_right(&step);
	// else if (key == 13)
	// 	move_up(&step);
	// else if (key == 1)
	// 	move_down(&step);
	else if (key == 53)
		ft_exit(17, mlx);
	return (0);
}
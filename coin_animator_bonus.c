#include "so_long_bonus.h"

void	coin_printer(int a, int j, int i, t_mlx *mlx)
{
	i *= 128;
	j *= 128;
	if (a == 1)
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->c1, j, i);
	else if (a == 2)
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->c2, j, i);
	else if (a == 3)
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->c3, j, i);
	else if (a == 4)
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->c4, j, i);
}

void	coin_finder(int a, t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (t_map.map[++i])
	{
		j = -1;
		while (t_map.map[i][++j] && t_map.map[i][j] != '\n')
		{
			if (t_map.map[i][j] == 'C')
			{
				if (a >= 1 && a <= 4)
					coin_printer(a, j, i, mlx);
			}
		}
	}
}

void	coin_animator(t_mlx **mlx)
{
	if ((*mlx)->coin_anim_count == 12000 || (*mlx)->coin_anim_count == 0)
	{
		(*mlx)->coin_anim_count = 0;
		coin_finder(1, *mlx);
		//enemy_animate(1, mlx);
	}
	else if ((*mlx)->coin_anim_count == 10000
		|| (*mlx)->coin_anim_count == 2000)
	{
		coin_finder(2, *mlx);
		//enemy_animate(2, mlx);
	}
	else if ((*mlx)->coin_anim_count == 8000 || (*mlx)->coin_anim_count == 4000)
	{
		coin_finder(3, *mlx);
		//enemy_animate(3, mlx);
	}
	else if ((*mlx)->coin_anim_count == 6000)
	{
		coin_finder(4, *mlx);
		//enemy_animate(4, mlx, t_map.map);
	}
	(*mlx)->coin_anim_count++;
}

#include "so_long_bonus.h"

void	coin_printer(int a, int j, int i)
{
	i *= 128;
	j *= 128;
	if(a == 1)
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->c1, j, i);
	else if(a == 2)
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->c2, j, i);
	else if(a == 3)
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->c3, j, i);
	else if(a == 4)
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->c4, j, i);
}

void	coin_finder(int a)
{
	int	i;
	int j;

	i = -1;
	while (t_map.map[++i])
	{
		j = -1;
		while (t_map.map[i][++j] && t_map.map[i][j] != '\n')
		{
			if (t_map.map[i][j] == 'C')
			{
				if(a >= 1 && a <= 4)
					coin_printer(a, j, i);
			}
		}
	}
}

void coin_animator(t_mlx *mlx)
{
	if (mlx->coin_anim_count == 12000 || mlx->coin_anim_count == 0)
	{
		mlx->coin_anim_count = 0;
		coin_finder(1);
	}
	else if (mlx->coin_anim_count == 10000 || mlx->coin_anim_count == 2000)
		coin_finder(2);
	else if (mlx->coin_anim_count == 8000 || mlx->coin_anim_count == 4000)
		coin_finder(3);
	else if (mlx->coin_anim_count == 6000)
		coin_finder(4);
	mlx->coin_anim_count++;
}
#include "so_long_bonus.h"

void	map_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free (map[i]);
		i++;
	}
	free (map[i]);
	free (map);
}

int	ft_exit(int key, t_mlx *mlx)
{
	mlx_clear_window(mlx->init, mlx->win);
	// if (key == 404)
	// 	lose window();
	// else if (key == 1001)
	// 	win window();
	map_free(t_map.map);
	free(mlx);
	system("leaks so_long_bonus");
	exit (0);
}

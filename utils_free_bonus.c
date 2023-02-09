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
#include <stdio.h>
void	lose_window(t_mlx *mlx)
{
	int i;
	int	x;
	int	y;

	x = (t_map.shortest_line * 64) - 192;
	y = (t_map.map_line_count * 64) - 64;
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->go, x, y);
	i = 0;
	while (i != 2147483647)
	{
		printf("%d\n", i);
		i++;
	}
}
#include <stdio.h>
int	ft_exit(int key, t_mlx *mlx)
{
	printf("%d\n", key);
	//mlx_clear_window(mlx->init, mlx->win);
	// if (key == 404)
	// 	lose_window(mlx);
	// else if (key == 1001)
	// 	win window();
	//map_free(t_map.map);
	//free(mlx);
	//system("leaks so_long_bonus");
	exit (0);
}

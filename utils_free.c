#include "so_long.h"

void	map_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free (map[i]);
		i++;
	}
	free(map[i]);
}

void	coins_free(int **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		i++;
	}
	free (arr[i]);
}

int	ft_exit(t_mlx *mlx, int key)
{
	(void) key;
	coins_free(t_map.coin_index);
	map_free(t_map.map);
	free (mlx);
	system("leaks so_long");
	exit(0);
}

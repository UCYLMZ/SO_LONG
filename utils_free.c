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

int	ft_exit(int key, t_mlx *mlx)
{
	map_free(t_map.map);
	//free (mlx);
	//system("leaks so_long");
	exit(0);
}

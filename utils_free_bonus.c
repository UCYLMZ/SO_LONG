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
	free(map);
}

int	ft_exit(int key, t_mlx *mlx)
{
	map_free(t_map.map);
	exit (0);
}

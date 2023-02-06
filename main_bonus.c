#include "so_long_bonus.h"
#include <stdio.h>

int	main(void)
{
	t_mlx	*mlx;

	map_info();
	if (map_check())
		return (1);
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (2);
	mlx_initializer(mlx);
}

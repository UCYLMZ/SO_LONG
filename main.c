#include "so_long.h"

int	main(void)
{
	map_info();
	if (map_check())
		return (1);
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (2);
	mlx_filler(mlx);
}

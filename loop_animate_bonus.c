#include "so_long_bonus.h"
#include <stdio.h>

int	loop_animator(t_mlx **mlx)
{
	if (t_map.coin_count > t_map.current_coin)
		coin_animator(mlx);
	return (0);
}

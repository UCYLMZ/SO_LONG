#include "so_long_bonus.h"
#include <stdio.h>

void	exit_checker(t_mlx **mlx)
{
	if (t_map.coin_count == t_map.current_coin)
		ft_exit(404, (*mlx));
	else if (t_map.coin_count / t_map.current_coin >= 4)
		(*mlx)->g = (*mlx)->g2;
	else if (t_map.coin_count / t_map.current_coin >= 2)
		(*mlx)->g = (*mlx)->g3;
	else if (t_map.coin_count == t_map.current_coin)
		(*mlx)->g = (*mlx)->g4;
	if (t_map.exit_col == t_map.plyr_col && t_map.exit_row == t_map.plyr_row)
		put_img('M', t_map.plyr_col, t_map.plyr_row, *mlx);
	else
		put_img('E', t_map.exit_col, t_map.exit_row, *mlx);
}

void	coin_checker(t_mlx **mlx)
{
	if (t_map.current_coin == 1)
		(*mlx)->g = (*mlx)->g2;
	else if (t_map.coin_count / t_map.current_coin <= 2)
		(*mlx)->g = (*mlx)->g3;
	if (t_map.coin_count == t_map.current_coin)
		(*mlx)->g = (*mlx)->g4;
	if (t_map.exit_col == t_map.plyr_col && t_map.exit_row == t_map.plyr_row)
		put_img('M', t_map.plyr_col, t_map.plyr_row, *mlx);
	else
		put_img('E', t_map.exit_col, t_map.exit_row, *mlx);
}

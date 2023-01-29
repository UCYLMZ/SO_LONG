#include "so_long.h"
#include <stdio.h>

void	xpm_to_img(t_mlx *map)
{
	//map->player_path = "./img/player.xpm";
	//map->wall_path = "./img/wall.xpm";
	//map->coin_path = "./img/coin.xpm";
	//map->gate_path = "./img/gate.xpm";
	//map->floor_path = "./img/wall.xpm";
	//map->wall = mlx_xpm_file_to_image(map->mlx_init, map->wall_path, &map->x, &map->y);
	//map->player = mlx_xpm_file_to_image(map->mlx_init, map->player_path, &map->x, &map->y);
	//map->coin = mlx_xpm_file_to_image(map->mlx_init, map->coin_path, &map->x, &map->y);
	//map->gate = mlx_xpm_file_to_image(map->mlx_init, map->gate_path, &map->x, &map->y);
	//map->floor = mlx_xpm_file_to_image(map->mlx_init, map->floor_path, &map->x, &map->y);
}

int	main(void)
{
	//t_mlx	*map;
	//map = malloc(sizeof(t_mlx) * 10);
	//map->a = 500;
	//map->b = 500;
	//map->mlx_init = mlx_init();
//
	//xpm_to_img(map);
	//map->win = mlx_new_window(map->mlx_init, map->a, map->b, "./so long");
	map_info();
	printf("%d", map_check());
	printf("\nshortest#%d#", t_map.shortest_line);
	printf("\nfirst*%d*", t_map.line_length);

	//mlx_loop(map->mlx_init);
	//map_free(t_map.map);
	//coins_free (t_map.coin_index);
	//system("leaks a.out");
}
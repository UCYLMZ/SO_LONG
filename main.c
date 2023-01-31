#include "so_long.h"
#include <stdio.h>

void	xpm_to_img(t_mlx *map)
{
	map->p_p = "./img/mario.xpm";
	map->w_p = "./img/wall.xpm";
	map->c_p = "./img/coin.xpm";
	map->g_p = "./img/gate.xpm";
	map->f_p = "./img/floor.xpm";
	map->w = mlx_xpm_file_to_image(map->init, map->w_p, &map->x, &map->y);
	map->p = mlx_xpm_file_to_image(map->init, map->p_p, &map->x, &map->y);
	map->c = mlx_xpm_file_to_image(map->init, map->c_p, &map->x, &map->y);
	map->g = mlx_xpm_file_to_image(map->init, map->g_p, &map->x, &map->y);
	map->f = mlx_xpm_file_to_image(map->init, map->f_p, &map->x, &map->y);
}

void	img_printer(t_mlx *mlx, char c)
{
	if (c == '1')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->w, mlx->x1, mlx->y1);
	if (c == '0')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->f, mlx->x1, mlx->y1);
	if (c == 'P')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->p, mlx->x1, mlx->y1);
	if (c == 'C')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->c, mlx->x1, mlx->y1);
	if (c == 'E')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->g, mlx->x1, mlx->y1);
}

void	put_img(t_mlx *mlx, char **map)
{
	int	i;
	int	j;

	i = 0;
	mlx->y1 = 0;
	while (map[i] != NULL)
	{
		j = 0;
		mlx->x1 = 0;
		while (map[i][j] != '\0')
		{
			img_printer(mlx, map[i][j]);
			j++;
			mlx->x1 += 64;
		}
		mlx->y1 += 64;
		i += 1;
	}
}

int	main(void)
{
	t_mlx	*mlx;
	int		l;
	int		c;

	map_info();
	if (map_check())
		return (1);
	l = t_map.line_length * 64;
	c = t_map.map_line_count * 64;
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (1);
	mlx->init = mlx_init();
	xpm_to_img(mlx);
	mlx->win = mlx_new_window(mlx->init, l, c, "so_long");
	put_img(mlx, t_map.map);
	mlx_hook(mlx->win, 17, 0, ft_exit, 0);
	mlx_loop(mlx->init);
	//map_free(t_map.map);
	//coins_free (t_map.coin_index);
	system("leaks a.out");
}

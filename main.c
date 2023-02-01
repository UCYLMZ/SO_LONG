#include "so_long.h"
#include <stdio.h>

void	xpm_to_img(t_mlx *map)
{
	map->p_p = "./img/mario.xpm";
	map->w_p = "./img/wall.xpm";
	map->c_p = "./img/coin.xpm";
	map->g_p = "./img/gate.xpm";
	map->f_p = "./img/floor.xpm";
	map->m_p = "./img/player+gate.xpm";
	map->w = mlx_xpm_file_to_image(map->init, map->w_p, &map->x, &map->y);
	map->p = mlx_xpm_file_to_image(map->init, map->p_p, &map->x, &map->y);
	map->c = mlx_xpm_file_to_image(map->init, map->c_p, &map->x, &map->y);
	map->g = mlx_xpm_file_to_image(map->init, map->g_p, &map->x, &map->y);
	map->f = mlx_xpm_file_to_image(map->init, map->f_p, &map->x, &map->y);
	map->m = mlx_xpm_file_to_image(map->init, map->m_p, &map->x, &map->y);
}

void	img_printer(t_mlx *mlx, char c)
{
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->f, mlx->x1, mlx->y1);
	if (c == '1')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->w, mlx->x1, mlx->y1);
	if (c == 'C')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->c, mlx->x1, mlx->y1);
	if (c == 'E')
	{
		/*if (t_map.gate_col == t_map.plyr_col && t_map.gate_row == t_map.plyr_row)
			mlx_put_image_to_window(mlx->init, mlx->win, mlx->m, mlx->x1, mlx->y1);
		else*/
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->g, mlx->x1, mlx->y1);
	}
	if (c == 'P')
	{
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->p, mlx->x1, mlx->y1);
		if (t_map.gate_col == t_map.plyr_col && t_map.gate_row == t_map.plyr_row)
			mlx_put_image_to_window(mlx->init, mlx->win, mlx->m, mlx->x1, mlx->y1);
	}
}

void	put_img(t_mlx *mlx, char **map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = t_map.plyr_col * 128;
	y = t_map.plyr_row * 128;
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
			mlx->x1 += 128;
		}
		mlx->y1 += 128;
		i += 1;
	}
}

void mlx_filler(t_mlx *mlx)
{
	int		l;
	int		c;

	l = t_map.line_length * 128;
	c = t_map.map_line_count * 128;
	mlx->init = mlx_init();
	xpm_to_img(mlx);
	mlx->win = mlx_new_window(mlx->init, l, c, "so_long");
	put_img(mlx, t_map.map);
	mlx_hook(mlx->win, 17, 0, &ft_exit, mlx);
	mlx_hook(mlx->win, 2, 0, &ft_movement, mlx);
	mlx_loop(mlx->init);
}

int	main(void)
{
	t_mlx	*mlx;
	
	map_info();
	if (map_check())
		return (1);
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (1);
	mlx_filler(mlx);
	//mlx_string_put(mlx->init, mlx->win, 64, 64, 0, "0");
	//mlx_loop_hook(mlx->init); check it out!
	free (mlx);
	//system("leaks so_long");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handle_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:33:10 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/02/11 18:36:17 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_img(char c, int x, int y, t_mlx *mlx)
{
	x *= 128;
	y *= 128;
	if (c == '0')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->f, x, y);
	else if (c == '1')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->w, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->p, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->g, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->c1, x, y);
	else if (c == 'X')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->e, x, y);
	else if (c == 'S')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->s, x, y);
	else if (c == 'M')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->m, x, y);
}

void	win_initializer(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (t_map.map[i])
	{
		j = 0;
		while (t_map.map[i][j] && t_map.map[i][j] != '\n')
		{
			put_img(t_map.map[i][j], j, i, mlx);
			j++;
		}
		i++;
	}
	put_img('S', 0, 0, mlx);
}

void	xpm_to_image(t_mlx *mlx)
{
	mlx->w = mlx_xpm_file_to_image(mlx->init, mlx->w_p, &mlx->x, &mlx->y);
	mlx->f = mlx_xpm_file_to_image(mlx->init, mlx->f_p, &mlx->x, &mlx->y);
	mlx->s = mlx_xpm_file_to_image(mlx->init, mlx->s_p, &mlx->x, &mlx->y);
	mlx->p = mlx_xpm_file_to_image(mlx->init, mlx->pr_p, &mlx->x, &mlx->y);
	mlx->pr = mlx_xpm_file_to_image(mlx->init, mlx->pr_p, &mlx->x, &mlx->y);
	mlx->pl = mlx_xpm_file_to_image(mlx->init, mlx->pl_p, &mlx->x, &mlx->y);
	mlx->c1 = mlx_xpm_file_to_image(mlx->init, mlx->c1_p, &mlx->x, &mlx->y);
	mlx->c2 = mlx_xpm_file_to_image(mlx->init, mlx->c2_p, &mlx->x, &mlx->y);
	mlx->c3 = mlx_xpm_file_to_image(mlx->init, mlx->c3_p, &mlx->x, &mlx->y);
	mlx->c4 = mlx_xpm_file_to_image(mlx->init, mlx->c4_p, &mlx->x, &mlx->y);
	mlx->g = mlx_xpm_file_to_image(mlx->init, mlx->g1_p, &mlx->x, &mlx->y);
	mlx->g1 = mlx_xpm_file_to_image(mlx->init, mlx->g1_p, &mlx->x, &mlx->y);
	mlx->g2 = mlx_xpm_file_to_image(mlx->init, mlx->g2_p, &mlx->x, &mlx->y);
	mlx->g3 = mlx_xpm_file_to_image(mlx->init, mlx->g3_p, &mlx->x, &mlx->y);
	mlx->g4 = mlx_xpm_file_to_image(mlx->init, mlx->g4_p, &mlx->x, &mlx->y);
	mlx->m = mlx_xpm_file_to_image(mlx->init, mlx->m_p, &mlx->x, &mlx->y);
	mlx->e = mlx_xpm_file_to_image(mlx->init, mlx->e1_p, &mlx->x, &mlx->y);
	mlx->e1 = mlx_xpm_file_to_image(mlx->init, mlx->e1_p, &mlx->x, &mlx->y);
	mlx->e2 = mlx_xpm_file_to_image(mlx->init, mlx->e2_p, &mlx->x, &mlx->y);
}

void	xpm_img_path(t_mlx *mlx)
{
	mlx->w_p = "./img_bonus/wall.xpm";
	mlx->f_p = "./img_bonus/floor.xpm";
	mlx->s_p = "./img_bonus/score.xpm";
	mlx->pr_p = "./img_bonus/pr.xpm";
	mlx->pl_p = "./img_bonus/pl.xpm";
	mlx->pl_p = "./img_bonus/pl.xpm";
	mlx->c1_p = "./img_bonus/c1.xpm";
	mlx->c2_p = "./img_bonus/c2.xpm";
	mlx->c3_p = "./img_bonus/c3.xpm";
	mlx->c4_p = "./img_bonus/c4.xpm";
	mlx->g1_p = "./img_bonus/g1.xpm";
	mlx->g2_p = "./img_bonus/g2.xpm";
	mlx->g3_p = "./img_bonus/g3.xpm";
	mlx->g4_p = "./img_bonus/g4.xpm";
	mlx->m_p = "./img_bonus/m.xpm";
	mlx->e1_p = "./img_bonus/e1.xpm";
	mlx->e2_p = "./img_bonus/e2.xpm";
	xpm_to_image(mlx);
}

void	mlx_initializer(t_mlx *mlx)
{
	int	l;
	int	c;

	l = t_map.line_length * 128;
	c = t_map.map_line_count * 128;
	mlx->init = mlx_init();
	xpm_img_path(mlx);
	mlx->win = mlx_new_window(mlx->init, l, c, "so_long_bonus");
	win_initializer(mlx);
	t_map.color = (int)4294967295;
	enemy_way_check(t_map.map, t_map.enemy_col, t_map.enemy_row);
	t_map.map[t_map.plyr_row][t_map.plyr_col] = '0';
	t_map.map[t_map.enemy_row][t_map.enemy_col] = '0';
	mlx_string_put(mlx->init, mlx->win, 35, 67, t_map.color, "step: 0");
	mlx_hook(mlx->win, 17, 0, &ft_exit, NULL);
	mlx_hook(mlx->win, 2, 0, &player_movement, (void *)&mlx);
	mlx_loop_hook(mlx->init, &loop_animator, (void *)&mlx);
	mlx_loop(mlx->init);
}

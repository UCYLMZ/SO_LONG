#include "so_long_bonus.h"
#include <stdio.h>

void	put_img(char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->f, x * 128, y * 128);
	else if (c == '1')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->w, x * 128, y * 128);
	else if (c == 'P')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->p, x * 128, y * 128);
	else if (c == 'E')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->g1, x * 128, y * 128);
	else if (c == 'C')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->c1, x * 128, y * 128);
	else if (c == 'X')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->e1, x * 128, y * 128);
}

void	win_initializer(void)
{
	int	i;
	int	j;

	i = 0;
	while (t_map.map[i])
	{
		j = 0;
		while (t_map.map[i][j] && t_map.map[i][j] != '\n')
		{
			put_img(t_map.map[i][j], j, i);
			j++;
		}
		i++;
	}
}

void	xpm_to_image(void)
{
	mlx->w = mlx_xpm_file_to_image(mlx->init, mlx->w_p, &mlx->x, &mlx->y);
	mlx->f = mlx_xpm_file_to_image(mlx->init, mlx->f_p, &mlx->x, &mlx->y);
	mlx->p = mlx_xpm_file_to_image(mlx->init, mlx->pr_p, &mlx->x, &mlx->y);
	mlx->pr = mlx_xpm_file_to_image(mlx->init, mlx->pr_p, &mlx->x, &mlx->y);
	mlx->pl = mlx_xpm_file_to_image(mlx->init, mlx->pl_p, &mlx->x, &mlx->y);
	mlx->prl = mlx_xpm_file_to_image(mlx->init, mlx->prl_p, &mlx->x, &mlx->y);
	mlx->pll = mlx_xpm_file_to_image(mlx->init, mlx->pll_p, &mlx->x, &mlx->y);
	mlx->prr = mlx_xpm_file_to_image(mlx->init, mlx->prr_p, &mlx->x, &mlx->y);
	mlx->plr = mlx_xpm_file_to_image(mlx->init, mlx->plr_p, &mlx->x, &mlx->y);
	mlx->c1 =  mlx_xpm_file_to_image(mlx->init, mlx->c1_p, &mlx->x, &mlx->y);
	mlx->c2 =  mlx_xpm_file_to_image(mlx->init, mlx->c2_p, &mlx->x, &mlx->y);
	mlx->c3 =  mlx_xpm_file_to_image(mlx->init, mlx->c3_p, &mlx->x, &mlx->y);
	mlx->c4 =  mlx_xpm_file_to_image(mlx->init, mlx->c4_p, &mlx->x, &mlx->y);
	mlx->g1 = mlx_xpm_file_to_image(mlx->init, mlx->g1_p, &mlx->x, &mlx->y);
	mlx->g2 = mlx_xpm_file_to_image(mlx->init, mlx->g2_p, &mlx->x, &mlx->y);
	mlx->g3 = mlx_xpm_file_to_image(mlx->init, mlx->g3_p, &mlx->x, &mlx->y);
	mlx->g4 = mlx_xpm_file_to_image(mlx->init, mlx->g4_p, &mlx->x, &mlx->y);
	mlx->m = mlx_xpm_file_to_image(mlx->init, mlx->m_p, &mlx->x, &mlx->y);
	mlx->e1 = mlx_xpm_file_to_image(mlx->init, mlx->e1_p, &mlx->x, &mlx->y);
	mlx->e2 = mlx_xpm_file_to_image(mlx->init, mlx->e2_p, &mlx->x, &mlx->y);
}

void	xpm_img_path(void)
{
	mlx->w_p = "./img_bonus/wall.xpm";
	mlx->f_p = "./img_bonus/floor.xpm";
	mlx->e1_p = "./img_bonus/e1.xpm";
	mlx->e2_p = "./img_bonus/e2.xpm";
	mlx->pr_p = "./img_bonus/pr.xpm";
	mlx->prl_p = "./img_bonus/prl.xpm";
	mlx->prr_p = "./img_bonus/prr.xpm";
	mlx->pl_p = "./img_bonus/pl.xpm";
	mlx->pll_p = "./img_bonus/pll.xpm";
	mlx->plr_p = "./img_bonus/plr.xpm";
	mlx->c1_p = "./img_bonus/c1.xpm";
	mlx->c2_p = "./img_bonus/c2.xpm";
	mlx->c3_p = "./img_bonus/c3.xpm";
	mlx->c4_p = "./img_bonus/c4.xpm";
	mlx->g1_p = "./img_bonus/g1.xpm";
	mlx->g2_p = "./img_bonus/g2.xpm";
	mlx->g3_p = "./img_bonus/g3.xpm";
	mlx->g4_p = "./img_bonus/g4.xpm";
	xpm_to_image();
}

void	mlx_initializer(void)
{
	int		l;
	int		c;
	l = t_map.line_length * 128;
	c = t_map.map_line_count * 128;
	mlx->init = mlx_init();
	xpm_img_path();
	printf("a");
	mlx->win = mlx_new_window(mlx->init, l, c, "so_long_bonus");
	win_initializer();
	mlx_hook(mlx->win, 17, 0, &ft_exit, NULL);
	mlx_loop_hook(mlx->init, &loop_animator, (void*)&mlx);
	mlx_hook(mlx->win, 2, 0, &player_movement, mlx);
	mlx_loop(mlx->init);
}
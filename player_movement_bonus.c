#include "so_long_bonus.h"

void	move_left(int *step, t_mlx **mlx)
{
	if (t_map.map[t_map.plyr_row][t_map.plyr_col - 1] != '1')
	{
		(*step)++;
		if (t_map.map[t_map.plyr_row][t_map.plyr_col - 1] == 'X')
			ft_exit(404, (*mlx));
		if (t_map.map[t_map.plyr_row][t_map.plyr_col] == 'E')
			put_img('E', t_map.plyr_col, t_map.plyr_row, *mlx);
		else
			put_img('0', t_map.plyr_col, t_map.plyr_row, *mlx);
		t_map.plyr_col--;
		(*mlx)->p = (*mlx)->pl;
		if (t_map.map[t_map.plyr_row][t_map.plyr_col] == 'E')
		{
			exit_checker(mlx);
			return ;
		}
		if (t_map.map[t_map.plyr_row][t_map.plyr_col] == 'C')
		{
			t_map.map[t_map.plyr_row][t_map.plyr_col] = '0';
			t_map.current_coin++;
			coin_checker(mlx);
		}
		put_img('P', t_map.plyr_col, t_map.plyr_row, *mlx);
	}
}

void	move_right(int *step, t_mlx **mlx)
{
	if (t_map.map[t_map.plyr_row][t_map.plyr_col + 1] != '1')
	{
		(*step)++;
		if (t_map.map[t_map.plyr_row][t_map.plyr_col + 1] == 'X')
			ft_exit(404, (*mlx));
		if (t_map.map[t_map.plyr_row][t_map.plyr_col] == 'E')
			put_img('E', t_map.plyr_col, t_map.plyr_row, *mlx);
		else
			put_img('0', t_map.plyr_col, t_map.plyr_row, *mlx);
		t_map.plyr_col++;
		(*mlx)->p = (*mlx)->pr;
		if (t_map.map[t_map.plyr_row][t_map.plyr_col] == 'E')
		{
			exit_checker(mlx);
			put_img('M', t_map.plyr_col, t_map.plyr_row, *mlx);
			return ;
		}
		if (t_map.map[t_map.plyr_row][t_map.plyr_col] == 'C')
		{
			t_map.map[t_map.plyr_row][t_map.plyr_col] = '0';
			t_map.current_coin++;
			coin_checker(mlx);
		}
		put_img('P', t_map.plyr_col, t_map.plyr_row, *mlx);
	}
}

void	move_up(int *step, t_mlx **mlx)
{
	if (t_map.map[t_map.plyr_row - 1][t_map.plyr_col] != '1')
	{
		(*step)++;
		if (t_map.map[t_map.plyr_row - 1][t_map.plyr_col] == 'X')
			ft_exit(404, (*mlx));
		if (t_map.map[t_map.plyr_row][t_map.plyr_col] == 'E')
			put_img('E', t_map.plyr_col, t_map.plyr_row, *mlx);
		else
			put_img('0', t_map.plyr_col, t_map.plyr_row, *mlx);
		t_map.plyr_row--;
		if (t_map.map[t_map.plyr_row][t_map.plyr_col] == 'E')
		{
			exit_checker(mlx);
			return ;
		}
		if (t_map.map[t_map.plyr_row][t_map.plyr_col] == 'C')
		{
			t_map.map[t_map.plyr_row][t_map.plyr_col] = '0';
			t_map.current_coin++;
			coin_checker(mlx);
		}
		put_img('P', t_map.plyr_col, t_map.plyr_row, *mlx);

	}
}

void	move_down(int *step, t_mlx **mlx)
{
	if (t_map.map[t_map.plyr_row + 1][t_map.plyr_col] != '1')
	{
		(*step)++;
		if (t_map.map[t_map.plyr_row + 1][t_map.plyr_col] == 'X')
			ft_exit(404, (*mlx));
		if (t_map.map[t_map.plyr_row][t_map.plyr_col] == 'E')
			put_img('E', t_map.plyr_col, t_map.plyr_row, *mlx);
		else
			put_img('0', t_map.plyr_col, t_map.plyr_row, *mlx);
		t_map.plyr_row++;
		if (t_map.map[t_map.plyr_row][t_map.plyr_col] == 'E')
		{
			exit_checker(mlx);
			return ;
		}
		if (t_map.map[t_map.plyr_row][t_map.plyr_col] == 'C')
		{
			t_map.map[t_map.plyr_row][t_map.plyr_col] = '0';
			t_map.current_coin++;
			coin_checker(mlx);
		}
		put_img('P', t_map.plyr_col, t_map.plyr_row, *mlx);
	}
}

int	player_movement(int key, t_mlx **mlx)
{
	static int	step;
	int			color;

	if (key != 0 && key != 2 && key != 1 && key != 13 && key != 53)
		return (1);
	if (key == 0)
		move_left(&step, mlx);
	else if (key == 2)
		move_right(&step, mlx);
	else if (key == 13)
		move_up(&step, mlx);
	else if (key == 1)
		move_down(&step, mlx);
	else if (key == 53)
		ft_exit(17, *mlx);
	put_img('S', 0, 0, *mlx);
	color = (int)4294967295;
	mlx_string_put((*mlx)->init, (*mlx)->win, 35, 67, color, "step: ");
	mlx_string_put((*mlx)->init, (*mlx)->win, 75, 67, color, ft_itoa(step));
	return (0);
}

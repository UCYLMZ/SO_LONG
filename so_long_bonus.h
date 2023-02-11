/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:36:45 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/02/11 18:36:46 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "./SRC/mlx/mlx.h"
# include "SRC/GET_NEXT_LINE/get_next_line.h"
# include <fcntl.h>

struct		s_map
{
	char	**map;
	int		map_line_count;
	int		line_length;
	int		shortest_line;
	int		plyr_col;
	int		plyr_row;
	int		exit_col;
	int		exit_row;
	int		gate_col;
	int		gate_row;
	int		enemy_count;
	int		enemy_col;
	int		enemy_row;
	char	enemy_way;
	int		enemy_flag;
	int		coin_count;
	int		current_coin;
	int		color;
}			t_map;

typedef struct s_mlx
{
	char	*w_p;
	char	*f_p;
	char	*s_p;

	char	*p_p;
	char	*pr_p;
	char	*pl_p;

	char	*c1_p;
	char	*c2_p;
	char	*c3_p;
	char	*c4_p;
	int		coin_anim_count;

	char	*g1_p;
	char	*g2_p;
	char	*g3_p;
	char	*g4_p;

	char	*m_p;

	char	*e1_p;
	char	*e2_p;
	int		enemy_anim_count;

	char	*go_p;
	char	*yw_p;

	char	*f;
	char	*w;
	char	*s;

	char	*p;
	char	*pr;
	char	*pl;

	char	*c1;
	char	*c2;
	char	*c3;
	char	*c4;

	char	*g;
	char	*g1;
	char	*g2;
	char	*g3;
	char	*g4;

	char	*m;

	char	*e;
	char	*e1;
	char	*e2;

	char	*go;
	char	*yw;

	int		a;
	int		b;

	int		x;
	int		y;
	int		xgo;
	int		ygo;
	int		xyw;
	int		yyw;

	void	*win;
	void	*init;
}			t_mlx;

int			map_check_bonus(void);
void		map_info_bonus(void);
int			wall_checker13(char **map);
void		error_messager(int result);
char		*ft_strdup(const char *s1);
char		*ft_itoa(int n);
int			path_checker(void);
char		**map_duplicator(void);
void		map_free(char **map);
void		shortest_line_func(char **map);
int			ft_exit(int key, t_mlx *mlx);
int			ft_movement(int key, t_mlx *mlx);
void		put_img(char c, int x, int y, t_mlx *mlx);
void		mlx_initializer(t_mlx *mlx);
void		ft_putnbr(int n);
void		ft_putstr(char *str);
void		enemy_way_check(char **map, int col, int row);
int			loop_animator(t_mlx **mlx);
void		coin_animator(t_mlx **mlx);
void		exit_checker(t_mlx **mlx);
int			player_movement(int key, t_mlx **mlx);
void		coin_checker(t_mlx **mlx);
void		enemy_animate(int a, t_mlx **mlx, char **map);
void		way_setter(void);
void		enemy_animator(t_mlx *mlx);
#endif
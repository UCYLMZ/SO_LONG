/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:36:52 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/02/11 18:36:53 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "SRC/GET_NEXT_LINE/get_next_line.h"
# include <fcntl.h>
# include "./SRC/mlx/mlx.h"

struct	s_map
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
	int		coin_count;
	int		current_coin;
} t_map;

typedef struct s_mlx
{
	char	*p_p;
	char	*w_p;
	char	*c_p;
	char	*g_p;
	char	*f_p;
	char	*m_p;

	int		x;
	int		y;

	int		x1;
	int		y1;

	char	*p;
	char	*w;
	char	*c;
	char	*g;
	char	*f;
	char	*m;

	int		a;
	int		b;

	void	*win;
	void	*init;
}	t_mlx;

int		map_check(void);
void	map_info(void);
int		wall_checker13(char **map);
void	error_messager(int result);
char	*ft_strdup(const char *s1);
int		path_checker(void);
char	**map_duplicator(void);
void	map_free(char **map);
void	shortest_line_func(char **map);
int		ft_exit(int key, t_mlx *mlx);
int		ft_movement(int key, t_mlx *mlx);
void	put_img(t_mlx *mlx, char **map);
void	mlx_filler(t_mlx *mlx);
void	ft_putnbr(int n);
void	ft_putstr(char *str);

#endif
#ifndef SO_LONG_H
# define SO_LONG_H
# include "SRC/GET_NEXT_LINE/get_next_line.h"
# include <fcntl.h>
# include "./mlx/mlx.h"

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
	int		enemy_col;
	int		enemy_row;
	int		coin_count;
	int		current_coin;
} t_map;

typedef struct s_mlx
{
	char	*pl_p;
	char	*plr_p;
	char	*pll_p;
	char	*pr_p;
	char	*prr_p;
	char	*prl_p;

	char	*w_p;

	char	*c1_p;
	char	*c2_p;
	char	*c3_p;
	char	*c4_p;

	char	*g1_p;
	char	*g2_p;
	char	*g3_p;
	char	*g4_p;

	char	*f_p;
	char	*m_p;
	char	*e1_p;
	char	*e2_p;

	int		coin_anim_count;

	int		x;
	int		y;

	char	*f;
	char	*m;
	char	*w;

	char	*p;
	char	*pr;
	char	*pl;
	char	*prl;
	char	*prr;
	char	*pll;
	char	*plr;

	char	*c1;
	char	*c2;
	char	*c3;
	char	*c4;

	char	*g1;
	char	*g2;
	char	*g3;
	char	*g4;

	char	*e1;
	char	*e2;

	int		a;
	int		b;

	void	*win;
	void	*init;
}	t_mlx;

t_mlx	*mlx;

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
void	put_img(char c, int x, int y);
void 	mlx_initializer(void);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
int		loop_animator(t_mlx *mlx);
void	coin_animator(t_mlx *mlx);
int	player_movement(int key, void *ptr);
#endif
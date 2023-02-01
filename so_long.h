#ifndef SO_LONG_H
# define SO_LONG_H
# include "SRC/GET_NEXT_LINE/get_next_line.h"
# include "SRC/PRINTF/ft_printf.h"
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

	int		x;
	int		y;

	int		x1;
	int		y1;

	int p_col;
	int p_row;

	char	*p;
	char	*w;
	char	*c;
	char	*g;
	char	*f;

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
int	ft_movement(int key, t_mlx *mlx);
void	put_img(t_mlx *mlx, char **map);

#endif
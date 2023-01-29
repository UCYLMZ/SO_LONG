#ifndef SO_LONG_H
# define SO_LONG_H
# include "SRC/GET_NEXT_LINE/get_next_line.h"
# include "SRC/PRINTF/ft_printf.h"
# include <fcntl.h>
# include "./mlx/mlx.h"

struct	s_map
{
	char	**map;
	int		**coin_index;
	int		map_line_count;
	int		line_length;
	int		shortest_line;
	int		plyr_col;
	int		plyr_row;
	int		exit_col;
	int		exit_row;
	int		coin_count;
} t_map;

typedef	struct	s_mlx
{
	char	*player_path;
	char	*wall_path;
	char	*coin_path;
	char	*gate_path;
	char	*floor_path;

	int		x;
	int		y;

	char	*player;
	char	*wall;
	char	*coin;
	char	*gate;
	char	*floor;

	int		a;
	int		b;

	void	*win;
	void	*mlx_init;
}	t_mlx;

int		map_check(void);
void	map_info(void);
int		wall_checker13(char **map);
void	error_messager(int result);
char	*ft_strdup(const char *s1);
int		path_checker(void);
char	**map_duplicator(void);
void	map_free(char **map);
void	coins_free(int **arr);
void	shortest_line_func(char **map);

#endif
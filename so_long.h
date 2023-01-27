#ifndef SO_LONG_H
# define SO_LONG_H
# include "SRC/GET_NEXT_LINE/get_next_line.h"
# include "SRC/PRINTF/ft_printf.h"
# include <fcntl.h>

struct	s_map
{
	char	**map;
	int		**coin_index;
	int 	map_line_count;
	int		line_length;
	int 	plyr_col;
	int 	plyr_row;
	int 	exit_col;
	int 	exit_row;
	int		coin_count;
} t_map;

int		map_check(void);
void	map_info(void);
int		wall_checker13(char **map);
void	error_messager(int result);
char	*ft_strdup(const char *s1);

#endif
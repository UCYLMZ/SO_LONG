/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:37:02 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/02/11 18:37:03 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free (map[i]);
		i++;
	}
	free (map[i]);
	free (map);
}

int	ft_exit(int key, t_mlx *mlx)
{
	(void)key;
	mlx_destroy_window(mlx->init, mlx->win);
	map_free(t_map.map);
	free(mlx);
	exit (0);
}

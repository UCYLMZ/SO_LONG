/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_animate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:35:33 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/02/11 18:35:38 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	loop_animator(t_mlx **mlx)
{
	coin_animator(mlx);
	enemy_animator(*mlx);
	if (t_map.plyr_col == t_map.enemy_col && t_map.plyr_row == t_map.enemy_row)
		ft_exit(404, *mlx);
	return (0);
}

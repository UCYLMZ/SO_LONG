/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:34:17 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/02/11 18:34:18 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(void)
{
	t_mlx	*mlx;

	map_info_bonus();
	if (map_check_bonus())
		return (1);
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (2);
	mlx_initializer(mlx);
}

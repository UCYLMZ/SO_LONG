/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:51:55 by uyilmaz           #+#    #+#             */
/*   Updated: 2022/10/27 18:05:01 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(char *str, int *count)
{
	int	len;

	len = 0;
	if (!str)
	{
		*count += (write (1, "(null)", 6));
		return ;
	}
	while (str[len])
		len++;
	*count += write (1, str, len);
}

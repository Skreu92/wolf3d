/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 13:50:38 by etranchi          #+#    #+#             */
/*   Updated: 2017/05/27 13:50:39 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void ft_error(void)
{
	ft_putstr("Error.\n");
	exit(0);
}

void ft_print_line(int x, int start, int end, int color, void *mlx, void *win)
{
	int i = 0;

	while (i < end - start)
	{
		mlx_pixel_put(mlx, win, x, (start + i), color);
		i++;
	}
}
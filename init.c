/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 22:01:24 by Etienne           #+#    #+#             */
/*   Updated: 2017/05/29 22:01:26 by Etienne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_init_mlx(t_map *w)
{
	w->mlx = mlx_init();
	w->win = mlx_new_window(w->mlx, WIDTH, HEIGHT, "Wolf3D");
	w->img = mlx_new_image(w->mlx, WIDTH, HEIGHT);
	w->add = (char *)mlx_get_data_addr(w->img, &(w->bits),
			&(w->len), &(w->endian));
	ft_set_rays(w);
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	//mlx_key_hook(w->win, ft_key, w);
	mlx_hook(w->win, 2, 0, ft_key, w);
	mlx_hook(w->win, 17, 17, ft_leave_window, w);
	mlx_loop(w->mlx);
}

void	ft_set_rays(t_map *w)
{
	double	rx;
	double	ry;
	double	angle;

	w->col = 0;
	angle = w->angle - (M_PI / 6);
	rx = cos(angle);
	ry = sin(angle);
	while (angle < w->angle + (M_PI / 6))
	{
		rx = cos(angle);
		ry = sin(angle);
		w->rx = rx;
		w->ry = ry;
		w->tmp_angle = angle;
		ft_go_to_wall(w);
		angle += M_PI / 3 / WIDTH;
		w->col++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 21:57:58 by Etienne           #+#    #+#             */
/*   Updated: 2017/06/03 16:11:29 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			ft_check_pos(t_map *w)
{
	if (w->matrice[(int)w->posy][(int)w->posx] == 1)
		return (0);
	return (1);
}

void		move_left_right(t_map *w, int key)
{
	if (key == 123)
	{
		w->posy -= 0.2 * cos(w->angle);
		w->posx += 0.2 * sin(w->angle);
		if (ft_check_pos(w) == 0)
		{
			w->posy += 0.2 * cos(w->angle);
			w->posx -= 0.2 * sin(w->angle);
		}
	}
	if (key == 124)
	{
		w->posy += 0.2 * cos(w->angle);
		w->posx -= 0.2 * sin(w->angle);
		if (ft_check_pos(w) == 0)
		{
			w->posy -= 0.2 * cos(w->angle);
			w->posx += 0.2 * sin(w->angle);
		}
	}
}

void		move_up_down(t_map *w, int key)
{
	if (key == 126)
	{
		w->posy += 0.2 * sin(w->angle);
		w->posx += 0.2 * cos(w->angle);
		if (ft_check_pos(w) == 0)
		{
			w->posy -= 0.2 * sin(w->angle);
			w->posx -= 0.2 * cos(w->angle);
		}
	}
	if (key == 125)
	{
		w->posy -= 0.2 * sin(w->angle);
		w->posx -= 0.2 * cos(w->angle);
		if (ft_check_pos(w) == 0)
		{
			w->posy += 0.2 * sin(w->angle);
			w->posx += 0.2 * cos(w->angle);
		}
	}
}

void		change_orientation(t_map *w, int key)
{
	if (key == 0)
		w->angle -= M_PI_2 / 12;
	if (key == 2)
		w->angle += M_PI_2 / 12;
}

int			ft_key(int key, t_map *w)
{
	if (key == 53)
		exit(0);
	move_left_right(w, key);
	move_up_down(w, key);
	change_orientation(w, key);
	free(w->add);
	w->img = mlx_new_image(w->mlx, WIDTH, HEIGHT);
	w->add = mlx_get_data_addr(w->img, &(w->bits),
			&(w->len), &(w->endian));
	ft_set_rays(w);
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	return (0);
}


int		ft_leave_window(t_map *w)
{
	mlx_destroy_image(w->mlx,w->img);
	mlx_destroy_window(w->mlx, w->win);
	exit(0);
	return (0);
}
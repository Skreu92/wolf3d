/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 16:54:03 by Etienne           #+#    #+#             */
/*   Updated: 2017/06/01 16:54:06 by Etienne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_check_wall(t_map *w, double i)
{
	double	tmpx;
	double	tmpy;
	int		x;
	int		y;

	w->color = 1;
	tmpx = w->posx + (w->rx * i);
	x = (int)tmpx;
	tmpy = w->posy + (w->ry * i);
	y = (int)tmpy;
	if (w->matrice[y] && w->matrice[y][x] && w->matrice[y][x] == 1)
	{
		ft_check_orientation(w, x, y, i);
		return (1);
	}
	return (0);
}

void	ft_check_orientation(t_map *w, double x, double y, double i)
{
	double tmpx;
	double tmpy;
	double tmp;

	tmpx = w->posx + (w->rx * i);
	tmpy = w->posy + (w->ry * i);
	x += 0.5;
	tmp = hypot(x - tmpx, y - tmpy);
	x -= 0.5;
	y += 0.5;
	if (hypot(x - tmpx, y - tmpy) < tmp)
	{
		tmp = hypot(x - tmpx, y - tmpy);
		w->color = 2;
	}
	x += 1;
	if (hypot(x - tmpx, y - tmpy) < tmp)
	{
		tmp = hypot(x - tmpx, y - tmpy);
		w->color = 3;
	}
	x -= 0.5;
	y += 0.5;
	(hypot(x - tmpx, y - tmpy) < tmp) ? w->color = 4 : 0;
	(ft_near_other(tmpx, tmpy, x - 0.5, y - 1) == 1) ? w->color = 0 : 0;
}

void	ft_go_to_wall(t_map *w)
{
	double	i;
	int		a;
	int		color;

	i = 0;
	a = 0;
	color = 0;
	while (w->posx + (w->rx * i) < w->w_matrice && w->posy +
		(w->ry * i) < w->h_matrice && a == 0 && w->posx + (w->rx
			* i) >= 0 && w->posy + (w->ry * i) >= 0 && a == 0)
	{
		if (ft_check_wall(w, i) == 1)
		{
			i -= 0.1;
			while (ft_check_wall(w, i) != 1)
				i += 0.001;
			a = 1;
			ft_draw_ray(w, i);
		}
		i += 0.1;
	}
}

int		ft_near_other(double tmpx, double tmpy, double x, double y)
{
	int a;

	a = 0;
	(hypot(x - tmpx, y - tmpy) < 0.01) ? a++ : 0;
	(hypot(x + 1 - tmpx, y - tmpy) < 0.01) ? a++ : 0;
	(hypot(x - tmpx, y + 1 - tmpy) < 0.01) ? a++ : 0;
	(hypot(x + 1 - tmpx, y + 1 - tmpy) < 0.01) ? a++ : 0;
	if (a != 0)
		return (1);
	return (0);
}

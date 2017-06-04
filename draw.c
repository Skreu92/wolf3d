/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 17:45:33 by Etienne           #+#    #+#             */
/*   Updated: 2017/06/03 16:03:14 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_draw_ray(t_map *w, double a)
{
	int i;
	int height;

	a = a * cos(w->tmp_angle - w->angle);
	height = WIDTH / a / 2;
	i = HEIGHT / 2 - height;
	(i < 0) ? i = 0 : 0;
	ft_color(w);
	while (i < HEIGHT/ 2 + height && i < HEIGHT && i >= 0 && w->col < WIDTH)
		ft_draw(w, w->col, i++);
	w->red = 0;
	w->blue = 0;
	w->green = 0;
	while (i < HEIGHT - 1 && i > 0 && w->col < WIDTH)
	{
		ft_draw(w, w->col, i++);
		if (w->red < 255)
		{
			w->red++;
			w->blue++;
			w->green++;
		}
	}
}

void	ft_draw(t_map *w, float x, float y)
{
	int nb;

	nb = (x * w->bits) / 8 + (y * w->len);
	w->add[nb] = w->red;
	w->add[nb + 1] = w->green;
	w->add[nb + 2] = w->blue;
}

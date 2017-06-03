/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 17:49:38 by Etienne           #+#    #+#             */
/*   Updated: 2017/06/01 17:49:40 by Etienne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_set_f_colors(t_map *w)
{
	if (w->color == 0)
	{
		w->red = 0;
		w->green = 0;
		w->blue = 0;
	}
	if (w->color == 1)
	{
		w->red = 90;
		w->green = 170;
		w->blue = 0;
	}
}

void	ft_color(t_map *w)
{
	ft_set_f_colors(w);
	if (w->color == 2)
	{
		w->red = 0;
		w->blue = 200;
		w->green = 145;
	}
	if (w->color == 3)
	{
		w->red = 150;
		w->green = 0;
		w->blue = 0;
	}
	if (w->color == 4)
	{
		w->red = 145;
		w->blue = 145;
		w->green = 0;
	}
}

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

void ft_print_line(int x, int start, int end, int color, t_map *w)
{
	char color1;
	char color2;
	char color3;
	int y;
	int tmp;
	color1 = (w->color & 0xFFFFFF00) >> 24;
	color2 = (w->color & 0xFFFFFF) >> 16;
	color3 = (w->color & 0xFFFF) >> 8;
	y = 0;
	while (y < abs(end - start))
	{
		w->add[ (start + y) * WIDTH + x ] = color;
		//w->add[ y * WIDTH + x * 4+ 1] = color2;
		//w->add[y * WIDTH + x * 4+ 2] = color1;
		y++;
	}

}




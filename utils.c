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
	int y;
	unsigned char color1;
	unsigned char color2;
	unsigned char color3;

	y = start;
	color1 = (color & 0xFF0000) << 16;
	color2 = (color & 0xFF00) << 8;
	color3 = (color & 0xFF) << 4;
	printf("%d %d %d\n",color3, color2, color1 );
	printf("x%d y%d end %d\n", x, y, end);
	while (y < end)
	{
		w->add[y * WIDTH + x] = color3;
		w->add[y * WIDTH + x + 1] = color2;
		w->add[y * WIDTH + x + 2] = color1;
		y++;
	}
	printf("aaa %d\n",x );
}
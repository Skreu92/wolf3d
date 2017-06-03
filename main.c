/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 13:37:34 by etranchi          #+#    #+#             */
/*   Updated: 2017/06/03 16:01:36 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	main(int ac, char **av)
{
	t_map *w;

	if (ac != 2)
		ft_error();
	w = parse_to_tab(av[1]);
	w->angle = M_PI_2;
	w->red = 0;
	w->green = 0;
	w->blue = 0;
	w->col = 0;
	w->posx = 1.5;
	w->posy = 1.5;
	ft_init_mlx(w);
	return (0);
}

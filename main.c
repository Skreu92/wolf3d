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

void		check_tab(t_map *w)
{
	int i;
	int j;
	int a;

	i = 0;
	while (i++ < w->h_matrice - 1)
	{
		j = 0;
		while (j++ < w->w_matrice - 1)
		{
			a = 0;
			if (w->matrice[i][j] == 1)
				if (w->matrice[i + 1][j + 1] == 1)
					if (w->matrice[i][j + 1] == 0 && w->matrice[i + 1][j] == 0)
						a++;
			if (w->matrice[i][j] == 1)
				if (w->matrice[i + 1][j - 1] == 1)
					if (w->matrice[i][j - 1] == 0 && w->matrice[i + 1][j] == 0)
						a++;
			if (a != 0)
				ft_error();
		}
	}
}

int			main(int ac, char **av)
{
	t_map *w;

	if (ac != 2)
		ft_error();
	w = parse_to_tab(av[1]);
	check_tab(w);
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

int			ft_leave_window(t_map *w)
{
	mlx_destroy_image(w->mlx, w->img);
	mlx_destroy_window(w->mlx, w->win);
	exit(0);
	return (0);
}

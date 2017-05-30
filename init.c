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

t_map *ft_init_mlx(void)
{
	t_map *w;

	if (!(w = (t_map *)malloc(sizeof(t_map))))
		ft_error();
	w->bpp = (int *)malloc(sizeof(int));
	w->bpl = (int *)malloc(sizeof(int));
	w->end = (int *)malloc(sizeof(int));
	w->camera = (t_pdou *)malloc(sizeof(t_pdou));
	w->rayPos = (t_pdou *)malloc(sizeof(t_pdou));
	w->rayDir = (t_pdou *)malloc(sizeof(t_pdou));
	w->step = (t_pint *)malloc(sizeof(t_pint));
	w->map = (t_pint *)malloc(sizeof(t_pint));
	w->deltaDist = (t_pdou *)malloc(sizeof(t_pdou));
	w->mlx = mlx_init();
	w->win = mlx_new_window(w->mlx, WIDTH, HEIGHT, "Wolf3D");
	w->img = mlx_new_image(w->mlx, WIDTH, HEIGHT);
	w->add = (char *)mlx_get_data_addr(w->img, w->bpp, w->bpl, w->end);
	init_double_pdp(w);

	return (w);
}

void ft_init_db(t_pdou *p, double x, double y)
{
	p->x = x;
	p->y = y;
}

void init_double_pdp(t_map *w)
{
	w->pos = (t_pdou *)malloc(sizeof(t_pdou));
	w->dir = (t_pdou *)malloc(sizeof(t_pdou));
	w->plane = (t_pdou *)malloc(sizeof(t_pdou));
	w->pos->x = 22;
	w->pos->y = 12;
	w->dir->x = -1;
	w->dir->y = 0;
	w->plane->x = 0;
	w->plane->y = 0.66;
}
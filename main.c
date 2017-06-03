/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 13:37:34 by etranchi          #+#    #+#             */
/*   Updated: 2017/05/27 13:37:36 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>
#include <time.h>
#include <string.h>


int main(int ac, char **av)
{
	t_map *w;

  if (ac != 2)
    ft_error();
  w = parse_to_tab(av[1]);
  w->angle = 0.5 * M_PI_2;
  w->red = 255;
  w->green = 0;
  w->blue = 0;
  w->col = 0;
  w->posx =  1.1 ;
  w->posy =  1.1;
  ft_init_mlx(w);    
  return (0);

}

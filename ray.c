/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 22:21:54 by Etienne           #+#    #+#             */
/*   Updated: 2017/05/29 22:21:56 by Etienne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void ft_ray(t_map *w)
{
	w->x = 0;
	while (w->x < WIDTH)
	{
		ft_init_position(w, w->x);
		w->x++;
	}
}
void ft_go_hit(t_map *w, t_pdou *sideDist)
{
	while (w->hit == 0)
      {
        if (sideDist->x < sideDist->y)
        {
          sideDist->x += w->deltaDist->x;
          w->map->x += w->step->x;
          w->side = 0;
        }
        else
        {
          sideDist->y += w->deltaDist->y;
          w->map->y += w->step->y;
          w->side = 1;
        }
        if (worldMap[w->map->x][w->map->y] > 0) 
        	w->hit = 1;
      }
      if (w->side == 0) 
      	w->perpWallDist = (w->map->x - w->rayPos->x + (1 - w->step->x) / 2) / w->rayDir->x;
      else           
      	w->perpWallDist = (w->map->y - w->rayPos->y + (1 - w->step->y) / 2) / w->rayDir->y;
}
void go_check_around(t_map *w)
{
	t_pdou *sideDist;

	if(!(sideDist = (t_pdou *)malloc(sizeof(t_pdou))))
		ft_error();
	if (w->rayDir->x < 0)
      {
        w->step->x = -1;
        sideDist->x = (w->rayPos->x - w->map->x) * w->deltaDist->x;
      }
      else
      {
        w->step->x = 1;
        sideDist->x = (w->map->x + 1.0 - w->rayPos->x) * w->deltaDist->x;
      }
      if (w->rayDir->y < 0)
      {
        w->step->y = -1;
        sideDist->y = (w->rayPos->y - w->map->y) * w->deltaDist->y;
      }
      else
      {
        w->step->y = 1;
        sideDist->y = (w->map->y + 1.0 - w->rayPos->y) * w->deltaDist->y;
      }
      ft_go_hit(w, sideDist);
}

void ft_begin_draw(t_map *w)
{
	//Calculate height of line to draw on screen
      int lineHeight; 
      int drawStart;
      int drawEnd;
      int color;

      lineHeight = (int)(HEIGHT / w->perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      printf("lineH%d\n",lineHeight);
      drawStart = -lineHeight / 2 + HEIGHT / 2;
      if(drawStart < 0)
      	drawStart = 0;
 
      drawEnd = lineHeight / 2 + HEIGHT / 2;
      if(drawEnd >= HEIGHT)
      	drawEnd = HEIGHT - 1;

      //choose wall color
      color = 0xFFFF00;
      //give x and y sides different brightness
      if (w->side == 1) 
      {
      	color = color / 2;
      }
      //draw the pixels of the stripe as a vertical line
      printf("kkk\n");
      ft_print_line(w->x, drawStart, drawEnd, color, w);
}
void ft_init_position(t_map *w, int x)
{
	w->camera->x = 2 * x / (double)(WIDTH) - 1;
	ft_init_db(w->rayPos, WIDTH, HEIGHT);
	ft_init_db(w->rayDir, w->dir->x + w->plane->x * w->camera->x, w->dir->y + w->plane->y * w->camera->x);
	ft_init_db(w->deltaDist, sqrt(1 + (w->rayDir->y * w->rayDir->y) / (w->rayDir->x * w->rayDir->x)), sqrt(1 + (w->rayDir->x * w->rayDir->x) / (w->rayDir->y * w->rayDir->y)));
	w->map->x = (int)w->rayPos->x;
	w->map->y = (int)w->rayPos->y;
	w->hit = 0;
	go_check_around(w);
  printf("coucou\n");
	ft_begin_draw(w);
}
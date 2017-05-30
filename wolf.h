/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 13:37:42 by etranchi          #+#    #+#             */
/*   Updated: 2017/05/27 13:37:43 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

#include "fcntl.h"
#include "libft/libft.h"
#include "minlibx/mlx.h"
#include <math.h>

#define WIDTH 512
#define HEIGHT 384
#define mapWidth 24
#define mapHeight 24


typedef struct 	s_line
{
	int 	*tab;
	int 	width;
	struct s_line *next;
}				t_line;

typedef struct s_pdou
{
	double x;
	double y;
}			t_pdou;

typedef struct s_pint
{
	int x;
	int y;
}				t_pint;
typedef struct 	s_map
{

	void		*mlx;
	void		*win;
	void		*img;
	char		*add;
	int			*bpp;
	int			*bpl;
	int			*end;
	t_pdou		*pos;
	t_pdou		*plane;
	t_pdou		*dir;


	t_pdou *camera;
	t_pdou *rayPos;
	t_pdou *rayDir;
	t_pint *step;
	t_pint *map;
	t_pdou *deltaDist;
	int side;
	int hit;
	double perpWallDist;
	int x;
}				t_map;

void ft_init_position(t_map *w, int x);
int ft_key(int key, void *w);
void ft_init_db(t_pdou *p, double x, double y);
void init_double_pdp(t_map *w);
t_map *ft_init_mlx(void);
void ft_ray(t_map *w);
t_map *parse_to_tab(char *str);
t_line		*create_lst_line(int fd);
t_line		*create_each_line(char **tab);
void	ft_error(void);
void ft_print_line(int x, int start, int end, int color, t_map *w);
#endif

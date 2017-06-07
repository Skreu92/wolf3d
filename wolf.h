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

# include "fcntl.h"
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define WIDTH 1280
# define HEIGHT 800

typedef struct		s_line
{
	int				*tab;
	int				width;
	struct s_line	*next;
}					t_line;

typedef struct		s_map
{
	int				**matrice;
	int				w_matrice;
	int				h_matrice;

	void			*mlx;
	void			*win;
	char			*add;
	void			*img;
	int				bits;
	int				len;
	int				endian;

	double			posx;
	double			posy;
	double			angle;
	double			tmp_angle;
	double			rx;
	double			ry;
	int				red;
	int				green;
	int				blue;
	int				color;
	int				col;
	int				tmp_len;
	int				k_status;
}					t_map;

int					ft_leave_window(t_map *map);
int					ft_key(int key, t_map *w);
void				ft_color(t_map *w);
void				ft_draw_ray(t_map *w, double a);
void				ft_draw(t_map *w, float x, float y);
int					ft_near_other(double tmpx, double tmpy, double x, double y);
void				ft_go_to_wall(t_map *w);
int					ft_check_wall(t_map *w, double i);
void				ft_check_orientation(t_map *w, double x, double y,
	double i);
void				ft_error(void);
int					ft_matrice_size(t_line *begin_list);
int					ft_line_len(t_line *line);
t_map				*parse_to_tab(char *str);
void				ft_init_mlx(t_map *w);
void				ft_set_rays(t_map *w);
#endif

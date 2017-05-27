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

typedef struct 	s_line
{
	int 	*tab;
	int 	width;
	struct s_line *next;
}				t_line;

typedef struct 	s_map
{
	int 	**map;
	int 	height;
	int		width;
}				t_map;

t_map *parse_to_tab(char *str);
t_line		*create_lst_line(int fd);
t_line		*create_each_line(char **tab);
void	ft_error(void);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 13:43:20 by etranchi          #+#    #+#             */
/*   Updated: 2017/05/27 16:10:22 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_line			*create_each_line(char **tab)
{
	t_line		*line;
	int			i;

	i = 0;
	while (tab[i])
		i++;
	line = (t_line *)malloc(sizeof(t_line));
	line->width = i;
	if (!(line->tab = (int *)malloc(sizeof(int) * i)))
		return (NULL);
	while (i--)
	{
		line->tab[i] = ft_atoi(tab[i]);
		free(tab[i]);
	}
	free(tab);
	line->next = NULL;
	return (line);
}

t_line			*create_lst_line(int fd)
{
	t_line		*lst_line;
	char		*str;
	t_line		*tmp;
	char		**ctn;

	lst_line = NULL;
	while ((get_next_line(fd, &str)))
	{
		ctn = ft_strsplit(str, ' ');
		if (!(lst_line))
		{
			lst_line = create_each_line(ctn);
			tmp = lst_line;
		}
		else
		{
			while (lst_line->next != NULL)
				lst_line = lst_line->next;
			lst_line->next = create_each_line(ctn);
		}
		free(str);
	}
	if (lst_line == NULL)
		ft_error();
	return (tmp);
}

void		create_tab_int(t_line *lst, t_map *w)
{
	int i;
	int j;
	t_line *tmp;

	j = 0;
	i = 0;
	while (i < w->h_matrice)
	{
		j = 0;
		while (j < w->w_matrice && lst)
		{
			w->matrice[i][j] = lst->tab[j];
			j++;
		}
		free(lst->tab);
		tmp = lst;
		lst = lst->next;
		free(tmp);
		i++;
	}

}

void check_map(t_map *w)
{

	int j;

	if(!(w->w_matrice > 2 && w->h_matrice > 2))
		ft_error();
	if(w->matrice[1][1] != 0)
		ft_error();
	j = w->w_matrice;
	while(j--)
	{
		if(w->matrice[0][j] != 1)
			ft_error();
		if(w->matrice[w->h_matrice - 1][j] != 1)
			ft_error();
	}
	printf("coucou\n");
	j = w->h_matrice;
	while (j--)
	{
		if(w->matrice[j][0] != 1)
			ft_error();
		if(w->matrice[j][w->w_matrice - 1] != 1)
			ft_error();
	}
}	

t_map			*parse_to_tab(char *str)
{
	int			fd;
	t_map		*w;
	t_line		*lst_line;
	int 		i;

	if (!(fd = open(str, O_RDONLY)))
		ft_error();
	if (!(w = (t_map *)malloc(sizeof(t_map))))
		ft_error();
	lst_line = create_lst_line(fd);
	w->w_matrice = ft_line_len(lst_line);
	if (w->w_matrice == 0)
		ft_error();
	w->h_matrice = ft_matrice_size(lst_line);
	if (!(w->matrice = (int **)malloc(sizeof(int *) * w->h_matrice)))
		ft_error();
	i = -1;
	while (++i < w->h_matrice )
		if (!(w->matrice[i] = (int *)malloc(sizeof(int) * w->w_matrice)))
			ft_error();
	create_tab_int(lst_line, w);
	check_map(w);
	return (w);
}

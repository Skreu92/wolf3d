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

t_map			*parse_to_tab(char *str)
{
	int			fd;
	char		*buff;
	t_map		*map;
	t_line		*lst_line;

	if (!(fd = open(str, O_RDONLY)))
		ft_error();
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		ft_error();
	lst_line = create_lst_line(fd);
	return (map);
}

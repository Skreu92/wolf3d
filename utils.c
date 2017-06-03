/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 13:50:38 by etranchi          #+#    #+#             */
/*   Updated: 2017/05/27 13:50:39 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_error(void)
{
	ft_putstr("Error.\n");
	exit(0);
}

int			ft_line_len(t_line *line)
{
	static int i;

	i = 0;
	while (line)
	{
		if (line->width > i && i == 0)
			i = line->width;
		if (line->width != i)
			ft_error();
		line = line->next;
	}
	return (i);
}

int			ft_matrice_size(t_line *begin_list)
{
	int		i;

	i = 0;
	while (begin_list != NULL)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

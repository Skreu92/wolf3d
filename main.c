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

int main(int ac, char **av)
{
	if (ac == 2)
	{
		parse_to_tab(av[1]);
	}
	else
	{
		ft_error();
	}

	return (0);
}

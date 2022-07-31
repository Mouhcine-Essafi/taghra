/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemy_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <messafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:54:59 by messafi           #+#    #+#             */
/*   Updated: 2022/07/31 16:53:14 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_move_enemy(t_save *g, int i, int j)
{
	// if (g->map[i][j + 1] == 'P' || g->map[i][j - 1] == 'P')
	// {
	// 	ft_printf("You lose\nGame over\n");
	// 	ft_close(g);
	// }
	if (g->map[i][j + 1] != '0' && g->map[i][j + 1] != 'P')
		g->move = 1;
	else if (g->map[i][j - 1] != '0' && g->map[i][j - 1] != 'P')
		g->move = 0;
	if (g->move == 0) //&& g->map[i][j + 1] == '0')
	{
		if (g->map[i][j + 1] == 'P')
			ft_close(g);
		g->map[i][j] = '0';
		g->map[i][j + 1] = 'N';
		return (1);
	}
	else if (g->move == 1) //&& g->map[i][j - 1] == '0')
	{
		if (g->map[i][j - 1] == 'P')
			ft_close(g);
		g->map[i][j] = '0';
		g->map[i][j - 1] = 'N';
	}
	return (0);
}

int	ft_enemy(t_save *g)
{
	int	i;
	int	j;

	if (g->emove == 5000)
	{
		i = 0;
		while (g->map[i])
		{
			j = 0;
			while (g->map[i][j])
			{
				if (g->map[i][j] == 'N')
				{	
					if (ft_move_enemy(g, i, j) == 1)
						j++;
				}
				j++;
			}
			i++;
		}
		ft_draw_map(g->map, g);
		g->emove = 0;
	}
	g->emove++;
	return (0);
}

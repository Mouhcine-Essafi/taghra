/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_u_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <messafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:31:36 by messafi           #+#    #+#             */
/*   Updated: 2022/07/29 16:58:15 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t	ft_strlen2(char **map)
{
	size_t		i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i);
}

void	ft_error(int a)
{
	if (a == 0)
	{
		ft_printf("Error\nundifined argumets\n");
		exit (0);
	}
	else if (a == 1)
	{
		ft_printf("Error\ninvalid map\n");
		exit (0);
	}
	else if (a == 3)
	{
		ft_printf("Error\ninvalid path\n");
		exit (0);
	}
	else if (a == 4)
	{
		ft_printf("Error\nempty map\n");
		exit (0);
	}
}

int	ft_handle_key(int key, t_save *g)
{
	char	c;

	c = 0;
	if (key == 123 || key == 0)
		c = 'A';
	else if (key == 124 || key == 2)
		c = 'D';
	else if (key == 125 || key == 1)
		c = 'S';
	else if (key == 126 || key == 13)
		c = 'W';
	else if (key == 53)
		ft_close(g);
	ft_move_player(g, c);
	return (0);
}

void	ft_player_position(t_save *g, char c)
{
	g->i = 0;
	while (g->map[++g->i] != '\0')
	{
		g->j = 0;
		while (g->map[g->i][g->j] != '\0')
		{
			if (g->map[g->i][++g->j] == 'P')
			{
				if (c == 'D')
					g->s = ft_right_side(g, g->i, g->j);
				else if (c == 'A')
					g->s = ft_left_side(g, g->i, g->j);
				else if (c == 'S')
					g->s = ft_down(g, g->i, g->j);
				else if (c == 'W')
					g->s = ft_up(g, g->i, g->j);
				return ;
			}
		}
	}
}

int	check_map2(char **map, t_save g)
{
	g.i = 0;
	g.j = 0;
	while (map[g.i] != '\0')
	{
		g.j = 0;
		while ((map[g.i][g.j]) != '\0')
		{
			if (map[g.i][g.j] == 'P')
				g.p++;
			else if (map[g.i][g.j] == 'E')
				g.e++;
			else if (map[g.i][g.j] == 'C')
				g.c++;
			g.j++;
		}
		g.i++;
	}
	if (g.p != 1 || g.e < 1 || g.c < 1)
		return (0);
	return (1);
}

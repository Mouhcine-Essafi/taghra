/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <messafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:35:02 by messafi           #+#    #+#             */
/*   Updated: 2022/07/26 12:35:29 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_player(t_save *g, char c)
{
	ft_player_position(g, c);
	if ((g->s == 3 && g->nbr_of_colc == 0))
	{
		ft_printf("Move number: %d\n", g->nbr_of_move + 1);
		ft_printf("You win\nGame over\n");
		ft_close(g);
	}
	else if (g->s == 1 || g->s == 2)
	{
		g->nbr_of_move++;
		ft_modify_map(g, g->s, c);
		ft_put_new_images(g, g->s, c);
		ft_printf("Move number: %d\n", g->nbr_of_move);
	}
}

int	ft_right_side(t_save *g, int i, int j)
{
	if (g->map[i][j + 1] == '1')
		return (0);
	else if (g->map[i][j + 1] == '0')
		return (1);
	else if (g->map[i][j + 1] == 'C')
	{
		g->nbr_of_colc--;
		return (2);
	}
	else if (g->map[i][j + 1] == 'E')
		return (3);
	return (0);
}

int	ft_left_side(t_save *g, int i, int j)
{
	if (g->map[i][j - 1] == '1')
		return (0);
	else if (g->map[i][j - 1] == '0')
		return (1);
	else if (g->map[i][j - 1] == 'C')
	{
		g->nbr_of_colc--;
		return (2);
	}
	else if (g->map[i][j - 1] == 'E')
		return (3);
	return (0);
}

int	ft_up(t_save *g, int i, int j)
{
	if (g->map[i - 1][j] == '1')
		return (0);
	else if (g->map[i - 1][j] == '0')
		return (1);
	else if (g->map[i - 1][j] == 'C')
	{
		g->nbr_of_colc--;
		return (2);
	}
	else if (g->map[i - 1][j] == 'E')
		return (3);
	return (0);
}

int	ft_down(t_save *g, int i, int j)
{
	if (g->map[i + 1][j] == '1')
		return (0);
	else if (g->map[i + 1][j] == '0')
		return (1);
	else if (g->map[i + 1][j] == 'C')
	{
		g->nbr_of_colc--;
		return (2);
	}
	else if (g->map[i + 1][j] == 'E')
		return (3);
	return (0);
}

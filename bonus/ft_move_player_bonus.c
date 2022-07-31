/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <messafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:35:02 by messafi           #+#    #+#             */
/*   Updated: 2022/07/30 17:38:39 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move_player(t_save *g, char c)
{
	void	*l;

	g->n_move = NULL;
	l = ft_read_map('1', *g);
	ft_player_position(g, c);
	if ((g->s == 3 && g->nbr_of_colc == 0))
		ft_close(g);
	else if (g->s == 1 || g->s == 2)
	{
		g->nbr_of_move++;
		g->n_move = ft_itoa(g->nbr_of_move);
		ft_put_new_images(g, g->s, c);
		ft_modify_map(g, g->s, c);
		mlx_put_image_to_window(g->mlx, g->win, l, 1, 1);
		mlx_string_put(g->mlx, g->win, 15, 10, 0xFFFFFF, g->n_move);
	}
	free(g->n_move);
	if (g->s == 4)
		ft_close(g);
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
	else if (g->map[i][j + 1] == 'N')
		return (4);
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
	else if (g->map[i][j - 1] == 'N')
		return (4);
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
	else if (g->map[i - 1][j] == 'N')
		return (4);
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
	else if (g->map[i + 1][j] == 'N')
		return (4);
	return (0);
}

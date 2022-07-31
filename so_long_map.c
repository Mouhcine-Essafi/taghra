/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <messafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:39:43 by messafi           #+#    #+#             */
/*   Updated: 2022/07/29 16:54:41 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(char **map, t_save *g)
{
	int		i;
	int		j;
	void	*s;

	i = 0;
	j = 0;
	g->nbr_of_colc = 0;
	while (map[i] != '\0')
	{
		while (map[i][j] != '\0')
		{
			if (g->map[i][j] == 'C')
				g->nbr_of_colc++;
			s = read_map(map[i][j], *g);
			mlx_put_image_to_window(g->mlx, g->win, s, j * 50, i * 50);
			j++;
		}
		i++;
		j = 0;
	}
}

void	*read_map(char c, t_save g)
{
	void	*s;

	s = NULL;
	if (c == '0')
		s = mlx_xpm_file_to_image(g.mlx, "images/0.xpm", &g.h, &g.w);
	else if (c == '1')
		s = mlx_xpm_file_to_image(g.mlx, "images/1.xpm", &g.h, &g.w);
	else if (c == 'C')
		s = mlx_xpm_file_to_image(g.mlx, "images/C.xpm", &g.h, &g.w);
	else if (c == 'E')
		s = mlx_xpm_file_to_image(g.mlx, "images/E.xpm", &g.h, &g.w);
	else if (c == 'P')
		s = mlx_xpm_file_to_image(g.mlx, "images/P.xpm", &g.h, &g.w);
	if (!s)
		ft_close(&g);
	return (s);
}

int	check_map(char **map, t_save g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != '\0')
	{
		while ((map[i][j]) != '\0')
		{
			if ((((map[0][j]) != '1') || (map[ft_strlen2(map) - 1][j]) != '1')
				|| (((map[i][0]) != '1' )
					|| ((map[i][ft_strlen(map[i]) - 1]) != '1')))
				ft_error (1);
			if (!(ft_strchr("01CEP", map[i][j])))
				ft_error (1);
			j++;
		}
		i++;
		j = 0;
	}
	return (check_map2(map, g));
}

void	ft_modify_map(t_save *g, int s, char c)
{
	if ((c == 'D') && (s == 1 || s == 2))
	{
		g->map[g->i][g->j + 1] = 'P';
		g->map[g->i][g->j] = '0';
	}
	else if ((c == 'A') && (s == 1 || s == 2))
	{
		g->map[g->i][g->j - 1] = 'P';
		g->map[g->i][g->j] = '0';
	}
	else if ((c == 'S') && (s == 1 || s == 2))
	{
		g->map[g->i + 1][g->j] = 'P';
		g->map[g->i][g->j] = '0';
	}
	else if ((c == 'W') && (s == 1 || s == 2))
	{
		g->map[g->i - 1][g->j] = 'P';
		g->map[g->i][g->j] = '0';
	}
}

void	ft_put_new_images(t_save *g, int s, char c)
{
	void	*p;
	void	*o;

	p = read_map('P', *g);
	o = read_map('0', *g);
	if ((c == 'D') && (s == 1 || s == 2))
	{
		mlx_put_image_to_window(g->mlx, g->win, p, (g->j + 1) * 50, g->i * 50);
		mlx_put_image_to_window(g->mlx, g->win, o, g->j * 50, g->i * 50);
	}
	else if ((c == 'A') && (s == 1 || s == 2))
	{
		mlx_put_image_to_window(g->mlx, g->win, p, (g->j - 1) * 50, g->i * 50);
		mlx_put_image_to_window(g->mlx, g->win, o, g->j * 50, g->i * 50);
	}
	else if ((c == 'S') && (s == 1 || s == 2))
	{
		mlx_put_image_to_window(g->mlx, g->win, p, g->j * 50, (g->i + 1) * 50);
		mlx_put_image_to_window(g->mlx, g->win, o, g->j * 50, g->i * 50);
	}
	else if ((c == 'W') && (s == 1 || s == 2))
	{
		mlx_put_image_to_window(g->mlx, g->win, p, g->j * 50, (g->i - 1) * 50);
		mlx_put_image_to_window(g->mlx, g->win, o, g->j * 50, g->i * 50);
	}
}

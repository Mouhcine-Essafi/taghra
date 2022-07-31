/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <messafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:06:30 by messafi           #+#    #+#             */
/*   Updated: 2022/07/31 16:56:52 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_close(t_save *g)
{
	mlx_destroy_window(g->mlx, g->win);
	//system("leaks so_long");
	exit(0);
}

void	ft_all(t_save g)
{
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, ft_strlen(*g.map) * g.h,
			(ft_strlen2(g.map)) * g.w, "so_long");
	ft_draw_map(g.map, &g);
	mlx_key_hook(g.win, ft_handle_key, &g);
	mlx_hook(g.win, 17, 0, ft_close, &g);
	mlx_loop_hook(g.mlx, ft_enemy, &g);
	mlx_loop(g.mlx);
}

int	main(int ac, char **av)
{
	t_save	g;
	char	*str;

	g.h = 50;
	g.w = 50;
	if (ac != 2 || ac == 1)
		ft_error(0);
	str = ft_strnstr(av[1], ".ber", ft_strlen(av[1]));
	if (!str)
		ft_error(3);
	else if (ft_strncmp(str, ".ber", ft_strlen(av[1])))
		ft_error(3);
	g.fd = open(av[1], O_RDWR);
	if (g.fd < 0)
		return (0);
	g.str = get_next_line(g.fd);
	if (g.str == NULL)
		ft_error(4);
	g.map = ft_split(g.str, '\n');
	if (check_map(g.map, g) && (ft_strlen(*g.map) != ft_strlen2(g.map)))
		ft_all(g);
	else
		ft_error (1);
}

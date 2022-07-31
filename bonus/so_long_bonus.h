/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <messafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:03:35 by messafi           #+#    #+#             */
/*   Updated: 2022/07/30 17:29:42 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "mlx.h"
# include "get_next_line.h"
# include "libft_bonus/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_save
{
	void	*mlx;
	void	*win;
	char	*str;
	int		fd;
	char	**map;
	int		w;
	int		h;
	int		i;
	int		j;
	int		nbr_of_colc;
	int		nbr_of_p;
	int		nbr_of_move;
	int		s;
	int		p;
	int		e;
	int		c;
	int		n;
	int		move;
	int		emove;
	char	*n_move;
}	t_save;

int		check_map(char **map, t_save g);
size_t	ft_strlen2(char **map);
void	ft_error(int a);
int		ft_handle_key(int key, t_save *g);
void	ft_draw_map(char **map, t_save *g);
void	*ft_read_map(char c, t_save g);
void	ft_move_player(t_save *g, char c);
void	ft_player_position(t_save *g, char c);
int		ft_right_side(t_save *g, int i, int j);
int		ft_left_side(t_save *g, int i, int j);
int		ft_up(t_save *g, int i, int j);
int		ft_down(t_save *g, int i, int j);
void	ft_modify_map(t_save *g, int s, char c);
int		ft_close(t_save *g);
int		check_map2(char **map, t_save g);
int		ft_printf(const char *format, ...);
void	ft_put_new_images(t_save *g, int s, char c);
int		ft_move_enemy(t_save *g, int i, int j);
int		ft_enemy(t_save *g);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:45:49 by malord            #+#    #+#             */
/*   Updated: 2022/07/05 14:32:26 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include "mlx/mlx.h"
# include <stdio.h>
# include <errno.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*floor;
	void	*perso;
	void	*wall;
	void	*collectible;
	void	*enemy;
	void	*exit;
	int		moves;
	int		x;
	int		y;
	char	**map;
	int		charac;
	int		sortie;
	int		collect;
	int		column;
	int		avail;
	int		rows;
}				t_vars;

void	ft_check_mcontent(t_vars *elem, size_t column);
void	ft_check_map(t_vars *elem, size_t column);
void	ft_check_rectangle(t_vars *elem, size_t column);
void	ft_check_wall(t_vars *elem, size_t column);
int		ft_check_args(char *argu, int argc);
void	ft_go_right(t_vars *elem);
void	ft_go_left(t_vars *elem);
void	ft_go_up(t_vars *elem);
void	ft_go_down(t_vars *elem);
void	ft_exit(t_vars *elem);
void	ft_move_p_right(t_vars *elem, int i, int j);
void	ft_move_p_left(t_vars *elem, int i, int j);
void	ft_move_p_up(t_vars *elem, int i, int j);
void	ft_move_p_down(t_vars *elem, int i, int j);
void	ft_move_e_left(t_vars *elem);
void	ft_move_e_right(t_vars *elem);
void	ft_move_e_down(t_vars *elem);
void	ft_move_e_up(t_vars *elem);
void	ft_game_win(void);
void	ft_game_controls(int keycode, t_vars *vars);
void	ft_esc_key(int keycode, t_vars *vars);
void	ft_create_window(t_vars *elem);
void	ft_init_struct(t_vars *vars);
void	ft_map_to_array(t_vars *vars, int fd);
int		ft_closewin(void);
void	ft_game_over(void);
void	ft_map_size(t_vars *vars, char *argv);
void	ft_check_fd(int fd);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:45:49 by malord            #+#    #+#             */
/*   Updated: 2022/06/27 13:15:34 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include "mlx.h"
# include <stdio.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*floor;
	void	*perso;
	void	*wall;
	void	*collectible;
	void	*exit;
	int		moves;
	int		x;
	int		y;
	char	**map;
	int		charac;
	int		sortie;
	int		collect;
}				t_vars;

void	ft_check_mcontent(t_vars *elem, size_t column);
void	ft_check_map(t_vars *elem, size_t column);
void	ft_check_rectangle(t_vars *elem, size_t column);
void	ft_check_wall(t_vars *elem, size_t column);
int		ft_check_args(char *argu, int argc);
#endif

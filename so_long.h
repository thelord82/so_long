/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:45:49 by malord            #+#    #+#             */
/*   Updated: 2022/06/23 10:08:13 by malord           ###   ########.fr       */
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
}				t_vars;
#endif

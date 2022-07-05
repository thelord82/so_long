/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:49:52 by malord            #+#    #+#             */
/*   Updated: 2022/07/05 14:45:05 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

//Closes the game on ESC Key.
void	ft_esc_key(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		printf("You have exited the game. FORE !\n");
		exit(0);
	}
}

//Closes the game (called on mouse click on X)
int	ft_closewin(void)
{
	printf("You have exited the game. FORE !\n");
	exit(0);
}

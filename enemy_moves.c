/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:30:41 by malord            #+#    #+#             */
/*   Updated: 2022/07/05 14:45:55 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

//Moves enemy left
void	ft_move_e_left(t_vars *elem)
{
	int	i;
	int	j;

	i = 0;
	while (i < elem->column - 1)
	{
		j = 0;
		while (elem->map[i][j] != '\n')
		{
			if (elem->map[i][j] == 'X' && elem->map[i][j - 1] != '1' &&
			elem->map[i][j - 1] != 'E' && elem->map[i][j - 1] != 'C' &&
			elem->map[i][j - 1] != 'X')
			{
				if (elem->map[i][j] == 'X' && elem->map[i][j - 1] == 'P')
					ft_game_over();
				elem->map[i][j] = '0';
				elem->map[i][j - 1] = 'X';
				break ;
			}
			j++;
		}
		i++;
	}
}

//Moves enemy right
void	ft_move_e_right(t_vars *elem)
{
	int	i;
	int	j;

	i = 0;
	while (i < elem->column - 1)
	{
		j = 0;
		while (elem->map[i][j] != '\n')
		{
			if (elem->map[i][j] == 'X' && elem->map[i][j + 1] != '1' &&
			elem->map[i][j + 1] != 'E' && elem->map[i][j + 1] != 'C' &&
			elem->map[i][j + 1] != 'X')
			{
				if (elem->map[i][j] == 'X' && elem->map[i][j + 1] == 'P')
					ft_game_over();
				elem->map[i][j] = '0';
				elem->map[i][j + 1] = 'X';
				break ;
			}
			j++;
		}
		i++;
	}
}

//Moves enemy down
void	ft_move_e_down(t_vars *elem)
{
	int	i;
	int	j;
	int	result;

	result = 0;
	i = -1;
	while (++i < elem->column - 1)
	{
		j = -1;
		while (elem->map[i][++j] != '\n')
		{
			if (elem->map[i][j] == 'X' && elem->map[i + 1][j] != '1' &&
			elem->map[i + 1][j] != 'E' && elem->map[i + 1][j] != 'C' &&
			elem->map[i + 1][j] != 'X')
			{
				if (elem->map[i][j] == 'X' && elem->map[i + 1][j] == 'P')
					ft_game_over();
				elem->map[i][j] = '0';
				elem->map[i + 1][j] = 'X';
				result = 1;
			}
		}
		if (result == 1)
			break ;
	}
}

//Moves enemy up
void	ft_move_e_up(t_vars *elem)
{
	int	i;
	int	j;

	i = 0;
	while (i < elem->column - 1)
	{
		j = 0;
		while (elem->map[i][j] != '\n')
		{
			if (elem->map[i][j] == 'X' && elem->map[i - 1][j] != '1' &&
			elem->map[i - 1][j] != 'E' && elem->map[i - 1][j] != 'C' &&
			elem->map[i - 1][j] != 'X')
			{
				if (elem->map[i][j] == 'X' && elem->map[i - 1][j] == 'P')
					ft_game_over();
				elem->map[i][j] = '0';
				elem->map[i - 1][j] = 'X';
				break ;
			}
			j++;
		}
		i++;
	}
}

//Gets called when character is hit by an enemy
void	ft_game_over(void)
{
	printf("You've been hit by bad driver Lou !\n");
	exit(0);
}

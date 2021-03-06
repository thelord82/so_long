/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 09:46:15 by malord            #+#    #+#             */
/*   Updated: 2022/07/05 14:51:57 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

//Calls function that moves character right
void	ft_go_right(t_vars *elem)
{
	int	i;
	int	j;

	i = 0;
	while (i < elem->column - 1)
	{
		j = 0;
		while (elem->map[i][j] != '\n')
		{
			if (elem->map[i][j] == 'P' && elem->map[i][j + 1] != '1' &&
				elem->map[i][j + 1] != 'E')
			{
				ft_move_p_right(elem, i, j);
				break ;
			}
			if (elem->map[i][j] == 'P' && elem->map[i][j + 1] == 'E' &&
				elem->avail == 1)
				ft_game_win();
			j++;
		}
		i++;
	}
}

//Calls functions that moves character left
void	ft_go_left(t_vars *elem)
{
	int	i;
	int	j;

	i = 0;
	while (i < elem->column - 1)
	{
		j = 0;
		while (elem->map[i][j] != '\n')
		{
			if (elem->map[i][j] == 'P' && elem->map[i][j - 1] != '1'
				&& elem->map[i][j - 1] != 'E')
			{
				ft_move_p_left(elem, i, j);
				break ;
			}
			if (elem->map[i][j] == 'P' && elem->map[i][j - 1] == 'E' &&
				elem->avail == 1)
				ft_game_win();
			j++;
		}
		i++;
	}
}

//Calls functions that moves character up
void	ft_go_up(t_vars *elem)
{
	int	i;
	int	j;

	i = 0;
	while (i < elem->column - 1)
	{
		j = 0;
		while (elem->map[i][j] != '\n' )
		{
			if (elem->map[i][j] == 'P' && elem->map[i - 1][j] != '1'
				&& elem->map[i - 1][j] != 'E')
			{
				ft_move_p_up(elem, i, j);
				break ;
			}
			if (elem->map[i][j] == 'P' && elem->map[i - 1][j] == 'E' &&
				elem->avail == 1)
				ft_game_win();
			j++;
		}
		i++;
	}
}

//Calls functions that moves character down
void	ft_go_down(t_vars *elem)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	result = 0;
	while (i < elem->column - 1 && result != 1)
	{
		j = 0;
		while (elem->map[i][j] != '\n')
		{
			if (elem->map[i][j] == 'P' && elem->map[i + 1][j] != '1' &&
				elem->map[i + 1][j] != 'E')
			{
				ft_move_p_down(elem, i, j);
				result = 1;
			}
			if (elem->map[i][j] == 'P' && elem->map[i + 1][j] == 'E' &&
				elem->avail == 1)
				ft_game_win();
			j++;
		}
		i++;
	}
}

//Changes the image of the exit, once it becomes available
void	ft_exit(t_vars *elem)
{
	int	img_width;
	int	img_height;

	elem->exit = mlx_xpm_file_to_image(elem->mlx,
			"img/exitnoflag.xpm",
			&img_width, &img_height);
}

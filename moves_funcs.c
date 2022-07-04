/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 09:46:15 by malord            #+#    #+#             */
/*   Updated: 2022/07/04 15:20:10 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

void	go_right(t_vars *elem)
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
				move_p_right(elem, i, j);
				break ;
			}
			if (elem->map[i][j] == 'P' && elem->map[i][j + 1] == 'E' &&
				elem->avail == 1)
				game_win();
			j++;
		}
		i++;
	}
}

void	go_left(t_vars *elem)
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
				move_p_left(elem, i, j);
				break ;
			}
			if (elem->map[i][j] == 'P' && elem->map[i][j - 1] == 'E' &&
				elem->avail == 1)
				game_win();
			j++;
		}
		i++;
	}
}

void	go_up(t_vars *elem)
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
				move_p_up(elem, i, j);
				break ;
			}
			if (elem->map[i][j] == 'P' && elem->map[i - 1][j] == 'E' &&
				elem->avail == 1)
				game_win();
			j++;
		}
		i++;
	}
}

void	go_down(t_vars *elem)
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
				move_p_down(elem, i, j);
				result = 1;
			}
			if (elem->map[i][j] == 'P' && elem->map[i + 1][j] == 'E' &&
				elem->avail == 1)
				game_win();
			j++;
		}
		i++;
	}
}

void	ft_exit(t_vars *elem)
{
	int	img_width;
	int	img_height;

	elem->exit = mlx_xpm_file_to_image(elem->mlx,
			"/Users/malord/42/so_long/exitnoflag.xpm",
			&img_width, &img_height);
}

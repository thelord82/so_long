/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_funcs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:30:34 by malord            #+#    #+#             */
/*   Updated: 2022/07/04 14:51:12 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

void	move_p_right(t_vars *elem, int i, int j)
{
	elem->map[i][j] = '0';
	if (elem->map[i][j + 1] == 'C')
		elem->collect--;
	if (elem->map[i][j + 1] == 'X')
	{
		printf("Tu t'es fait passer dessus par Lou !\n");
		exit(0);
	}
	if (elem->collect == 0)
	{
		elem->avail = 1;
		ft_exit(elem);
	}
	elem->map[i][j + 1] = 'P';
	printf("%d MOVES\n", ++elem->moves);
}

void	move_p_left(t_vars *elem, int i, int j)
{
	elem->map[i][j] = '0';
	if (elem->map[i][j - 1] == 'C')
		elem->collect--;
	if (elem->map[i][j - 1] == 'X')
	{
		printf("Tu t'es fait passer dessus par Lou !\n");
		exit(0);
	}
	if (elem->collect == 0)
	{
		elem->avail = 1;
		ft_exit(elem);
	}
	elem->map[i][j - 1] = 'P';
	printf("%d MOVES\n", ++elem->moves);
}

void	move_p_up(t_vars *elem, int i, int j)
{
	elem->map[i][j] = '0';
	if (elem->map[i - 1][j] == 'C')
		elem->collect--;
	if (elem->map[i - 1][j] == 'X')
	{
		printf("Tu t'es fait passer dessus par Lou !\n");
		exit(0);
	}
	if (elem->collect == 0)
	{
		elem->avail = 1;
		ft_exit(elem);
	}
	elem->map[i - 1][j] = 'P';
	printf("%d MOVES\n", ++elem->moves);
}

void	move_p_down(t_vars *elem, int i, int j)
{
	elem->map[i][j] = '0';
	if (elem->map[i + 1][j] == 'C')
		elem->collect--;
	if (elem->map[i + 1][j] == 'X')
	{
		printf("Tu t'es fait passer dessus par Lou !\n");
		exit(0);
	}
	if (elem->collect == 0)
	{
		elem->avail = 1;
		ft_exit(elem);
	}
	elem->map[i + 1][j] = 'P';
	printf("%d MOVES\n", ++elem->moves);
}

void	game_win(void)
{
	printf("BIIIIIIIRDIE!!!\n");
	exit(0);
}
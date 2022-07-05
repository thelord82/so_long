/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 07:58:23 by malord            #+#    #+#             */
/*   Updated: 2022/07/05 14:32:24 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

char	*ft_nb_moves(t_vars *elem)
{
	char	*nb_moves;
	char	*moves;

	nb_moves = ft_itoa(elem->moves);
	moves = ft_strjoin("MOVES : ", nb_moves);
	free(nb_moves);
	return (moves);
}

void	ft_put_image(int i, int j, t_vars *elem)
{
	if (elem->map[i][j] == '1')
		mlx_put_image_to_window(elem->mlx, elem->win, elem->wall, elem->x,
			elem->y);
	if (elem->map[i][j] == '0')
		mlx_put_image_to_window(elem->mlx, elem->win, elem->floor, elem->x,
			elem->y);
	if (elem->map[i][j] == 'P')
		mlx_put_image_to_window(elem->mlx, elem->win, elem->perso, elem->x,
			elem->y);
	if (elem->map[i][j] == 'C')
		mlx_put_image_to_window(elem->mlx, elem->win, elem->collectible,
			elem->x, elem->y);
	if (elem->map[i][j] == 'E')
		mlx_put_image_to_window(elem->mlx, elem->win, elem->exit, elem->x,
			elem->y);
	if (elem->map[i][j] == 'X')
		mlx_put_image_to_window(elem->mlx, elem->win, elem->enemy, elem->x,
			elem->y);
}

void	ft_create_window(t_vars *elem)
{
	int		i;
	int		j;
	char	*moves;

	i = 0;
	elem->y = 0;
	moves = ft_nb_moves(elem);
	while (i < elem->column)
	{
		j = 0;
		elem->x = 0;
		while (elem->map[i][j] != '\n')
		{
			ft_put_image(i, j, elem);
			mlx_string_put(elem->mlx, elem->win, 20, 20, 0xffffff, moves);
			j++;
			elem->x += 64;
		}
		elem->y += 64;
		i++;
	}
	free(moves);
}

int	ft_keys(int keycode, t_vars *vars)
{	
	ft_esc_key(keycode, vars);
	ft_game_controls(keycode, vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		fd;

	vars.moves = 0;
	if (ft_check_args(argv[1], argc) == 1)
	{
		ft_map_size(&vars, argv[1]);
		fd = open(argv[1], O_RDONLY);
		ft_check_fd(fd);
		vars.avail = 0;
		ft_init_struct(&vars);
		ft_map_to_array(&vars, fd);
		ft_check_wall(&vars, vars.column);
		ft_check_rectangle(&vars, vars.column);
		ft_check_map(&vars, vars.column);
		ft_check_mcontent(&vars, vars.column);
		vars.win = mlx_new_window(vars.mlx, ((ft_strlen(vars.map[0]) - 1) * 64),
				(vars.column * 64), "so_long");
		ft_create_window(&vars);
		mlx_hook(vars.win, 2, 0, ft_keys, &vars);
		mlx_hook(vars.win, 17, 0, ft_closewin, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}

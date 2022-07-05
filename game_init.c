/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:34:35 by malord            #+#    #+#             */
/*   Updated: 2022/07/04 20:10:47 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

/*void	game_init(t_vars *vars, int fd, char **argv)
{
	vars->avail = 0;
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (0);
	vars->mlx = mlx_init();
	vars->floor = mlx_xpm_file_to_image(vars.mlx, floor_path, &img_width, &img_height);
	vars->perso = mlx_xpm_file_to_image(vars.mlx, perso_path, &img_width, &img_height);
	vars->wall = mlx_xpm_file_to_image(vars.mlx, wall_path, &img_width, &img_height);
	vars->collectible = mlx_xpm_file_to_image(vars.mlx, coll_path, &img_width, &img_height);
	vars->enemy = mlx_xpm_file_to_image(vars.mlx, enemy_path, &img_width, &img_height);
	vars->exit = mlx_xpm_file_to_image(vars.mlx, exit_path, &img_width, &img_height);
	vars->map = ft_calloc(sizeof(t_vars), 1);
	while (1)
	{
		vars->map[j] = get_next_line(fd);
		if (vars->map[j] == NULL)
		{
			free (vars->map[j]);
			break ;
		}
		j++;
	}
	vars->column = j;
}*/

void	game_controls(int keycode, t_vars *vars)
{
	if( keycode == 2)
	{
		go_right(vars);
		move_e_left(vars);
		ft_create_window(vars);
	}
	else if (keycode == 0)
	{
		go_left(vars);
		move_e_right(vars);
		ft_create_window(vars);
	}
	else if (keycode == 1)
	{
		go_down(vars);
		move_e_up(vars);
		ft_create_window(vars);
	}
	else if (keycode == 13)
	{
		go_up(vars);
		move_e_down(vars);
		ft_create_window(vars);
	}
}

void	esc_key(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
}
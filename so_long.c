/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 07:58:23 by malord            #+#    #+#             */
/*   Updated: 2022/07/04 14:01:28 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

char	*nb_moves(t_vars *elem)
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
	moves = nb_moves(elem);
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
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if( keycode == 2)
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
	return (0);
}

// Ferme la fenetre et quitte proprement sur la croix rouge
int	ft_closewin(void)
{
	exit(0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		fd;
	int		j;
	size_t	column;
	char	*floor_path = "/Users/malord/42/so_long/floorgreen.xpm";
	char	*perso_path = "/Users/malord/42/so_long/mario2.xpm";
	char	*wall_path = "/Users/malord/42/so_long/wall.xpm";
	char 	*coll_path = "/Users/malord/42/so_long/collectible.xpm";
	char	*exit_path = "/Users/malord/42/so_long/exitflag.xpm";
	char	*enemy_path = "/Users/malord/42/so_long/enemy.xpm";
	int		img_width;
	int		img_height;

	column = 0;
	j = 0;
	vars.moves = 0;
	vars.x = 0; 
	vars.y = 0;
	if (ft_check_args(argv[1], argc) == 1)
	{
		vars.avail = 0;
		fd = open(argv[1], O_RDONLY);
		if (!fd)
			return (0);
		vars.mlx = mlx_init();
		vars.floor = mlx_xpm_file_to_image(vars.mlx, floor_path, &img_width, &img_height);
		vars.perso = mlx_xpm_file_to_image(vars.mlx, perso_path, &img_width, &img_height);
		vars.wall = mlx_xpm_file_to_image(vars.mlx, wall_path, &img_width, &img_height);
		vars.collectible = mlx_xpm_file_to_image(vars.mlx, coll_path, &img_width, &img_height);
		vars.enemy = mlx_xpm_file_to_image(vars.mlx, enemy_path, &img_width, &img_height);
		vars.exit = mlx_xpm_file_to_image(vars.mlx, exit_path, &img_width, &img_height);
		vars.map = ft_calloc(sizeof(t_vars), 1);
		while (1)
		{
			vars.map[j] = get_next_line(fd);
			if (vars.map[j] == NULL)
			{
				free (vars.map[j]);
				break ;
			}
			j++;
		}
		vars.column = j;
		j = 0;
		ft_check_wall(&vars, vars.column);
		ft_check_rectangle(&vars, vars.column);
		ft_check_map(&vars, vars.column);
		ft_check_mcontent(&vars, vars.column);
		vars.win = mlx_new_window(vars.mlx, ((ft_strlen(vars.map[0]) - 1) * 64), (vars.column * 64), "so_long");
		ft_create_window(&vars);
		mlx_hook(vars.win, 2, 0, ft_keys, &vars);
		mlx_hook(vars.win, 17, 0, ft_closewin, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}

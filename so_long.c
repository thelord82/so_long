/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 07:58:23 by malord            #+#    #+#             */
/*   Updated: 2022/06/27 16:04:11 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

void	ft_create_window(t_vars *elem, int size)
{
	int	i;
	int	j;

	i = 0;
	elem->win = mlx_new_window(elem->mlx, ((ft_strlen(elem->map[i]) - 1) * 64), (size * 64), "so_long");
	while (i < size)
	{
		j = 0;
		elem->x = 0;
		while (elem->map[i][j] != '\n')
		{
			if (elem->map[i][j] == '1')
				mlx_put_image_to_window(elem->mlx, elem->win, elem->wall, elem->x, elem->y);
			if (elem->map[i][j] == '0')
				mlx_put_image_to_window(elem->mlx, elem->win, elem->floor, elem->x, elem->y);
			if (elem->map[i][j] == 'P')
				mlx_put_image_to_window(elem->mlx, elem->win, elem->perso, elem->x, elem->y);
			if (elem->map[i][j] == 'C')
				mlx_put_image_to_window(elem->mlx, elem->win, elem->collectible, elem->x, elem->y);
			if (elem->map[i][j] == 'E')
				mlx_put_image_to_window(elem->mlx, elem->win, elem->exit, elem->x, elem->y);
			j++;
			elem->x += 64;
		}
		elem->y += 64;
		i++;
	}
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
		printf("%d MOVES\n", ++vars->moves);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, (vars->x += 64), vars->y);
	}
	else if (keycode == 0)
	{
		printf("%d MOVES\n", ++vars->moves);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, (vars->x -= 64), vars->y);
	}
	else if (keycode == 1)
	{
		printf("%d MOVES\n", ++vars->moves);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, vars->x, (vars->y += 64));
	}
	else if (keycode == 13)
	{
		printf("%d MOVES\n", ++vars->moves);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, vars->x, (vars->y -= 64));
	}
	return (0);
}

// Ferme la fenetre et quitte proprement sur la croix rouge
int	ft_closewin()
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
	int		img_width;
	int		img_height;

	column = 0;
	j = 0;
	vars.moves = 0;
	vars.x = 0; 
	vars.y = 0;
	if (ft_check_args(argv[1], argc) == 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (!fd)
			return (0);
		vars.mlx = mlx_init();
		vars.floor = mlx_xpm_file_to_image(vars.mlx, floor_path, &img_width, &img_height);
		vars.perso = mlx_xpm_file_to_image(vars.mlx, perso_path, &img_width, &img_height);
		vars.wall = mlx_xpm_file_to_image(vars.mlx, wall_path, &img_width, &img_height);
		vars.collectible = mlx_xpm_file_to_image(vars.mlx, coll_path, &img_width, &img_height);
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
		column = j;
		j = 0;
		ft_check_wall(&vars, column);
		ft_check_rectangle(&vars, column);
		ft_check_map(&vars, column);
		ft_check_mcontent(&vars, column);
		ft_create_window(&vars, column);
	mlx_hook(vars.win, 2, 0, ft_keys, &vars);
	mlx_hook(vars.win, 17, 0, ft_closewin, &vars);
	mlx_loop(vars.mlx);
	}
	return (0);
}

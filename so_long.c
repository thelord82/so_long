/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 07:58:23 by malord            #+#    #+#             */
/*   Updated: 2022/06/21 17:03:40 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

int	ft_check_error(char *argu, int argc)
{
	int	ext;

	if (argc != 2)
	{
		printf("Error\nYou must enter one and only one argument.\n");
		return (0);
	}
	ext = ft_strlen(argu) - 4;
	if (ft_strncmp(&argu[ext], ".ber", 4) != 0)
	{
		printf("Error\nMap must be of .ber extension.\n");
		return (0);
	}
	return (1);
}

void	ft_check_map_error(char **map, int column)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 1;
	size = ft_strlen(map[0]);
	printf("%d\n", size);
	while (i < size - 1)
	{
		if (map[0][i] != '1' || map[column - 1][i] != '1')
		{
			printf("Error\nMap is not surrounded by walls.\n");
			return ;
		}
		i++;
		//printf("%s", map[j]);
		/*if (map[j][0] != '1' || map[j][size - 2])
		{
			printf("Error\nMap is not circled by walls.\n");
			return ;
		}
		j++;*/
	}
	/*while (i < size)
	{
		j = 0;
		while (map[i][j])
		{
			//if (map[0][j] != '1' || map[i][0] != 1 || map[i][ft_strlen(map[i] - 1)] != 1 || map[i][j] != 1)
			if (map[0][j] != '1')
			{
				printf("Error\nMap is not surrounded by walls.\n");
				return ;
			}
			//else if ()
			j++;
		}
		i++;
	}*/
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
	int		column;

	j = 0;
	if (ft_check_error(argv[1], argc) == 1)
	{
		fd = open(argv[1], O_RDONLY);
		vars.map = ft_calloc(sizeof(t_vars), 1);
		if (!fd)
			return (0);
		vars.mlx = mlx_init();
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
		ft_check_map_error(&vars.map[j], column);
	}
	/*t_vars	vars;
	char	*floor_path = "/Users/malord/42/so_long/floorgreen.xpm";
	char	*perso_path = "/Users/malord/42/so_long/mario2.xpm";
	char	*wall_path = "/Users/malord/42/so_long/wall.xpm";
	char 	*coll_path = "/Users/malord/42/so_long/collectible.xpm";
	char	*exit_path = "/Users/malord/42/so_long/exitflag.xpm";
	int	img_width;
	int	img_height;
	int fd = 0;
	int	i = 0;
	int	j = 0;
	int size = 0;
	fd = open(argv[1], O_RDONLY);
	vars.map = ft_calloc(sizeof(t_vars), 1);
	if (!fd)
		return (0);
	vars.moves = 0;
	vars.x = 0; 
	vars.y = 0;
	vars.mlx = mlx_init();
	vars.floor = mlx_xpm_file_to_image(vars.mlx, floor_path, &img_width, &img_height);
	vars.perso = mlx_xpm_file_to_image(vars.mlx, perso_path, &img_width, &img_height);
	vars.wall = mlx_xpm_file_to_image(vars.mlx, wall_path, &img_width, &img_height);
	vars.collectible = mlx_xpm_file_to_image(vars.mlx, coll_path, &img_width, &img_height);
	vars.exit = mlx_xpm_file_to_image(vars.mlx, exit_path, &img_width, &img_height);
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
	size = j;
	vars.win = mlx_new_window(vars.mlx, ((ft_strlen(vars.map[i]) - 1) * 64), (size * 64), "so_long");
	j = 0;
	while (i < size)
	{
		while (vars.map[i][j] != '\n')
		{
			if (vars.map[i][j] == '1')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.wall, vars.x, vars.y);
			if (vars.map[i][j] == '0')
				mlx_put_image_to_window(vars.mlx, vars. win, vars.floor, vars.x, vars.y);
			if (vars.map[i][j] == 'P')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.perso, vars.x, vars.y);
			if (vars.map[i][j] == 'C')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.collectible, vars.x, vars.y);
			if (vars.map[i][j] == 'E')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.exit, vars.x, vars.y);
			j++;
			vars.x += 64;
		}
		vars.y += 64;
		j = 0;
		i++;
		vars.x = 0;
	}
	mlx_hook(vars.win, 2, 0, ft_keys, &vars);
	mlx_hook(vars.win, 17, 0, ft_closewin, &vars);
	mlx_loop(vars.mlx);*/
}

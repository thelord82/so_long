/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:34:35 by malord            #+#    #+#             */
/*   Updated: 2022/07/05 14:49:37 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

//Takes a file with fd and puts it into an array
void	ft_map_to_array(t_vars *vars, int fd)
{
	vars->column = 0;
	vars->map[vars->column] = get_next_line(fd);
	if (vars->map[vars->column] == NULL)
	{
		printf("Error : File is empty.\n");
		free (vars->map[vars->column]);
		exit(0);
	}
	else
		vars->column++;
	while (1)
	{
		vars->map[vars->column] = get_next_line(fd);
		if (vars->map[vars->column] == NULL)
		{
			free (vars->map[vars->column]);
			break ;
		}
		vars->column++;
	}
}

//Gets the number of rows for the fd, allows to malloc correctly
void	ft_map_size(t_vars *vars, char *argv)
{
	int		fd;
	char	*row;

	fd = open(argv, O_RDONLY);
	row = get_next_line(fd);
	vars->rows = 1;
	while (row != NULL)
	{
		free (row);
		row = get_next_line(fd);
		vars->rows++;
	}
	free (row);
	close (fd);
}

//Initialize the struct by converting image files and memory allocation for map
void	ft_init_struct(t_vars *vars)
{
	int	img_width;
	int	img_height;

	vars->mlx = mlx_init();
	vars->floor = mlx_xpm_file_to_image(vars->mlx, "img/floorgreen.xpm",
			&img_width, &img_height);
	vars->perso = mlx_xpm_file_to_image(vars->mlx, "img/mario2.xpm",
			&img_width, &img_height);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, "img/wall.xpm",
			&img_width, &img_height);
	vars->collectible = mlx_xpm_file_to_image(vars->mlx,
			"img/collectible.xpm", &img_width, &img_height);
	vars->enemy = mlx_xpm_file_to_image(vars->mlx, "img/enemy.xpm",
			&img_width, &img_height);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, "img/exitflag.xpm",
			&img_width, &img_height);
	vars->map = ft_calloc(sizeof(char *), vars->rows + 1);
}

//Calls movement functions on certain key events
void	ft_game_controls(int keycode, t_vars *vars)
{
	if (keycode == 2)
	{
		ft_go_right(vars);
		ft_move_e_left(vars);
		ft_create_window(vars);
	}
	else if (keycode == 0)
	{
		ft_go_left(vars);
		ft_move_e_right(vars);
		ft_create_window(vars);
	}
	else if (keycode == 1)
	{
		ft_go_down(vars);
		ft_move_e_down(vars);
		ft_create_window(vars);
	}
	else if (keycode == 13)
	{
		ft_go_up(vars);
		ft_move_e_up(vars);
		ft_create_window(vars);
	}
}

//Checks if the file passed in argument exists
void	ft_check_fd(int fd)
{
	if (fd == -1)
	{
		printf("Error : %s\n", strerror(errno));
		exit(0);
	}
}

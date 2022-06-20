/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 07:58:23 by malord            #+#    #+#             */
/*   Updated: 2022/06/20 13:47:46 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

/*int	main()
{
	void	*mlx_ptr;
	void	*window_ptr;
	int		color;
	int		x = 400;
	int		y = 300;

	color = 255;

	mlx_ptr = mlx_init();
	window_ptr = mlx_new_window(mlx_ptr, 640, 480, "RECTUM!");
	while (x < 450 && y < 350)
		mlx_pixel_put(mlx_ptr, window_ptr, x++, y++, color);
	while (x > 350)
		mlx_pixel_put(mlx_ptr, window_ptr, x--, y, color);
	while (x < 400 && y > 300)
		mlx_pixel_put(mlx_ptr, window_ptr, x++, y--, color);
	mlx_key_hook(window_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}*/

/*int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int x = 555;
	int y = 555;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (x <= 655 && y <= 655)
	{
		my_mlx_pixel_put(&img, x++, y, 0x00FF0000);
		if (x == 655)
		{
			x = 555;
			y++;
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop_hook(mlx, render_next_frame, &
	mlx_loop(mlx);
}*/

int	ft_keys(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if( keycode == 2)
	{
		vars->moves++;
		printf("%d MOVES\n", vars->moves);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, (vars->x += 32), vars->y);
	}
	else if (keycode == 0)
	{
		vars->moves++;
		printf("%d MOVES\n", vars->moves);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, (vars->x -= 32), vars->y);
	}
	else if (keycode == 1)
	{
		vars->moves++;
		printf("%d MOVES\n", vars->moves);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, vars->x, (vars->y += 32));
	}
	else if (keycode == 13)
	{
		vars->moves++;
		printf("%d MOVES\n", vars->moves);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->perso, vars->x, (vars->y -= 32));
	}
	return (0);
}

// Ferme la fenetre et quitte proprement sur la croix rouge
int	ft_closewin()
{
	exit(0);
}

int	main(void)
{
	t_vars	vars;
	char	*floor_path = "/Users/malord/42/so_long/floorgreen.xpm";
	char	*perso_path = "/Users/malord/42/so_long/mario2.xpm";
	char	*wall_path = "/Users/malord/42/so_long/wall.xpm";
	char 	*coll_path = "/Users/malord/42/so_long/collectible.xpm";
	char	*exit_path = "/Users/malord/42/so_long/exitflag.xpm";
	int	img_width;
	int	img_height;
	int fd;
	char *line;
	int	i = 0;

	fd = open("map.ber", O_RDONLY);
	if (!fd)
		return (0);
	line = get_next_line(fd);
	vars.moves = 0;
	vars.x = 0; 
	vars.y = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1024, 768, "LE PIRE JEU DE GOLF DE L'HISTOIRE");
	vars.floor = mlx_xpm_file_to_image(vars.mlx, floor_path, &img_width, &img_height);
	vars.perso = mlx_xpm_file_to_image(vars.mlx, perso_path, &img_width, &img_height);
	vars.wall = mlx_xpm_file_to_image(vars.mlx, wall_path, &img_width, &img_height);
	vars.collectible = mlx_xpm_file_to_image(vars.mlx, coll_path, &img_width, &img_height);
	vars.exit = mlx_xpm_file_to_image(vars.mlx, exit_path, &img_width, &img_height);
	while (line != NULL)
	{
		while (line[i] != '\n')
		{
			if (line[i] == '1')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.wall, vars.x, vars.y);
			if (line[i] == '0')
				mlx_put_image_to_window(vars.mlx, vars. win, vars.floor, vars.x, vars.y);
			if (line[i] == 'P')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.perso, vars.x, vars.y);
			if (line[i] == 'C')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.collectible, vars.x, vars.y);
			if (line[i] == 'E')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.exit, vars.x, vars.y);
			i++;
			vars.x += 64;
		}
		vars.y += 64;
		i = 0;
		vars.x = 0;
		line = get_next_line(fd);
	}
	/*while (vars.x <= 1024 && vars.y <= 768)
	{
		while (vars.x <= 1024)
		{
			mlx_put_image_to_window(vars.mlx, vars.win, vars.floor, vars.x, vars.y);
			vars.x += 64;
		}
		vars.x = 0;
		vars.y += 64;
	}*/
	//mlx_put_image_to_window(vars.mlx, vars.win, vars.perso, 0, 0);

	mlx_hook(vars.win, 2, 0, ft_keys, &vars);
	//mlx_hook(vars.win, 3, 0, ft_keys, &vars);
	//mlx_key_hook(vars.win, ft_keys, &vars);
	mlx_hook(vars.win, 17, 0, ft_closewin, &vars);
	mlx_loop(vars.mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:30:38 by malord            #+#    #+#             */
/*   Updated: 2022/06/30 11:28:05 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

void	ft_check_mcontent(t_vars *elem, size_t column)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < column - 1)
	{
		j = 0;
		while (j < ft_strlen(elem->map[0]) - 1)
		{
			if (elem->map[i][j] == 'P')
				elem->charac++;
			if (elem->map[i][j] == 'E')
				elem->sortie++;
			if (elem->map[i][j] == 'C')
				elem->collect++;
			j++;
		}
		i++;
	}
	if (elem->charac != 1 || elem->sortie != 1 || elem->collect < 1)
	{
		printf("Error.\nGame must have 1: exit, character, collectible.\n");
		exit (0);
	}
}

void	ft_check_map(t_vars *elem, size_t column)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < column - 1)
	{
		j = 0;
		while (j < ft_strlen(elem->map[0]) - 1)
		{
			if (elem->map[i][j] != '0' && elem->map[i][j] != '1'
				&& elem->map[i][j] != 'E' && elem->map[i][j] != 'C'
				&& elem->map[i][j] != 'P' && elem->map[i][j] != 'X'
				&& elem->map[i][j] != '\n')
			{
				printf("Error\nMap has invalid characters.");
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	ft_check_rectangle(t_vars *elem, size_t column)
{
	size_t	i;

	i = 0;
	while (i < column - 1)
	{
		if ((i + 1) == (column - 1))
		{
			if (ft_strlen(elem->map[i]) != ft_strlen(elem->map[i + 1]) + 1)
			{
				printf("Error\nMap is not rectangle.");
				exit(0);
			}
		}
		else if (ft_strlen(elem->map[i]) != ft_strlen(elem->map[i + 1]))
		{
			printf("Error\nMap is not rectangle.");
			exit(0);
		}
		i++;
	}
}

int	ft_check_args(char *argu, int argc)
{
	size_t	ext;

	if (argc != 2)
	{
		printf("Error\nYou must enter one and only one argument.\n");
		exit(0);
	}
	ext = ft_strlen(argu) - 4;
	if (ft_strncmp(&argu[ext], ".ber", 4) != 0)
	{
		printf("Error\nMap must be of .ber extension.\n");
		exit(0);
	}
	return (1);
}

void	ft_check_wall(t_vars *elem, size_t column)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 1;
	size = ft_strlen(elem->map[0]);
	while (i < size - 1)
	{
		if (elem->map[0][i] != '1' || elem->map[column - 1][i] != '1')
		{
			printf("Error\nMap is not surrounded by walls.\n");
			exit(0);
		}
		i++;
	}
	while (j < (column - 1))
	{
		if (elem->map[j][0] != '1' || elem->map[j][size - 2] != '1')
		{
			printf("Error\nMap is not circled by walls.\n");
			exit(0);
		}
		j++;
	}
}
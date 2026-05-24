/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 23:34:22 by juan-her          #+#    #+#             */
/*   Updated: 2026/05/25 01:10:41 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parseo.h"

static int	ft_is_valid(char c)
{
	return(c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
					|| c == ' ' || c == '\t');
}

static int ft_val_char_player(char **map, int *px, int *py)
{
	int x;
	int	y;
	int	player;
	
	player = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!ft_is_valid(map[y][x]))
				return (printf("Error: invalid char\n"), 0);
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' 
					|| map[y][x] == 'W')
			{
				player++;
				*px = x;
				*py = y;
			}
			x++;
		}
		y++;
	}
	if (player != 1)
		return (printf("Error: invalid player\n"), 0);
	return (1);
}

static char	**ft_copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
			return (ft_free_split(copy), NULL);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static int	ft_flood_fill(char **map, int x, int y)
{
	if (y < 0 || x < 0 || !map[y] || !map[y][x])
		return (0);
	if (map[y][x] == ' ')
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'F')
		return (1);
	map[y][x] = 'F';
	if (!ft_flood_fill(map, x + 1, y))
		return (0);
	if (!ft_flood_fill(map, x - 1, y))
		return (0);
	if (!ft_flood_fill(map, x, y + 1))
		return (0);
	if (!ft_flood_fill(map, x, y - 1))
		return (0);
	return (1);
}

static int	ft_val_closed_map(char **map, int height, int px, int py)
{
	char	**tmp;

	tmp = ft_copy_map(map, height);
	if (!tmp)
		return (0);
	if (!ft_flood_fill(tmp, px, py))
	{
		printf("Error: mapa abierto\n");
		ft_free_split(tmp);
		return (0);
	}
	ft_free_split(tmp);
	return (1);
}

int	ft_val_map(char **map, int height)
{
	int	px;
	int	py;

	if (!ft_val_char_player(map, &px, &py))
		return (0);
	if (!ft_val_closed_map(map, height, px, py))
		return (0);
	return (1);
}

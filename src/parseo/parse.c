/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 17:26:21 by juan-her          #+#    #+#             */
/*   Updated: 2026/05/25 01:04:51 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parseo.h"

int	ft_parse(t_parseo *parse)
{
	char	*line;
	t_line	*lst_map;
	char	**map;

	lst_map = NULL;
	if (!ft_init_parse(parse))
		return (0);
	parse->fd = open("media/maps/firstMap.cub", O_RDONLY);
	if (parse->fd < 0)
		return (0);
	line = ft_header(parse);
	if (!line)
		return (0);
	if (!ft_check_header(parse->header))
		return (free(line), 0);
	printf("Header OK\n");
	lst_map = ft_new_line(line);
	free(line);
	if (!ft_read_map(parse, &lst_map))
		return (ft_del_list(&lst_map), 0);
	map = ft_norm_map(lst_map, parse);
	if (!map)
		return (0);
	if (!ft_val_map(map, parse->map->height))
		return (printf("No funciono"), 0);
	printf("Map OK\n");
	return (1);
}

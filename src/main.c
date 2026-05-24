/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:00:13 by juan-her          #+#    #+#             */
/*   Updated: 2026/05/22 21:09:13 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parseo.h"

int	main(int ac, char **ag)
{
	t_parseo parse;
	(void) ag;

	if (ac != 1)
		return (1);
	if (!ft_parse(&parse))
	{
		printf("haihsohsa");
		return (1);
	}
	return (0);
}

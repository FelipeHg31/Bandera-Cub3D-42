/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:00:13 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/12 22:08:29 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/config.h"
#include "../includes/engine.h"
#include "../includes/parseo.h"
#include "../includes/player.h"
#include "../includes/screen.h"

int	main(void)
{
	t_engine	*engine;

	engine = ft_calloc(1, sizeof(t_engine));
	if (!engine)
		return (1);
	engine->final = ft_parse();
	if (!engine->final)
		return (free(engine), printf("Error parse\n"), 1);
	ft_init_engine(engine);
	ft_start_engine(engine);
	return (0);
}

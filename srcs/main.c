/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:34:44 by msarr             #+#    #+#             */
/*   Updated: 2015/02/27 21:34:44 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	init_array(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			game->array[i][j].win = NULL;
			game->array[i][j].val = 0;
			j++;
		}
		i++;
	}
}

static void	init(t_game *game)
{
	game->menubar = NULL;
	game->win = NULL;
	game->msgbar = NULL;
	game->menulist = NULL;
	game->scorelist = NULL;
	init_array(game);
	start_color();
	curs_set(0);
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	noecho();
	keypad(stdscr, TRUE);
	bkgd(COLOR_PAIR(1));
	refresh();
}

int			main(void)
{
	t_game	game;

	if (!(WIN_VALUE % 2) && initscr())
	{
		glob = &game;
		init(&game);
		setwins(&game);
		score_init(&game);
		while ((game.size = menu(&game) + 3) > 5)
			put_score(&game);
		if (game.size > 3 && game.size < 6)
		{
			set_plateau(&game);
			if (start(&game))
				put_msg(game.msgbar, " GAME BEGIN", 2);
			play(&game);
			refresh();
		}
		ft_exit("ya", &game);
	}
	else
		ft_putendl("Game_2048: Initialisation failed.");
	return (0);
}

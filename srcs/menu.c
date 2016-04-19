/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:41:07 by msarr             #+#    #+#             */
/*   Updated: 2015/02/27 22:41:07 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int	show_menubar(t_game *game)
{
	if (!(game->menulist = (WINDOW **)malloc(sizeof(WINDOW *) * 6)))
		ft_exit("Error showing the menu.", game);
	game->menulist[0] = newwin(6, 19, 1, 0);
	wbkgd(game->menulist[0], COLOR_PAIR(2));
	box(game->menulist[0], ACS_VLINE, ACS_HLINE);
	game->menulist[1] = subwin(game->menulist[0], 1, 17, 2, 1);
	wprintw(game->menulist[1], "GRILL 4X4");
	game->menulist[2] = subwin(game->menulist[0], 1, 17, 3, 1);
	wprintw(game->menulist[2], "GRILL 5X5");
	game->menulist[3] = subwin(game->menulist[0], 1, 17, 4, 1);
	wprintw(game->menulist[3], "SCORE");
	game->menulist[4] = subwin(game->menulist[0], 1, 17, 5, 1);
	wprintw(game->menulist[4], "EXIT");
	game->menulist[5] = NULL;
	wbkgd(game->menulist[1], COLOR_PAIR(1));
	wrefresh(game->menulist[0]);
	return (1);
}

static int	scroller(t_game *game, int i, int flag)
{
	wbkgd(game->menulist[i], COLOR_PAIR(2));
	wrefresh(game->menulist[i]);
	if (flag == KEY_DOWN)
		i++;
	else
		i--;
	i = i % 6;
	if (!i)
		i++;
	wbkgd(game->menulist[i], COLOR_PAIR(1));
	wrefresh(game->menulist[i]);
	return (i);
}

int			menu(t_game *game)
{
	int key;
	int i;

	i = 1;
	key = -1;
	while (key != ESCAPE && key != ENTER)
	{
		key = getch();
		if (key == KEY_F(1))
		{
			show_menubar(game);
			while ((key = getch()) && (key == KEY_UP || key == KEY_DOWN))
				i = scroller(game, i, key);
			if (key != ENTER)
				i = 0;
		}
		if (key == ESCAPE)
			i = 0;
	}
	del_menu(game);
	refresh();
	return (i);
}

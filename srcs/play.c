/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 13:53:49 by msarr             #+#    #+#             */
/*   Updated: 2015/11/26 22:21:31 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int		reload(t_game *game, int i, int j)
{
	char		*k;

	if (!game->array[i][j].win)
		game->array[i][j].win = subwin(game->win, game->pady, game->padx,
		game->starty, game->startx);
	k = ft_itoa(game->array[i][j].val);
	if (game->array[i][j].val)
		put_msg_middle(game, game->array[i][j].win, k, 1);
	box(game->array[i][j].win, ACS_VLINE, ACS_HLINE);
	wrefresh(game->array[i][j].win);
	refresh();
	return (1);
}

void			set_plateau(t_game *game)
{
	int			i;
	int			j;

	i = 0;
	werase(game->win);
	padding(game);
	while (game->size < 6 && i < game->size)
	{
		j = 0;
		while (j < game->size)
		{
			reload(game, i, j);
			game->startx += game->padx;
			j++;
		}
		i++;
		game->startx = 0;
		game->starty += game->pady;
	}
}

int				start(t_game *game)
{
	int			key;

	game->score = 0;
	game->state = 0;
	wrand(game);
	wrand(game);
	put_msg(game->msgbar, "Press ENTER to start the game", 1);
	key = -1;
	while (key != ENTER && key != ESCAPE)
		key = getch();
	if (key == ENTER)
		return (1);
	return (0);
}

int				play(t_game *game)
{
	int			key;
	char		*str;

	key = 0;
	put_msg(game->msgbar, "Use the directions keys.", 1);
	while (key != ESCAPE)
	{
		key = getch();
		if (key == KEY_UP)
			up(game);
		else if (key == KEY_LEFT)
			left(game);
		else if (key == KEY_RIGHT)
			right(game);
		else if (key == KEY_DOWN)
			down(game);
		if (game->state == 1)
			put_msg(game->msgbar, "YOU REACHED 2048!", 1);
		if (!loose(game) && !loose1(game))
			put_msg(game->msgbar, "FATAL DEATH!", 1);
		str = ft_strjoin("SCORE: ", ft_itoa(game->score));
		put_msg(game->scorebar, str, 1);
		wrand(game);
	}
	return (1);
}

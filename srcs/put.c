/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:41:54 by msarr             #+#    #+#             */
/*   Updated: 2015/03/01 19:41:57 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int			put_msg_middle(t_game *game, WINDOW *win, char *str, int flag)
{
	int		i;

	if (win)
	{
		i = ft_strlen(str);
		if (flag == 1)
			werase(win);
		mvwprintw(win, game->pady / 2, (game->padx / 2) - i / 2, str);
		box(win, ACS_VLINE, ACS_HLINE);
		wrefresh(win);
	}
	return (0);
}

int			put_msg(WINDOW *win, char *str, int flag)
{
	if (win)
	{
		if (flag == 1)
			werase(win);
		waddstr(win, str);
		wrefresh(win);
	}
	return (0);
}

void		put_score(t_game *game)
{
	t_score	*score;

	if (game->size == 6)
	{
		score = game->scorelist;
		werase(game->win);
		put_msg(game->win, "LIST DES SCORES\n", 2);
		while (score)
		{
			put_msg(game->win, "|", 2);
			put_msg(game->win, score->name, 2);
			put_msg(game->win, " ", 2);
			put_msg(game->win, ft_itoa(score->val), 2);
			put_msg(game->win, "\n", 2);
			score = score->next;
		}
	}
	else
		ft_exit("SEE YA", game);
}

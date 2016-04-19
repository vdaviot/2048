/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:42:54 by msarr             #+#    #+#             */
/*   Updated: 2015/11/26 22:26:05 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		up2(t_game *game, int x, int y)
{
	int			z;

	z = y - 1;
	while (z >= 0)
	{
		if (!game->array[z][x].val)
			z--;
		else if (game->array[y][x].val == game->array[z][x].val)
		{
			game->array[y][x].val += game->array[z][x].val;
			put_msg_middle(game, game->array[y][x].win,
				ft_itoa(game->array[y][x].val), 1);
			put_msg_middle(game, game->array[z][x].win, "", 1);
			game->score += game->array[y][x].val;
			if (game->array[y][x].val == WIN_VALUE)
				game->state = 1;
			game->array[z][x].val = 0;
			break ;
		}
		else
			break ;
	}
}

void			ft_move_up(t_game *game, int x)
{
	int			y;
	int			z;

	y = 0;
	while (y < game->size)
	{
		if (!game->array[y][x].val)
		{
			z = y + 1;
			while (z < game->size)
			{
				if (game->array[z][x].val)
				{
					game->array[y][x].val = game->array[z][x].val;
					put_msg_middle(game, game->array[y][x].win,
						ft_itoa(game->array[y][x].val), 1);
					put_msg_middle(game, game->array[z][x].win, "", 1);
					game->array[z][x].val = 0;
					break ;
				}
				z++;
			}
		}
		y++;
	}
}

void			up(t_game *game)
{
	int			x;
	int			y;

	x = 0;
	while (x < game->size)
	{
		y = game->size - 1;
		while (y >= 0)
		{
			if (game->array[y][x].val)
				up2(game, x, y);
			y--;
		}
		ft_move_up(game, x);
		x++;
	}
}

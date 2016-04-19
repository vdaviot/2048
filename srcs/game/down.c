/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 20:09:15 by vdaviot           #+#    #+#             */
/*   Updated: 2015/03/01 20:09:17 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		down2(t_game *game, int x, int y)
{
	int			z;

	z = y + 1;
	while (z < game->size)
	{
		if (!game->array[z][x].val)
			z++;
		else if ((game->array[y][x].val == game->array[z][x].val))
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

static void		ft_move_down(t_game *game, int x)
{
	int			y;
	int			z;

	y = game->size - 1;
	while (y >= 0)
	{
		if (!game->array[y][x].val)
		{
			z = y - 1;
			while (z >= 0)
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
				z--;
			}
		}
		y--;
	}
}

void			down(t_game *game)
{
	int			x;
	int			y;

	x = 0;
	while (x < game->size)
	{
		y = 0;
		while (y < game->size)
		{
			if (game->array[y][x].val)
				down2(game, x, y);
			y++;
		}
		ft_move_down(game, x);
		x++;
	}
}

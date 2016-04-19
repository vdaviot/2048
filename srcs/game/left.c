/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 20:10:00 by vdaviot           #+#    #+#             */
/*   Updated: 2015/03/01 20:10:03 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		left2(t_game *game, int x, int y)
{
	int			z;

	z = x - 1;
	while (z >= 0)
	{
		if (!game->array[y][z].val)
			z--;
		else if ((game->array[y][x].val == game->array[y][z].val))
		{
			game->array[y][x].val += game->array[y][z].val;
			put_msg_middle(game, game->array[y][x].win,
				ft_itoa(game->array[y][x].val), 1);
			put_msg_middle(game, game->array[y][z].win, "", 1);
			game->score += game->array[y][x].val;
			if (game->array[y][x].val == WIN_VALUE)
				game->state = 1;
			game->array[y][z].val = 0;
			break ;
		}
		else
			break ;
	}
}

static void		ft_move_left(t_game *game, int y)
{
	int			x;
	int			z;

	x = 0;
	while (x < game->size)
	{
		if (!game->array[y][x].val)
		{
			z = x + 1;
			while (z < game->size)
			{
				if (game->array[y][z].val)
				{
					game->array[y][x].val = game->array[y][z].val;
					put_msg_middle(game, game->array[y][x].win,
						ft_itoa(game->array[y][x].val), 1);
					put_msg_middle(game, game->array[y][z].win, "", 1);
					game->array[y][z].val = 0;
					break ;
				}
				z++;
			}
		}
		x++;
	}
}

void			left(t_game *game)
{
	int			x;
	int			y;

	y = 0;
	while (y < game->size)
	{
		x = game->size - 1;
		while (x >= 0)
		{
			if (game->array[y][x].val)
				left2(game, x, y);
			x--;
		}
		ft_move_left(game, y);
		y++;
	}
}

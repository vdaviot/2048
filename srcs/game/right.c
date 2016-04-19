/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 20:10:10 by vdaviot           #+#    #+#             */
/*   Updated: 2015/03/01 20:10:12 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		right2(t_game *game, int x, int y)
{
	int			z;

	z = x + 1;
	while (z < game->size)
	{
		if (!game->array[y][z].val)
			z++;
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

void			ft_move_right(t_game *game, int y)
{
	int			x;
	int			z;

	x = game->size - 1;
	while (x >= 0)
	{
		if (!game->array[y][x].val)
		{
			z = x - 1;
			while (z >= 0)
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
				z--;
			}
		}
		x--;
	}
}

void			right(t_game *game)
{
	int			x;
	int			y;

	y = 0;
	while (y < game->size)
	{
		x = 0;
		while (x < game->size)
		{
			if (game->array[y][x].val)
				right2(game, x, y);
			x++;
		}
		ft_move_right(game, y);
		y++;
	}
}

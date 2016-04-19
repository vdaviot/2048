/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_2048.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:31:27 by vdaviot           #+#    #+#             */
/*   Updated: 2015/02/28 15:31:28 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int	is_full(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->size)
	{
		j = 0;
		while (j < game->size)
		{
			if (!game->array[i][j].val)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void		wrand(t_game *game)
{
	int		x;
	int		pn;
	int		pm;

	x = rand() % 5;
	if (x < 2)
		x = 2;
	if (x > 2)
		x = 4;
	if (is_full(game))
		return ;
	while (1)
	{
		pm = rand() % game->size;
		pn = rand() % game->size;
		if (!game->array[pm][pn].val)
		{
			game->array[pm][pn].val = x;
			put_msg_middle(game, game->array[pm][pn].win, ft_itoa(x), 1);
			break ;
		}
	}
}

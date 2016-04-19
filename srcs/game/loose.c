/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loose.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 23:00:06 by msarr             #+#    #+#             */
/*   Updated: 2015/03/01 23:00:08 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		loose(t_game *game)
{
	int		i;
	int		j;
	int		z;

	i = 0;
	while (i < game->size)
	{
		j = 0;
		while (j < game->size)
		{
			z = j + 1;
			while (z < game->size)
			{
				if (game->array[i][j].val == (game->array[i][z].val))
					return (1);
				else if (!game->array[i][z].val)
					z++;
				else
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		loose1(t_game *game)
{
	int		i;
	int		j;
	int		z;

	j = 0;
	while (j < game->size)
	{
		i = 0;
		while (i < game->size)
		{
			z = i + 1;
			while (z < game->size)
			{
				if (game->array[i][j].val == (game->array[i][z].val))
					return (1);
				else if (!game->array[i][z].val)
					z++;
				else
					return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

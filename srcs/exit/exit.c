/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 09:54:57 by msarr             #+#    #+#             */
/*   Updated: 2015/03/01 09:54:57 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void		del_win(WINDOW **win)
{
	if (win && *win)
	{
		delwin(*win);
		*win = NULL;
	}
}

void		del_menu(t_game *game)
{
	if (game->menulist)
	{
		del_win(&game->menulist[0]);
		del_win(&game->menulist[1]);
		del_win(&game->menulist[2]);
		ft_memdel((void **)&(game->menulist));
	}
}

void		del_array(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			del_win(&game->array[i][j].win);
			j++;
		}
		i++;
	}
}

int			ft_exit(char *str, t_game *game)
{
	char	*str1;

	del_win(&game->menubar);
	del_win(&game->win);
	del_win(&game->msgbar);
	endwin();
	ft_putstr("Surname :");
	get_next_line(1, &str1);
	score_save(game, str1);
	ft_putstr("Game_2048: ");
	ft_putendl(str);
	exit(0);
}

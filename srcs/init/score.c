/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 14:26:42 by msarr             #+#    #+#             */
/*   Updated: 2015/11/26 22:31:31 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static t_score	*new_score(char *name, int val)
{
	t_score		*s;

	if ((s = malloc(sizeof(t_score))))
	{
		s->name = ft_strdup(name);
		s->val = val;
		s->next = NULL;
	}
	return (s);
}

static int		add_score(t_game *game, char *name, int val)
{
	t_score		*tmp;
	t_score		*tmp2;

	if (!game->scorelist || game->scorelist->val <= val)
	{
		tmp = new_score(name, val);
		tmp->next = game->scorelist;
		game->scorelist = tmp;
		return (1);
	}
	tmp = game->scorelist;
	tmp2 = tmp;
	while (tmp && tmp->val >= val)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	if ((tmp2->next = new_score(name, val)))
		tmp2->next->next = tmp;
	return (1);
}

int				score_init(t_game *game)
{
	int			fd;
	char		*str;
	char		**t;

	fd = open("./score.txt", O_RDWR | O_CREAT, 0755);
	if (fd > 1)
	{
		while (get_next_line(fd, &str))
		{
			t = ft_strsplit(str, ' ');
			add_score(game, t[0], ft_atoi(t[1]));
		}
	}
	else
		put_msg(game->msgbar, "Unable to open score file.", 1);
	return (0);
}

int				score_save(t_game *game, char *name)
{
	int			fd;
	char		*str;
	t_score		*s;

	fd = open("./score.txt", O_RDWR | O_CREAT, 0755);
	s = game->scorelist;
	if (fd > 1)
	{
		while (s)
		{
			str = ft_strjoin(s->name, " ");
			str = ft_strjoin(str, ft_itoa(s->val));
			write(fd, str, ft_strlen(str));
			s = s->next;
		}
		str = ft_strjoin(name, " ");
		str = ft_strjoin(str, ft_itoa(game->score));
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
	}
	else
		put_msg(game->msgbar, "Unable to open score file.", 1);
	return (0);
}

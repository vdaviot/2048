/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:56:20 by msarr             #+#    #+#             */
/*   Updated: 2015/02/27 20:56:20 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include <stdlib.h>
# include <termios.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <fcntl.h>
# include <curses.h>
# include <term.h>
# include <ncurses.h>
# include "libft.h"

/*
** STRUCTS ENUM AND DEFINE
*/

# define ENTER			10
# define ESCAPE			27
# define RANDR(lo,hi)	((lo) + (((hi)-(lo)) * drand48()))

typedef struct termios	t_term;

typedef struct s_score	t_score;

enum			e_const
{
	WIN_VALUE = 16
};

typedef struct	s_score
{
	int			val;
	char		*name;
	t_score		*next;
}				t_score;

typedef struct	s_win
{
	int			val;
	WINDOW		*win;
}				t_win;

typedef struct	s_game
{
	int			win_h;
	int			win_w;
	int			startx;
	int			padx;
	int			starty;
	int			pady;
	int			size;
	int			state;
	int			score;
	t_score		*scorelist;
	WINDOW 		*menubar;
	WINDOW 		*scorebar;
	WINDOW		*msgbar;
	WINDOW		*win;
	WINDOW		**menulist;	
	t_win		array[5][5];
}				t_game;

t_game		*glob;

void		mywinch(int i);
int 		menu(t_game *game);
int			term_init(void);
int			start(t_game *game);
int			setwins(t_game *game);
void		del_win(WINDOW **win);
void		del_menu(t_game *game);
int			padding(t_game *game);
int			score_init(t_game *game);
int			put_msg(WINDOW *win, char *str, int flag);
int			ft_exit(char *str, t_game *game);
int			term_exit(void);
void		set_plateau(t_game *game);
void		up(t_game *game);
void		left(t_game *game);
void		right(t_game *game);
void		down(t_game *game);
int			play(t_game *game);
void		wrand(t_game *game);
void		del_array(t_game *game);
void		put_score(t_game *game);
int			loose(t_game *game);
int			loose1(t_game *game);
int			put_msg_middle(t_game *game, WINDOW *win, char *str, int flag);
int			score_save(t_game *game, char *name);

#endif
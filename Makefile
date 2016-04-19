# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msarr <msarr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/27 20:51:23 by msarr             #+#    #+#              #
#    Updated: 2015/11/26 22:26:26 by vdaviot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_2048

MAKE = make
CC = gcc
RM = /bin/rm
LDIR = libft/
SDIR = srcs/
IDIR = $(SDIR)init/
EDIR = $(SDIR)exit/
GDIR = $(SDIR)game/

SRC = $(SDIR)main.c $(SDIR)menu.c $(SDIR)play.c $(SDIR)put.c\
	  $(IDIR)win.c $(IDIR)score.c \
	  $(GDIR)up.c $(GDIR)down.c $(GDIR)left.c $(GDIR)right.c $(GDIR)rand.c \
	  $(GDIR)loose.c \
	  $(EDIR)exit.c
OBJ = $(SRC:.c=.o)
INC = -I includes -I $(LDIR)includes
LIB = ./libft/libft.a
LDFLAGS += -lncurses
CFLAGS = 

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[31;1m"
	@echo -n '---> Creating the Libft... <---'
	@echo "\033[0m"
	$(MAKE) re -C $(LDIR)
	@echo "\033[31;1m"
	@echo -n '---> Compilation in progress... <---'
	@echo "\033[0m"
	$(CC) $(CFLAGS) $(INC) $^ -o $(NAME) $(LDFLAGS) $(LIB)
	@echo "\033[1;32m"
	@echo -n '---> DONE ! <---'
	@echo "\033[0m"

%.o:%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@echo "\033[31;1m"
	@echo -n '---> Clean : <---'
	@echo "\033[0m"
	$(RM) -rf $(OBJ)
	$(MAKE) clean -C $(LDIR)
	@echo "\033[1;32m"
	@echo -n '---> DONE ! <---'
	@echo "\033[0m"

fclean: clean
	@echo "\033[31;1m"
	@echo -n '---> FClean : <---'
	@echo "\033[0m"
	$(RM) -rf $(NAME)
	$(MAKE) fclean -C $(LDIR)
	@echo "\033[1;32m"
	@echo -n '---> DONE ! <---'
	@echo "\033[0m"

re: fclean all

.PHONY: all name clean fclean re

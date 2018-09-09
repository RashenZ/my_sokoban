##
## Makefile for emacs in /home/Victor/101pong
## 
## Made by Victor Zhu
## Login   <Victor@epitech.net>
## 
## Started on  Mon Nov  7 11:11:25 2016 Victor Zhu
## Last update Wed Dec 21 14:16:37 2016 Victor Zhu
##

CC	=	gcc

RM	=	rm -f

//CFLAGS	+=	-Wextra -Wall -Werror
CFLAGS	+=	-I./include/

SRCS	=	lib/my_putchar.c	\
		lib/my_put_nbr.c	\
		lib/my_putstr.c		\
		lib/my_strcpy.c		\
		lib/my_strdup.c		\
		lib/my_strlen.c		\
		src/menu_file/menu_start.c	\
		src/menu_file/menu_move.c	\
		src/menu_file/select_level.c	\
		src/menu_file/redirect.c	\
		src/menu_file/option.c		\
		src/menu_file/option_move.c	\
		src/menu_file/help.c		\
		src/soko_window.c		\
		src/color_map.c			\
		src/player_move.c		\
		src/player_move_casewin.c	\
		src/player_else_move.c		\
		src/man_info.c			\
		src/player_key.c		\
		src/error.c			\
		src/when_you_won.c		\
		src/main.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	my_sokoban

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) -lncurses

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	all clean

.PHONY:	all clean fclean re

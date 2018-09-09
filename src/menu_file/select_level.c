/*
** menu.c for emacs in /home/Victor/PSU_2016_my_sokoban/bonus
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Fri Dec 16 08:51:24 2016 Victor Zhu
** Last update Wed Dec 21 14:24:48 2016 Victor Zhu
*/

#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <ncurses.h>
#include "my.h"

struct dirent	*check_alloc_dirent(struct dirent *ls)
{
  ls = malloc(sizeof(*ls));
  if (ls == NULL)
    exit(84);
  return (ls);
}

int	display_level(char **level, int n, int selection)
{
  int	y;
  int	x;
  int	i;

  i = 0;
  getmaxyx(stdscr,y,x);
  clear();
  while (level[i] != NULL)
    {
      if (selection == i)
	{
	  attron(COLOR_PAIR(1));
	  mvprintw(y / 2.5 + n, x / 2.5,"%s", level[i]);
	  attroff(COLOR_PAIR(1));
	}
      else
	mvprintw(y / 2.5 + n, x / 2.5,"%s", level[i]);
      i = i + 1;
      n = n + 1;
    }
  return (0);
}

int	move_level(char **level, int selection, int ch)
{
  if (ch == KEY_UP)
    {
      clear();
      if (selection == 4)
	selection = 9;
      else
	selection = selection - 1;
      display_level(level, 0, selection);
    }
  else if (ch == KEY_DOWN)
    {
      clear();
      if (selection == 9)
	selection = 4;
      else
	selection = selection + 1;
      display_level(level, 0, selection);
    }
  return (selection);
}

int	move_select_level(char **level, int selection, char **sum)
{
  int	ch;
  char	**av;

  if ((av = malloc(sizeof(char*) * 2 + 1)) == NULL)
    exit(80);
  ch = getch();
  while (ch != 27)
    {
      selection = move_level(level, selection, ch);
      ch = getch();
      if (ch == 10)
	redirect_level(selection, av);
    }
  clear();
  display_menu(sum, 6);
  return (0);
}

int	my_select_level(char **sum)
{
  FILE	*file;
  char	*line;
  unsigned long	len;
  char	**level;
  int	i;

  line = NULL;
  len = 0;
  i = 0;
  if ((level = malloc(sizeof(char*) * 12 + 1)) == NULL)
    exit(80);
  file = fopen("file/select_my_level", "r");
  if (file == NULL)
    exit(80);
  while ((getline(&line, &len, file)) != -1)
    {
      level[i] = my_strdup(line);
      i = i + 1;
    }
  level[i] = NULL;
  if (line)
    free(line);
  display_level(level, 0, 4);
  move_select_level(level, 4, sum);
  return (0);
}

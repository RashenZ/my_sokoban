/*
** menu_start.c for emacs in /home/Victor/PSU_2016_my_sokoban/bonus
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Sat Dec 17 16:30:19 2016 Victor Zhu
** Last update Tue Dec 20 19:34:11 2016 Victor Zhu
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "my.h"

void	disp_select(char **sum, int i, int n)
{
  int	y;
  int	x;

  getmaxyx(stdscr,y,x);
  attron(COLOR_PAIR(1));
  mvprintw(y/2.5 + n, x/2.5,"%s", sum[i]);
  attroff(COLOR_PAIR(1));
}

int	display_menu(char **sum, int selection)
{
  int	y;
  int	x;
  int	i;
  int	n;

  i = 0;
  n = 0;
  getmaxyx(stdscr,y,x);
  while (sum[i] != NULL)
    {
      if (selection == i)
	disp_select(sum, i, n);
      else
	mvprintw(y/2.5 + n, x/2.5,"%s", sum[i]);
      i = i + 1;
      n = n + 1;
    }
  return (0);
}

int	start_menu(char **sum)
{
  if (initscr() == NULL)
    exit(12);
  if (keypad(stdscr, true) == ERR)
    exit(12);
  if (noecho() == ERR)
    exit(12);
  if (curs_set(0) == ERR)
    exit(12);
  if (start_color() == ERR)
    exit(12);
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  display_menu(sum, 5);
  move_menu(sum, 5);
  if (endwin() == ERR)
    exit(12);
  return (0);
}

int	prepare_menu()
{
  FILE	*file;
  char	*line;
  unsigned long	len;
  char	**sum;
  int	i;

  line = NULL;
  len = 0;
  i = 0;
  if ((sum = malloc(sizeof(char*) * 13 + 1)) == NULL)
    exit(80);
  file = fopen("file/summary", "r");
  if (file == NULL)
    exit (80);
  while ((getline(&line, &len, file)) != -1)
    {
      sum[i] = my_strdup(line);
      i = i + 1;
    }
  sum[i] = NULL;
  if (line)
    free (line);
  start_menu(sum);
  return (0);
}

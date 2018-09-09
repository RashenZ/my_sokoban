/*
** help.c for emacs in /home/Victor/PSU_2016_my_sokoban/bonus
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Sun Dec 18 06:24:03 2016 Victor Zhu
** Last update Mon Dec 19 15:25:39 2016 Victor Zhu
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

void	my_help(char **sum, int n)
{
  int	y;
  int	x;
  int	ch;
  FILE	*file;
  char	*line;
  unsigned long	len;

  ch = 0;
  getmaxyx(stdscr,y,x);
  line = NULL;
  len = 0;
  file = fopen("file/help", "r");
  if (file == NULL)
    exit(80);
  while ((getline(&line, &len, file)) != -1)
    {
      mvprintw(y / 2.5 + n, x / 2.5,"%s", line);
      n = n + 1;
    }
  while (ch != 10)
    ch = getch();
  clear();
  display_menu(sum, 8);
  move_menu(sum, 8);
}

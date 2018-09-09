/*
** option.c for emacs in /home/Victor/PSU_2016_my_sokoban/bonus
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Sun Dec 18 03:18:26 2016 Victor Zhu
** Last update Tue Dec 20 20:11:38 2016 Victor Zhu
*/

#include <stdlib.h>
#include <ncurses.h>
#include "my.h"

void	option_select(char **stropt, int n, int i)
{
  int	y;
  int	x;

  getmaxyx(stdscr,y,x);
  attron(COLOR_PAIR(1));
  mvprintw(y / 2.5 + n, x / 2.5,"%s", stropt[i]);
  attroff(COLOR_PAIR(1));
}

int	display_option(char **stropt, int n, int selection)
{
  int	y;
  int	x;
  int	i;

  i = 0;
  getmaxyx(stdscr,y,x);
  clear();
  while (stropt[i] != NULL)
    {
      if (selection == i)
	option_select(stropt, n, i);
      else
	mvprintw(y / 2.5 + n, x / 2.5,"%s", stropt[i]);
      i = i + 1;
      n = n + 1;
    }
  return (0);
}

int	my_option(int i)
{
  FILE	*file;
  char	*line;
  char	**stropt;
  unsigned long	len;

  line = NULL;
  len = 0;
  if ((stropt = malloc(sizeof(char*) * 13 + 1)) == NULL)
    exit(80);
  if ((file = fopen("file/option", "r")) == NULL)
    exit(84);
  while ((getline(&line, &len, file)) != -1)
    {
      stropt[i] = my_strdup(line);
      i = i + 1;
    }
  stropt[i] = NULL;
  display_option(stropt, 0, 4);
  option_move(stropt, 4);
  if (fclose(file) == EOF)
    exit(80);
  return (0);
}

/*
** soko_window.c for emacs in /home/Victor/PSU_2016_my_sokoban
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Fri Dec  9 13:35:59 2016 Victor Zhu
** Last update Wed Dec 21 13:06:32 2016 Victor Zhu
*/

#include <stdlib.h>
#include <ncurses.h>
#include "my.h"

int	*color_map(int *tab, int x, int y)
{
  if (x == 3)
    {
      attron(COLOR_PAIR(1));
      attron(A_BOLD);
      mvprintw(tab[2], tab[3],"#");
      attroff(COLOR_PAIR(1));
      attroff(A_BOLD);
    }
  else if (x == 1)
    {
      tab[4] = tab[0];
      tab[5] = tab[1];
      mvprintw(tab[2], tab[3],"P");
    }
  else if (y == 1)
    {
      attron(COLOR_PAIR(2));
      attron(A_BOLD);
      mvprintw(tab[2], tab[3],"V");
      attroff(COLOR_PAIR(2));
      attroff(A_BOLD);
    }
  return (tab);
}

int	*show_map(char **soko_map, int *tab, int x)
{
  while (soko_map[tab[0]] != '\0')
    {
      if (soko_map[tab[0]][tab[1]] == 'P' && x == 1)
	tab = color_map(tab, 1, 0);
      if (soko_map[tab[0]][tab[1]] == '#')
	tab = color_map(tab, 3, 0);
      if (soko_map[tab[0]][tab[1]] == 'V')
	tab = color_map(tab, 0, 1);
      if (soko_map[tab[0]][tab[1]] == ' ' || soko_map[tab[0]][tab[1]] == 'X'
	  || soko_map[tab[0]][tab[1]] == 'O')
	color_map_2(tab, soko_map);
      tab[1] = tab[1] + 1;
      tab[3] = tab[3] + 1;
      if (soko_map[tab[0]][tab[1]] == '\0')
	{
	  tab[0] = tab[0] + 1;
	  tab[1] = 0;
	  tab[2] = tab[2] + 1;
	  tab[3] = 0;
	}
    }
  return (tab);
}

int	*tab_value(int *tab, int x_nbr)
{
  tab[0] = 0;
  tab[1] = 0;
  tab[2] = 0;
  tab[3] = 0;
  tab[4] = 0;
  tab[5] = 0;
  tab[6] = x_nbr;
  tab[7] = 10;
  return (tab);
}

int	color()
{
  init_pair(1, COLOR_BLUE, COLOR_BLUE);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  init_pair(3, COLOR_BLACK, COLOR_YELLOW);
}

void	start_window(char **soko_map, char **av, int x_nbr, int i)
{
  int	*tab;

  if ((tab = malloc(sizeof(int) * 8)) == NULL)
    exit(80);
  tab = tab_value(tab, x_nbr);
  if (initscr() == NULL)
    exit(84);
  if (nodelay(stdscr, true) == ERR)
    exit(84);
  if (keypad(stdscr, true) == ERR)
    exit(84);
  if (curs_set(0) == ERR)
    exit(84);
  if (noecho() == ERR)
    exit(84);
  if (start_color() == ERR)
    exit(84);
  color();
  tab = show_map(soko_map, tab, 1);
  soko_map[tab[4]][tab[5]] = ' ';
  player_flags(tab, soko_map, av, i);
  when_you_won();
  if (endwin() == ERR)
    exit(84);
  prepare_menu();
}

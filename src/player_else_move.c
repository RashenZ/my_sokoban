/*
** play_else_move.c for emacs in /home/Victor/PSU_2016_my_sokoban
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Wed Dec 14 14:49:14 2016 Victor Zhu
** Last update Tue Dec 20 11:01:55 2016 Victor Zhu
*/

#include <ncurses.h>
#include "my.h"

int	*show_move_else(int *tab, char **soko_map)
{
  tab = show_map(soko_map, tab, 2);
  mvprintw(tab[4], tab[5],"P");
  return (tab);
}

int	*move_else_up(int *tab, char **soko_map)
{
  if ((soko_map[tab[4]][tab[5]] == 'V' && soko_map[tab[4] - 1][tab[5]] == '#')
      || (soko_map[tab[4]][tab[5]] == 'V' &&
	  soko_map[tab[4] - 1][tab[5]] == 'X')
      || (soko_map[tab[4]][tab[5]] == 'X' &&
	  soko_map[tab[4] - 1][tab[5]] == 'V')
      || (soko_map[tab[4]][tab[5]] == 'V' &&
	  soko_map[tab[4] - 1][tab[5]] == 'V'))
    {
      tab[4] = tab[4] + 1;
      tab = show_map(soko_map, tab, 0);
      mvprintw(tab[4], tab[5], "P");
    }
  else if (soko_map[tab[4]][tab[5]] == 'V' &&
	   soko_map[tab[4] - 1][tab[5]] == 'O')
    {
      soko_map[tab[4] - 1][tab[5]] = 'V';
      soko_map[tab[4]][tab[5]] = 'O';
      tab = show_map(soko_map, tab, tab[7]);
      mvprintw(tab[4], tab[5],"P");
    }
  else
    tab = show_move_else(tab, soko_map);
  return (tab);
}

int	*move_else_down(int *tab, char **soko_map)
{
  if ((soko_map[tab[4]][tab[5]] == 'V' && soko_map[tab[4] + 1][tab[5]] == '#')
      || (soko_map[tab[4]][tab[5]] == 'V' &&
	  soko_map[tab[4] + 1][tab[5]] == 'X')
      || (soko_map[tab[4]][tab[5]] == 'X' &&
	  soko_map[tab[4] + 1][tab[5]] == 'V')
      || (soko_map[tab[4]][tab[5]] == 'V' &&
	  soko_map[tab[4] + 1][tab[5]] == 'V'))
    {
      tab[4] = tab[4] - 1;
      tab = show_map(soko_map, tab, 0);
      mvprintw(tab[4], tab[5],"P");
    }
  else if (soko_map[tab[4]][tab[5]] == 'V' &&
	   soko_map[tab[4] + 1][tab[5]] == 'O')
    {
      soko_map[tab[4] + 1][tab[5]] = 'V';
      soko_map[tab[4]][tab[5]] = 'O';
      tab = show_map(soko_map, tab, tab[7]);
      mvprintw(tab[4], tab[5],"P");
    }
  else
    tab = show_move_else(tab, soko_map);
  return (tab);
}

int	*move_else_left(int *tab, char **soko_map)
{
  if ((soko_map[tab[4]][tab[5]] == 'V' && soko_map[tab[4]][tab[5] - 1] == '#')
      || (soko_map[tab[4]][tab[5]] == 'V' &&
	  soko_map[tab[4]][tab[5] - 1] == 'X')
      || (soko_map[tab[4]][tab[5]] == 'X' &&
	  soko_map[tab[4]][tab[5] - 1] == 'V')
      || (soko_map[tab[4]][tab[5]] == 'V' &&
	  soko_map[tab[4]][tab[5] - 1] == 'V'))
    {
      tab[5] = tab[5] + 1;
      tab = show_map(soko_map, tab, 0);
      mvprintw(tab[4], tab[5],"P");
    }
  else if (soko_map[tab[4]][tab[5]] == 'V' &&
	   soko_map[tab[4]][tab[5] - 1] == 'O')
    {
      soko_map[tab[4]][tab[5] - 1] = 'V';
      soko_map[tab[4]][tab[5]] = 'O';
      tab = show_map(soko_map, tab, tab[7]);
      mvprintw(tab[4], tab[5],"P");
    }
  else
    tab = show_move_else(tab, soko_map);
  return (tab);
}

int	*move_else_right(int *tab, char **soko_map)
{
  if ((soko_map[tab[4]][tab[5]] == 'V' && soko_map[tab[4]][tab[5] + 1] == '#')
      || (soko_map[tab[4]][tab[5]] == 'V' &&
	  soko_map[tab[4]][tab[5] + 1] == 'X')
      || (soko_map[tab[4]][tab[5]] == 'X' &&
	  soko_map[tab[4]][tab[5] + 1] == 'V')
      || (soko_map[tab[4]][tab[5]] == 'V' &&
	  soko_map[tab[4]][tab[5] + 1] == 'V'))
    {
      tab[5] = tab[5] - 1;
      tab = show_map(soko_map, tab, 0);
      mvprintw(tab[4], tab[5],"P");
    }
  else if (soko_map[tab[4]][tab[5]] == 'V' &&
	   soko_map[tab[4]][tab[5] + 1] == 'O')
    {
      soko_map[tab[4]][tab[5] + 1] = 'V';
      soko_map[tab[4]][tab[5]] = 'O';
      tab = show_map(soko_map, tab, tab[7]);
      mvprintw(tab[4], tab[5],"P");
    }
  else
    tab = show_move_else(tab, soko_map);
  return (tab);
}

/*
** player_move_casewin.c for emacs in /home/Victor/PSU_2016_my_sokoban
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Sat Dec 10 10:38:30 2016 Victor Zhu
** Last update Thu Dec 15 18:45:41 2016 Victor Zhu
*/

#include <ncurses.h>
#include "my.h"

int	*move_else(int *tab, char **soko_map)
{
  tab = show_map(soko_map, tab, 2);
  mvprintw(tab[4], tab[5],"P");
  return (tab);
}

int	*move_into_oup(char **soko_map, int *tab)
{
  if (soko_map[tab[4]][tab[5]] == 'X' && soko_map[tab[4] - 1][tab[5]] == 'O')
    {
      soko_map[tab[4] - 1][tab[5]] = 'V';
      soko_map[tab[4]][tab[5]] = ' ';
      tab[7] = tab[7] + 1;
      tab[6] = tab[6] - 1;
      tab = show_map(soko_map, tab, tab[7]);
      mvprintw(tab[4], tab[5],"P");
    }
  else if (soko_map[tab[4]][tab[5]] == 'V' &&
	   soko_map[tab[4] - 1][tab[5]] == ' ')
    {
      soko_map[tab[4] - 1][tab[5]] = 'X';
      soko_map[tab[4]][tab[5]] = 'O';
      tab[7] = tab[7] - 1;
      tab[6] = tab[6] + 1;
      tab = show_map(soko_map, tab, tab[7]);
      mvprintw(tab[4], tab[5],"P");
    }
  return (tab);
}

int	*move_into_odown(char **soko_map, int *tab)
{
  if (soko_map[tab[4]][tab[5]] == 'X' && soko_map[tab[4] + 1][tab[5]] == 'O')
    {
      soko_map[tab[4] + 1][tab[5]] = 'V';
      soko_map[tab[4]][tab[5]] = ' ';
      tab[7] = tab[7] + 1;
      tab[6] = tab[6] - 1;
      tab = show_map(soko_map, tab, tab[7]);
      mvprintw(tab[4], tab[5],"P");
    }
  else if (soko_map[tab[4]][tab[5]] == 'V' &&
	   soko_map[tab[4] + 1][tab[5]] == ' ')
    {
      soko_map[tab[4] + 1][tab[5]] = 'X';
      soko_map[tab[4]][tab[5]] = 'O';
      tab[7] = tab[7] - 1;
      tab[6] = tab[6] + 1;
      tab = show_map(soko_map, tab, tab[7]);
      mvprintw(tab[4], tab[5],"P");
    }
  return (tab);
}

int	*move_into_oleft(char **soko_map, int *tab)
{
  if (soko_map[tab[4]][tab[5]] == 'X' && soko_map[tab[4]][tab[5] - 1] == 'O')
    {
      soko_map[tab[4]][tab[5] - 1] = 'V';
      soko_map[tab[4]][tab[5]] = ' ';
      tab[7] = tab[7] + 1;
      tab[6] = tab[6] - 1;
      tab = show_map(soko_map, tab, tab[7]);
      mvprintw(tab[4], tab[5],"P");
    }
  else if (soko_map[tab[4]][tab[5]] == 'V' &&
	   soko_map[tab[4]][tab[5] - 1] == ' ')
    {
      soko_map[tab[4]][tab[5] - 1] = 'X';
      soko_map[tab[4]][tab[5]] = 'O';
      tab[7] = tab[7] - 1;
      tab[6] = tab[6] + 1;
      tab = show_map(soko_map, tab, tab[7]);
      mvprintw(tab[4], tab[5],"P");
    }
  return (tab);
}

int	*move_into_oright(char **soko_map, int *tab)
{
  if (soko_map[tab[4]][tab[5]] == 'X' && soko_map[tab[4]][tab[5] + 1] == 'O')
    {
      soko_map[tab[4]][tab[5] + 1] = 'V';
      soko_map[tab[4]][tab[5]] = ' ';
      tab[7] = tab[7] + 1;
      tab[6] = tab[6] - 1;
      tab = show_map(soko_map, tab, tab[7]);
      mvprintw(tab[4], tab[5],"P");
    }
  else if (soko_map[tab[4]][tab[5]] == 'V' &&
	   soko_map[tab[4]][tab[5] + 1] == ' ')
    {
      soko_map[tab[4]][tab[5] + 1] = 'X';
      soko_map[tab[4]][tab[5]] = 'O';
      tab[7] = tab[7] - 1;
      tab[6] = tab[6] + 1;
      tab = show_map(soko_map, tab, tab[7]);
      mvprintw(tab[4], tab[5],"P");
    }
  return (tab);
}

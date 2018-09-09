/*
** player_move.c for emacs in /home/Victor/PSU_2016_my_sokoban
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Fri Dec  9 16:55:27 2016 Victor Zhu
** Last update Sat Dec 17 11:11:28 2016 Victor Zhu
*/

#include <ncurses.h>
#include "my.h"

int	*move_up(int *tab, char **soko_map)
{
  clear();
  tab[4] = tab[4] - 1;
  if (soko_map[tab[4]][tab[5]] == 'X' && soko_map[tab[4] - 1][tab[5]] == ' ')
    {
      soko_map[tab[4] - 1][tab[5]] = 'X';
      soko_map[tab[4]][tab[5]] = ' ';
      tab = show_map(soko_map, tab, 0);
      mvprintw(tab[4], tab[5],"P");
    }
  else if ((soko_map[tab[4]][tab[5]] == 'X' &&
	    soko_map[tab[4] - 1][tab[5]] == '#') || (soko_map[tab[4]][tab[5]] == 'X'
						     && soko_map[tab[4] - 1][tab[5]] == 'X'))
    {
      tab[4] = tab[4] + 1;
      tab = show_map(soko_map, tab, 0);
      mvprintw(tab[4], tab[5], "P");
    }
  else if ((soko_map[tab[4]][tab[5]] == 'X' &&
	    soko_map[tab[4] - 1][tab[5]] == 'O') || (soko_map[tab[4]][tab[5]] == 'V'
						     && soko_map[tab[4] - 1][tab[5]] == ' '))
    tab = move_into_oup(soko_map, tab);
  else
    tab = move_else_up(tab, soko_map);
  return (tab);
}

int	*move_down(int *tab, char **soko_map)
{
  clear();
  tab[4] = tab[4] + 1;
  if (soko_map[tab[4]][tab[5]] == 'X' && soko_map[tab[4] + 1][tab[5]] == ' ')
    {
      soko_map[tab[4] + 1][tab[5]] = 'X';
      soko_map[tab[4]][tab[5]] = ' ';
      tab = show_map(soko_map, tab, 0);
      mvprintw(tab[4], tab[5], "P");
    }
  else if ((soko_map[tab[4]][tab[5]] == 'X' &&
	    soko_map[tab[4] + 1][tab[5]] == '#') || (soko_map[tab[4]][tab[5]] == 'X'
						     && soko_map[tab[4] + 1][tab[5]] == 'X'))
    {
      tab[4] = tab[4] - 1;
      tab = show_map(soko_map, tab, 0);
      mvprintw(tab[4], tab[5],"P");
    }
  else if ((soko_map[tab[4]][tab[5]] == 'X' &&
	    soko_map[tab[4] + 1][tab[5]] == 'O') || (soko_map[tab[4]][tab[5]] == 'V'
						     && soko_map[tab[4] + 1][tab[5]] == ' '))
    tab = move_into_odown(soko_map, tab);
  else
    tab = move_else_down(tab, soko_map);
  return (tab);
}

int	*move_left(int *tab, char **soko_map)
{
  clear();
  tab[5] = tab[5] - 1;
  if (soko_map[tab[4]][tab[5]] == 'X' && soko_map[tab[4]][tab[5] - 1] == ' ')
    {
      soko_map[tab[4]][tab[5] - 1] = 'X';
      soko_map[tab[4]][tab[5]] = ' ';
      tab = show_map(soko_map, tab, 0);
      mvprintw(tab[4], tab[5],"P");
    }
  else if ((soko_map[tab[4]][tab[5]] == 'X' &&
	    soko_map[tab[4]][tab[5] - 1] == '#') || (soko_map[tab[4]][tab[5]] == 'X'
						     && soko_map[tab[4]][tab[5] - 1] == 'X'))
    {
      tab[5] = tab[5] + 1;
      tab = show_map(soko_map, tab, 0);
      mvprintw(tab[4], tab[5],"P");
    }
  else if ((soko_map[tab[4]][tab[5]] == 'X' &&
	   soko_map[tab[4]][tab[5] - 1] == 'O') || (soko_map[tab[4]][tab[5]] == 'V'
						    && soko_map[tab[4]][tab[5] - 1] == ' '))
    tab = move_into_oleft(soko_map, tab);
  else
    tab = move_else_left(tab, soko_map);
  return (tab);
}

int	*move_right(int *tab, char **soko_map)
{
  clear();
  tab[5] = tab[5] + 1;
  if (soko_map[tab[4]][tab[5]] == 'X' && soko_map[tab[4]][tab[5] + 1] == ' ')
    {
      soko_map[tab[4]][tab[5] + 1] = 'X';
      soko_map[tab[4]][tab[5]] = ' ';
      tab = show_map(soko_map, tab, 0);
      mvprintw(tab[4], tab[5],"P");
    }
  else if ((soko_map[tab[4]][tab[5]] == 'X' &&
	    soko_map[tab[4]][tab[5] + 1] == '#') || (soko_map[tab[4]][tab[5]] == 'X'
						     && soko_map[tab[4]][tab[5] + 1] == 'X'))
    {
      tab[5] = tab[5] - 1;
      tab = show_map(soko_map, tab, 0);
      mvprintw(tab[4], tab[5],"P");
    }
  else if ((soko_map[tab[4]][tab[5]] == 'X' &&
	    soko_map[tab[4]][tab[5] + 1] == 'O') || (soko_map[tab[4]][tab[5]] == 'V'
						     && soko_map[tab[4]][tab[5] + 1] == ' '))
    tab = move_into_oright(soko_map, tab);
  else
    tab = move_else_right(tab, soko_map);
  return (tab);
}

int	player_flags(int *tab, char **soko_map, char **av, int i)
{
  int	ch;

  ch = getch();
  while (tab[6] != 0)
    {
      tab[0] = 0;
      tab[1] = 0;
      tab[2] = 0;
      tab[3] = 0;
      if (KEY_UP == ch && soko_map[tab[4] - 1][tab[5]] != '#' &&
	  tab[4] - 1 > 0)
	tab = move_up(tab, soko_map);
      if (KEY_DOWN == ch && soko_map[tab[4] + 1][tab[5]] != '#' &&
	  tab[4] + 2 < i)
	tab = move_down(tab, soko_map);
      if (KEY_LEFT == ch && soko_map[tab[4]][tab[5] - 1] != '#' && tab[5])
	tab = move_left(tab, soko_map);
      if (KEY_RIGHT == ch && soko_map[tab[4]][tab[5] + 1] != '#' &&
	  soko_map[tab[4]][tab[5]])
	tab = move_right(tab, soko_map);
      if (32 == ch)
	game_restart(av);
      ch = getch();
    }
  return (0);
}

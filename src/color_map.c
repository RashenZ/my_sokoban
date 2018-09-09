/*
** color_map.c for emacs in /home/Victor/PSU_2016_my_sokoban/bonus
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Tue Dec 20 20:30:56 2016 Victor Zhu
** Last update Wed Dec 21 11:05:44 2016 Victor Zhu
*/

#include <ncurses.h>
#include "my.h"

int	*color_map_2(int *tab, char **soko_map)
{
  //attron(COLOR_PAIR(3));
  mvprintw(tab[2], tab[3],"%c", soko_map[tab[0]][tab[1]]);
  //attroff(COLOR_PAIR(3));
  return (tab);
}

/*
** redirect.c for emacs in /home/Victor/PSU_2016/PSU_2016_my_sokoban/bonus/menu_file
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Wed Dec 21 14:17:44 2016 Victor Zhu
** Last update Wed Dec 21 15:03:19 2016 Victor Zhu
*/

#include "my.h"
#include <ncurses.h>

int	redirect_level(int selection, char **av)
{
  clear();
  if (selection == 4)
    av[1] = my_strdup("./map/map_nowall");
  else if (selection == 5)
    av[1] = my_strdup("./map/map_test");
  else if (selection == 6)
    av[1] = my_strdup("./map/map");
  else if (selection == 7)
    av[1] = my_strdup("./map/map_2");
  else if (selection == 8)
    av[1] = my_strdup("./map/map_3");
  else if (selection == 9)
    av[1] = my_strdup("./map/map_11");
  sokoban_start(av);
  return (0);
}

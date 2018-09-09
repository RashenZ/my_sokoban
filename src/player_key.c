/*
** player_flag.c for emacs in /home/Victor/PSU_2016_my_sokoban
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Sat Dec 10 05:43:32 2016 Victor Zhu
** Last update Mon Dec 12 22:30:40 2016 Victor Zhu
*/

#include <ncurses.h>
#include "my.h"

int	game_restart(char **av)
{
  clear();
  endwin();
  move(12,15);
  printw("game restarted B)");
  sokoban_start(av);
  return (0);
}

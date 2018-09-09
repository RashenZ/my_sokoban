/*
** option_move.c for emacs in /home/Victor/PSU_2016_my_sokoban/bonus/menu_file
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Tue Dec 20 01:58:00 2016 Victor Zhu
** Last update Tue Dec 20 04:42:47 2016 Victor Zhu
*/

#include <ncurses.h>
#include "my.h"

int	move_option(char **stropt, int selection, int ch)
{
  if (ch == KEY_UP)
    {
      clear();
      if (selection == 4)
	selection = 7;
      else
	selection = selection - 1;
      display_option(stropt, 0, selection);
    }
  else if (ch == KEY_DOWN)
    {
      clear();
      if (selection == 7)
	selection = 4;
      else
	selection = selection + 1;
      display_option(stropt, 0, selection);
    }
  return (selection);
}

int	option_move(char **stropt, int selection)
{
  int	ch;

  ch = getch();
  while (ch != 10)
    {
      selection = move_option(stropt, selection, ch);
      ch = getch();
    }
  return (0);
}

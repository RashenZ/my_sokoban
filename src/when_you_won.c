/*
** when_you_won.c for emacs in /home/Victor/PSU_2016_my_sokoban
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Sun Dec 11 14:26:43 2016 Victor Zhu
** Last update Tue Dec 20 04:22:35 2016 Victor Zhu
*/

#include <ncurses.h>
#include "my.h"

void	when_you_won()
{
  int	ch;

  clear();
  ch = getch();
  while (ch != 'q')
    {
      mvprintw(0, 0,"CONGRATULATION YOU WON THIS GAMUUUU");
      mvprintw(1, 0,"Pess 'q' for exit");
      ch = getch();
    }
  clear();
}

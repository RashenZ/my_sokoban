/*
** man_info.c for emacs in /home/Victor/PSU_2016_my_sokoban
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Thu Dec  8 18:22:49 2016 Victor Zhu
** Last update Fri Dec  9 11:19:59 2016 Victor Zhu
*/

#include "my.h"

void	man_my_sokoban()
{
  my_putstr("USAGE\n\t./my_sokoban map\n\nDESCRIPTION\n\tmap\t");
  my_putstr("file representing the warehouse map, containing `#` ");
  my_putstr("for walls\n\t\t`P` for the player, `X` for boxes ");
  my_putstr("and `O` for storage locations.\n");
}

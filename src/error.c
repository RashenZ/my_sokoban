/*
** error.c for emacs in /home/Victor/PSU_2016_my_sokoban
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Wed Dec 14 15:47:23 2016 Victor Zhu
** Last update Tue Dec 20 10:11:30 2016 Victor Zhu
*/

#include <stdlib.h>
#include <ncurses.h>
#include "my.h"

int	display_error()
{
  my_putstr("This map is invalid\n");
  exit(84);
}

int	check_p_nbr(char **soko_map, int i, int j)
{
  int	p_nbr;

  p_nbr = 0;
  while (soko_map[i] != '\0')
    {
      if (soko_map[i][j] == 'P')
	p_nbr = p_nbr + 1;
      j = j + 1;
      if (soko_map[i][j] == '\0')
	{
	  i = i + 1;
	  j = 0;
	}
    }
  if (p_nbr > 1)
    {
      my_putstr("This map is invalid: too much Player in this map");
      exit (84);
    }
  else if (p_nbr == 0)
    {
      my_putstr("This map is invalid: there's no player");
      exit(84);
    }
  return (0);
}

int	compare_o(int x_nbr, int o_nbr)
{
  if (o_nbr > x_nbr)
    {
      my_putstr("error: not enought box");
      exit (84);
    }
  return (0);
}

void	check_error(char **soko_map, int x_nbr, int i, int j)
{
  int	o_nbr;

  o_nbr = 0;
  while (soko_map[i] != '\0')
    {
      if (soko_map[i][j] == 'O' || soko_map[i][j] == 'X' ||
	  soko_map[i][j] == '#' || soko_map[i][j] == 'P' ||
	  soko_map[i][j] == ' ' || soko_map[i][j] == '\n')
	{
	  if (soko_map[i][j] == 'O')
	    o_nbr = o_nbr + 1;
	  j = j + 1;
	  if (soko_map[i][j] == '\0')
	    {
	      i = i + 1;
	      j = 0;
	    }
	}
      else
	display_error();
    }
  check_p_nbr(soko_map, 0, 0);
  compare_o(x_nbr, o_nbr);
}

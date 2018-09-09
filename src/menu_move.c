/*
** menu_move.c for emacs in /home/Victor/PSU_2016_my_sokoban/bonus
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Sun Dec 18 01:07:34 2016 Victor Zhu
** Last update Sun Dec 18 06:12:36 2016 Victor Zhu
*/

#include <stdlib.h>
#include <dirent.h>
#include <ncurses.h>
#include "my.h"

int	move_upordown(char **sum, int selection, int ch)
{
  if (ch == KEY_UP)
    {
      clear();
      if (selection == 5)
	selection = 9;
      else
	selection = selection - 1;
      display_menu(sum, selection);
    }
  else if (ch == KEY_DOWN)
    {
      clear();
      if (selection == 9)
	selection = 5;
      else
	selection = selection + 1;
      display_menu(sum, selection);
    }
  return (selection);
}

int	choice_selected_89(int selection)
{
  if (selection == 8)
    my_help()
  else if (selection == 9)
    {
      endwin();
      exit(0);
    }
  return (0);
}

int	choice_selected_567(int selection, char **av)
{
  DIR	*rep;
  struct dirent	*ls;

  rep = opendir("./map/");
  if (rep == NULL)
    exit(1);
  ls = NULL;
  ls = check_alloc_dirent(ls);
  if (selection == 5)
    {
      while ((ls = readdir(rep)) != NULL)
	{
	  if (ls->d_name[0] != '.')
	    {
	      clear();
	      av[1] = my_strdup("./map/map");
	      sokoban_start(av);
	    }
	}
    }
  else if (selection == 6)
    my_select_level();
  else if (selection == 7)
    my_option();
  return (0);
}

int	move_menu(char **sum, int selection)
{
  int	ch;
  char	**av;

  ch = getch();
  av = malloc(sizeof(char*) * 2 + 1);
  while (ch != 27)
    {
      selection = move_upordown(sum, selection, ch);
      if (ch == 10)
	{
	  choice_selected_567(selection, av);
	  choice_selected_89(selection);
	}
      ch = getch();
    }
  return (0);
}

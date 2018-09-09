/*
** menu_move.c for emacs in /home/Victor/PSU_2016_my_sokoban/bonus
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Sun Dec 18 01:07:34 2016 Victor Zhu
** Last update Wed Dec 21 14:29:27 2016 Victor Zhu
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

int	choice_selected_789(int selection, char **sum)
{
  if (selection == 7)
    {
      my_option(0);
      clear();
      display_menu(sum, 7);
    }
  if (selection == 8)
    {
      clear();
      my_help(sum, 0);
    }
  else if (selection == 9)
    {
      endwin();
      exit(0);
    }
  return (0);
}

int	choice_selected_56(int selection, char **av, char **sum)
{
  if (selection == 5)
    {
      clear();
      av[1] = my_strdup("./map/map");
      sokoban_start(av);
    }
  else if (selection == 6)
    {
      my_select_level(sum);
      clear();
      display_menu(sum, 6);
    }
  return (0);
}

int	move_menu(char **sum, int selection)
{
  int	ch;
  char	**av;

  ch = getch();
  if ((av = malloc(sizeof(char*) * 2 + 1)) == NULL)
    exit(80);
  while (ch)
    {
      selection = move_upordown(sum, selection, ch);
      if (ch == 10)
	{
	  choice_selected_56(selection, av, sum);
	  choice_selected_789(selection, sum);
	}
      ch = getch();
    }
  return (0);
}

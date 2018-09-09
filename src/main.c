/*
** main.c for emacs in /home/Victor/PSU_2016_my_sokoban
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Thu Dec  8 18:19:07 2016 Victor Zhu
** Last update Tue Dec 20 20:00:24 2016 Victor Zhu
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "my.h"

int	soko_line(char **av)
{
  FILE	*file;
  char	*line;
  unsigned long	len;
  int	i;

  line = NULL;
  len = 0;
  i = 0;
  file = fopen(av[1], "r");
  if (file == NULL)
    exit (EXIT_FAILURE);
  while ((getline(&line, &len, file)) != -1)
    i = i + 1;
  if (line)
    free (line);
  if (fclose(file) == EOF)
    exit(80);;
  return (i);
}

char	**file_size(char **av, int *line_nbr)
{
  FILE	*file;
  char	*line;
  char	**soko_map;
  unsigned long	len;
  int	i;

  line = NULL;
  len = 0;
  i = 0;
  file = fopen(av[1], "r");
  if (file == NULL)
    exit (EXIT_FAILURE);
  soko_map = malloc(sizeof(char*) * ((*line_nbr = soko_line(av)) + 1));
  while ((getline(&line, &len, file)) != -1)
    {
      soko_map[i] = my_strdup(line);
      i = i + 1;
    }
  soko_map[i] = NULL;
  if (line)
    free (line);
  if (fclose(file) == EOF)
    exit(80);
  return (soko_map);
}

int	find_x_nbr(char **soko_map)
{
  int	i;
  int	j;
  int	nbr;

  i = 0;
  j = 0;
  nbr = 0;
  while (soko_map[i] != '\0')
    {
      if (soko_map[i][j] == 'X')
	nbr = nbr + 1;
      j = j + 1;
      if (soko_map[i][j] == '\0')
	{
	  i = i + 1;
	  j = 0;
	}
    }
  return (nbr);
}

int	sokoban_start(char **av)
{
  char	**soko_map;
  int	x_nbr;
  int	i;

  i = 0;
  x_nbr = 0;
  soko_map = file_size(av, &i);
  x_nbr = find_x_nbr(soko_map);
  check_error(soko_map, x_nbr, 0, 0);
  start_window(soko_map, av, x_nbr, i);
  return (0);
}

int	main(int ac, char **av)
{
  if (ac == 1)
    prepare_menu();
  else if (ac == 2)
    {
      if (av[1][0] == '-' && av[1][1] == 'h')
	man_my_sokoban(av);
      else
	sokoban_start(av);
    }
  else
    {
      my_putstr("Syntax error: too much arguments\n");
      return (84);
    }
  return (0);
}

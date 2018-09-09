/*
** my_strdup.c for emacs in /home/Victor
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Wed Oct 12 08:33:58 2016 Victor Zhu
** Last update Fri Dec  9 12:42:34 2016 Victor Zhu
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  int	nbr;
  char	*str;

  nbr = my_strlen(src);
  str = malloc(nbr + 1);
  str = my_strcpy(str, src);
  return (str);
}

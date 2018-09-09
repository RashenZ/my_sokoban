/*
** my_strcpy.c for emacs in /home/Victor/CPool_Day06
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Mon Oct 10 09:20:48 2016 Victor Zhu
** Last update Fri Dec  9 13:41:17 2016 Victor Zhu
*/

#include "my.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

/*
** my_putchar.c for emacs in /home/Victor/CPool_Day07/lib/my
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Tue Oct 11 15:25:15 2016 Victor Zhu
** Last update Wed Oct 12 16:24:11 2016 Victor Zhu
*/

#include <unistd.h>
#include <stdlib.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

/*
** my_strcar.c for my_strcat in /home/rieux-_t/rendu/Piscine_C_J07/lib/my
** 
** Made by Thomas Rieux-Laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Wed Oct  8 22:37:48 2014 Thomas Rieux-Laucat
** Last update Sun Mar 15 17:50:37 2015 Thomas Rieux-Laucat
*/

#include <stdlib.h>
#include "include/minishell1.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int   j;
  char  *str;

  i = 0;
  j = 0;
  if ((str = malloc(sizeof(str) * (my_strlen(dest) + my_strlen(src) + 1)))
== NULL)
    exit(1);
  while (dest[i] != '\0')
    {
      str[i] = dest[i];
      i++;
    }
  str[i++] = '/';
  while (src[j] != '\0')
    str[i++] = src[j++];
  str[i] = '\0';
  return (str);
}

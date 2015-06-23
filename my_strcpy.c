/*
** my_strcpy.c for minishell2 in /home/rieux-_t/Projets/Module_Epitech/Unix/PSU_2014_minishell2
** 
** Made by Thomas Rieux-Laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Tue Mar  3 18:59:46 2015 Thomas Rieux-Laucat
** Last update Tue Mar  3 19:00:39 2015 Thomas Rieux-Laucat
*/

#include "include/minishell1.h"

char    *my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

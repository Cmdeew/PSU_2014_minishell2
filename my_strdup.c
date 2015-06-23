/*
** my_strdup.c for minishell1 in /home/rieux-_t/Documents/rendu/Unix/PSU_2014_minishell1
** 
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Tue Jan 27 15:19:58 2015 thomas rieux-laucat
** Last update Tue Jan 27 15:51:24 2015 thomas rieux-laucat
*/

#include <stdlib.h>
#include "include/minishell1.h"

char	*my_strdup(char *str)
{
  char	*new;
  int	i;
  int	j;

  i = 0;
  j = my_strlen(str);
  if ((new = malloc(sizeof(char *) * (j + 1))) == NULL)
    exit(1);
  while (str[i] != '\0')
    {
      new[i] = str[i];
      i++;
    }
  new[i] = '\0';
  return (new);
}

/*
** path.c for minishell1 in /home/rieux-_t/Documents/rendu/Unix/PSU_2014_minishell1
** 
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Tue Jan 27 16:21:10 2015 thomas rieux-laucat
** Last update Fri Jun  5 01:28:26 2015 Thomas-Rieux-Laucat
*/

#include <stdlib.h>
#include "include/minishell1.h"

char	**get_env(char **env)
{
  char	**new_env;
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (env[i])
    i++;
  if ((new_env = malloc(sizeof(char *) * (i))) == NULL)
    exit(1);
  while (j < (i - 1))
    {
      new_env[j] = my_strdup(env[j]);
      j++;
    }
  new_env[i - 1] = NULL;
  return (new_env);
}

char	**get_path(char **env)
{
  char	**path;
  char	carac;
  int	i;
  int	find;

  find = 0;
  carac = ':';
  i = 0;
  while (env[i])
    {
      if (env[i][0] == 'P' && env[i][1] == 'A' &&
	  env[i][2] == 'T' && env[i][3] == 'H' && env[i][4] == '=')
	{
	  path = str_to_word_tab((env[i] + 5), carac);
	  find = 1;
	}
      i++;
    }
  if (find == 0)
    return (NULL);
  return (path);
}

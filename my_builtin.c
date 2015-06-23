/*
** my_builtin.c for minishell1 in /home/rieux-_t/Documents/rendu/Unix/PSU_2014_minishell1
** 
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Wed Jan 28 15:01:26 2015 thomas rieux-laucat
** Last update Sun Feb  1 23:28:22 2015 thomas rieux-laucat
*/

#include <unistd.h>
#include <stdlib.h>
#include "include/minishell1.h"

int     my_cd(char *arg)
{
  int	ret;

  if ((ret = chdir(arg)) == -1)
    return (1);
  return (0);
}

int     my_setenv()
{
  my_putstr("setenv\n");
  return (0);
}

int     my_unsetenv()
{
  my_putstr("unsetenv\n");
  return (0);
}

int     my_env(char **env)
{
  show_tab(env);
  return (0);
}

int     my_exit(char **env, char **arg)
{
  free_my_tab(env);
  free_my_tab(arg);
  exit(EXIT_SUCCESS);
  return (0);
}

/*
** check_builtin.c for minishell1 in /home/rieux-_t/Documents/rendu/Unix/PSU_2014_minishell1
** 
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Tue Jan 27 17:02:57 2015 thomas rieux-laucat
** Last update Sat Mar 14 14:15:47 2015 Thomas Rieux-Laucat
*/

#include <stdlib.h>
#include "include/minishell1.h"

int	check_builtin(char **arg, char **env)
{
  if ((my_strcmp(arg[0], "cd")) == 0)
    my_cd(arg[1]);
  else if ((my_strcmp(arg[0], "setenv")) == 0)
    my_setenv();
  else if ((my_strcmp(arg[0], "unsetenv")) == 0)
    my_unsetenv();
  else if ((my_strcmp(arg[0], "env")) == 0)
    my_env(env);
  else if ((my_strcmp(arg[0], "exit")) == 0)
    my_exit(env, arg);
  else if ((arg[0][0] == '.' && arg[0][1] == '/'))
    my_exec(arg, env);
  else
    return (1);
  return (0);
}

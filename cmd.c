/*
** cmd.c for minishell1 in /home/rieux-_t/Documents/rendu/Unix/PSU_2014_minishell1
** 
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Wed Jan 21 18:00:23 2015 thomas rieux-laucat
** Last update Fri Mar 13 17:49:13 2015 Thomas Rieux-Laucat
*/

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "include/minishell1.h"

int	cmd(char **buff, char **env)
{
  if ((check_path(buff[0], buff, env)) == 1)
    {
      my_putstr("Command not found.\n");
      return (1);
    }
  return (0);
}

int	check_access(char *cmd, char **env)
{
  int	i;
  char	**path;

  i = 0;
  if ((path = get_path(env)) == NULL)
    {
      my_putstr("PATH not found.\n");
      return (1);
    }
  while (path[i])
    {
      if (access((my_strcat(path[i++], cmd)), F_OK || X_OK) == 0)
	return (0);
    }
  return (1);
}

int	check_path(char *cmd, char **argv, char **env)
{
  char	**path;
  pid_t	pid;
  int	i;

  i = 0;
  if ((check_access(cmd, env)) == 1)
    return (1);
  path = get_path(env);
  if ((pid = fork()) == -1)
    return (1);
  if (pid == -1)
    return (1);
  if (pid == 0)
    while (path[i])
      execve((my_strcat(path[i++], cmd)), argv, env);
  wait(&pid);
  return (0);
}

int	my_exec(char **arg, char **env)
{
  pid_t	pid;

  if ((pid = fork()) == -1)
    return (1);
  if (pid == -1)
    return (1);
  if (pid == 0)
    execve(arg[0], arg, env);
  wait(&pid);
  return (0);
}

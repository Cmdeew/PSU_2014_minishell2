/*
** pars.c for minishell2 in /home/rieux-_t/Projets/Module_Epitech/Unix/PSU_2014_minishell2
** 
** Made by Thomas Rieux-Laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Tue Mar  3 18:27:27 2015 Thomas Rieux-Laucat
** Last update Sun Mar 15 21:52:16 2015 Thomas Rieux-Laucat
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "include/minishell1.h"

char	**first_pars(char *buffer)
{
  char	**ftab;

  ftab = str_to_word_tab(buffer, ';');
  return (ftab);
}

int	redirection_fonc(char **arg, char **env)
{
  int	ret;
  int	fd;
  char	**myarg;

  if ((ret = open(arg[2], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR
| S_IRGRP | S_IWGRP | S_IWUSR)) == -1)
    {
      my_putstr("Error open....\n");
      exit(1);
    }
  fd = dup(1);
  dup2(ret, 1);
  myarg = str_to_word_tab(arg[0], ' ');
  if ((cmd(myarg, env)) == 1)
    return (1);
  close(ret);
  dup2(fd, 1);
  return (0);
}

int	redirection_double_fonc(char **arg, char **env)
{
  int	ret;
  int	fd;
  char	**myarg;

  if ((ret = open(arg[2], O_WRONLY | O_APPEND | O_CREAT, S_IRUSR
| S_IRGRP | S_IWGRP | S_IWUSR)) == -1)
    {
      my_putstr("Error open....\n");
      exit(1);
    }
  fd = dup(1);
  dup2(ret, 1);
  myarg = str_to_word_tab(arg[0], ' ');
  if ((cmd(myarg, env)) == 1)
    return (1);
  close(ret);
  dup2(fd, 1);
  return (0);
}

int	check_redirection(char *tab, char **env)
{
  int	i;
  char	**arg;

  i = 0;
  while (tab[i])
    {
      if (tab[i] == '>' && tab[i + 1] != '>')
	{
	  arg = str_to_word_tab(tab, ' ');
	  if ((redirection_fonc(arg, env)) == 1)
	    return (1);
	  return (0);
	}
      else if (tab[i] == '>' && tab[i + 1] == '>')
	{
	  arg = str_to_word_tab(tab, ' ');
	  if ((redirection_double_fonc(arg, env)) == 1)
	    return (1);
	  return (0);
	}
      i++;
    }
  return (1);
}

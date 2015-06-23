/*
** my_wait.c for minishell in /home/rieux-_t/Documents/rendu/Unix/PSU_2014_minishell1
** 
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Wed Jan 21 17:08:46 2015 thomas rieux-laucat
** Last update Tue Jun 23 18:16:46 2015 Thomas-Rieux-Laucat
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "include/minishell1.h"

# define BUFF_SIZE 4096

char	**delete_fck_space(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      tab[i] = supp_useless_space(tab[i]);
      i++;
    }
  return (tab);
}

int	why_im_stupid(char **ftab, char **env)
{
  char	**tab;
  int	i;

  i = 0;
  while (ftab[i])
    {
      if ((check_redirection(ftab[i], env) == 0))
	{
	  if (ftab[i + 1] != NULL)
	    i++;
	  else
	    return (0);
	}
      tab = str_to_word_tab(ftab[i], ' ');
      if ((check_builtin(tab, env)) == 1)
	if ((cmd(tab, env)) == 1)
	  return (0);
      i++;
    }
  return (0);
}
int	prompt(char **env)
{
  char	*buff;
  char	**ftab;
  int	a;

  if ((buff = malloc(sizeof(char*) * BUFF_SIZE)) == NULL)
    return (1);
  my_putstr("$>");
  if ((a = read(0, buff, BUFF_SIZE)) <= 0)
    return (1);
  buff[a - 1] = '\0';
  ftab = first_pars(buff);
  ftab = delete_fck_space(ftab);
  if ((why_im_stupid(ftab, env)) == 1)
    return (1);
  free(buff);
  return (0);
}

int	main(int argc, char **argv, char **env)
{
  char	**tab;
  char	**test;
  int	i;

  i = 0;
  if (argc != 1 && argv[0] == NULL)
    return (1);
  if (env == NULL || env[i] == NULL)
    {
      my_putstr("Environnement null.\n");
      return (1);
    }
  if ((test = get_path(env)) == NULL)
    {
      my_putstr("Env line 'PATH' is null\n");
      return (1);
    }
  tab = get_env(env);
  while (1)
    if ((prompt(tab)) == 1)
      return (1);
  return (0);
}

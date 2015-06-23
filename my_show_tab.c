/*
** my_show_tab.c for minishell1 in /home/rieux-_t/Documents/rendu/Unix/PSU_2014_minishell1
** 
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Sun Jan 25 21:00:30 2015 thomas rieux-laucat
** Last update Wed Jan 28 15:05:09 2015 thomas rieux-laucat
*/

#include <stdlib.h>
#include "include/minishell1.h"

int	free_my_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab);
  return (0);
}

void	show_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i++]);
      my_putchar('\n');
    }
}

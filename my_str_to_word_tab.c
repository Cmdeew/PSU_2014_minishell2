/*
** my_str_to_word_tab.c for minishell1 in /home/rieux-_t/Documents/rendu/Unix/PSU_2014_minishell1
** 
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Fri Jan 23 20:52:36 2015 thomas rieux-laucat
** Last update Sun Mar 15 17:57:43 2015 Thomas Rieux-Laucat
*/

#include <stdlib.h>
#include "include/minishell1.h"

int	count_word(char *str, char carac)
{
  int	i;
  int	nb;

  i = 0;
  nb = 1;
  while (str[i])
    {
      if (str[i] == carac && str[i + 1] != '\0')
	{
	  nb++;
	  while (str[i] == carac)
	    i++;
	}
      i++;
    }
  return (nb);
}

int	count_char(char *str, int start, char carac)
{
  int	i;

  i = 0;
  while (str[start] != carac && str[start] != '\0')
    {
      start++;
      i++;
    }
  return (i);
}

char	*supp_useless_space(char *str)
{
  int	i;
  int	j;
  char	*nstr;
  int	len;

  i = 0;
  j = 0;
  if (str[i] != ' ')
    return (str);
  else
    {
      while (str[i] == ' ')
	i++;
      len = (my_strlen(str) - i);
      if ((nstr = malloc(sizeof(char *) * len)) == NULL)
	exit(1);
      while (str[i] != '\0')
	  nstr[j++] = str[i++];
    }
  return (nstr);
}

char	**str_to_word_tab(char *str, char carac)
{
  char	**tab;
  int	i;
  int	j;
  int	c;
  int	k;

  c = 0;
  i = 0;
  k = count_word(str, carac);
  if ((tab = malloc(sizeof(char *) * (k + 1))) == NULL)
    exit(1);
  while (i < k)
    {
      if ((tab[i]=malloc(sizeof(char)*(count_char(str, c, carac) + 1)))==NULL)
	exit(1);
      j = 0;
      while (str[c] != carac && str[c])
	tab[i][j++] = str[c++];
      if (str[c] == carac)
	while (str[c] == carac)
	  c++;
       tab[i++][j] = '\0';
    }
  tab[k] = NULL;
  return (tab);
}

/*
** base_fonction.c for minishell in /home/rieux-_t/Documents/rendu/Unix/PSU_2014_minishell1
** 
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Wed Jan 21 17:24:38 2015 thomas rieux-laucat
** Last update Thu Feb  5 14:09:50 2015 Thomas Rieux-Laucat
*/

#include <stdlib.h>
#include <unistd.h>
#include "include/minishell1.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    {
      exit(1);
    }
  while (str[i])
    my_putchar(str[i++]);
}

void	my_putnbr(int nb)
{
  if (nb >= 10)
    my_putnbr(nb / 10);
  if (nb < 0)
    {
      my_putchar('-');
      my_putnbr(-nb);
    }
  else
    my_putchar((nb % 10) + '0');
}

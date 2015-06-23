/*
** my_strcmp.c for my_strcmp in /home/rieux-_t/rendu/Piscine_C_J07/lib/my
** 
** Made by Thomas Rieux-Laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Wed Oct  8 15:45:01 2014 Thomas Rieux-Laucat
** Last update Tue Nov  4 15:52:42 2014 thomas rieux-laucat
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0')
    i++;
  return (s1[i] - s2[i]);
}

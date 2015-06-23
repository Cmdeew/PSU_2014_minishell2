/*
** minishell1.h for minishell1 in /home/rieux-_t/Documents/rendu/Unix/PSU_2014_minishell1
** 
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Mon Jan 26 12:32:47 2015 thomas rieux-laucat
** Last update Wed Mar 11 18:10:27 2015 Thomas Rieux-Laucat
*/

#ifndef MINISHELL1_H_
# define MINISHELL1_H_

typedef struct	s_list
{
  char		*data;
  struct s_list	*next;
}		t_list;

/* Function(s) in file my_show_tab.c */
int	free_my_tab(char **);
void	show_tab(char **);

/* Function(s) in file my_wait.c */
int	prompt(char **);
int	main(int, char **, char **);

/* Function(s) in file my_str_to_word_tab.c */
int	count_word(char *, char);
int	count_char(char *, int, char);
char	**str_to_word_tab(char *, char);
char	*supp_useless_space(char *);

/* Function(s) in file cmd.c */
int	cmd(char **, char **);
int	check_path(char *, char **, char **);

/* Function(s) in file base_fonction.c */
void	my_putchar(char);
int	my_strlen(char *);
void	my_putstr(char *);
void	my_putnbr(int);
char	*my_strcat(char *, char *);

/* Function(s) in file my_strcmp.c */
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);
char	*my_strdup(char *);

char	**get_env(char **);
char	**get_path(char **);

int	check_builtin(char **, char **);
int	my_cd(char *);
int	my_setenv();
int	my_unsetenv();
int	my_env(char **);
int	my_exit(char **, char **);
int	my_exec(char **, char **);

/* Function(s) in file pars.c */
char	**first_pars(char *);
int	redirection_fonc(char **, char **);
int	check_redirection(char *, char **);

#endif /* !MINISHELL1_H_ */

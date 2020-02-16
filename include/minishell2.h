/*
** minishell2.h for minishell in /home/tatanouu/rendu/PSU_2015_minishell2
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Wed Apr  6 17:21:11 2016 Antoine Zaczyk
** Last update Tue May 17 20:45:08 2016 Antoine ZACZYK
*/

#ifndef		MINISHELL_2_

# define	MINISHELL_2_

void		do_minishell2(char *s, char **env, char **path);
void		my_multi_pipe(char *s, char **env, char **path);
void		my_redir_left(char **env, char **path, char *s);
void		my_double_right(char **env, char **path, char *s);
void		exec_pipe(char **path, char **env, char **tab);
int		check_my_pipe(char *str);
int		verif_pipe(char *str);
int		check_minishell2(char *str);
int		check_my_pipe(char *str);
int		redir_right_two(char **env, char **path, char *s);
int		my_redir_right(char **env, char **path, char *s);

#endif		/* !MINISHELL_2_ */

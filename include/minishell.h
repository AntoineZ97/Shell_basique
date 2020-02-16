/*
** basic.h for basic_function in /home/tatanouu/rendu/PSU/PSU_2015_minishell1
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Tue Jan 19 09:12:30 2016 Antoine Zaczyk
** Last update Tue May 17 20:44:58 2016 Antoine ZACZYK
*/

#ifndef		MINISHELL_H_

# define	MINISHELL_H

void		get_sigint(int sig);
void		check_ls(char *check, char *pwd, char **env);
void		exec_it(char **path, char **env, char **tab);
void		do_my_av(char **path, char **av, char **env, int c);
char		**do_env(char **tab, char **env);
char		**give_me_path(char **env);
int		check_pwd(char *check, char *pwd);
int		check_exit(char *check, char **new_env, char **path);
int		check_cd(char **tab, char **env);
int		go_home(char **env);
int		check_env(char **tab);
void		print_env(char **env);

#endif		/* !BASIC_ */

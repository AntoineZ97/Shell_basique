/*
** list.h for list.h in /home/tatanouu/rendu/PSU/PSU_2015_minishell1
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Thu Jan 21 17:20:07 2016 Antoine Zaczyk
** Last update Tue May 17 20:44:40 2016 Antoine ZACZYK
*/

#ifndef		CHECK_H_

# define	CHECK_H

int		check_pwd(char *check, char *pwd);
int		check_exit(char *check);
void		check_ls(char *check, char *pwd, char **my_env);
void		get_sigint(int sig);

#endif		/* !CHECK_H_ */

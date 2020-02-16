/*
** basic.h for basic in /home/tatanouu/rendu/PSU/PSU_2015_minishell1
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Thu Jan 21 17:38:33 2016 Antoine Zaczyk
** Last update Tue May 17 22:54:49 2016 Antoine ZACZYK
*/

#ifndef		BASIC_H_

# define	BASIC_H

void		my_putchar(char c);
void		my_putstr(char *str);
void		free_my_tab(char **tab);
void		my_free_all(char **tab1, char **tab2, char **tab3, int fd);
void		free_my_loop(char *s, char **tab, char **path);
void		control_d(char *s, char **path);
void		my_free(char *str);
void		check_not_found(char **path, int i);
void		check_segfault(int status);
char		**copy_env_no_exist(char **env, int i, char *str, char *str2);
char		**str_to_wordtab(char *str, char c);
char		**simple_str_to_wordtab(char *str);
char		*my_strcat(char *s1, char *s2);
char		**copy_my_env(char **env, int i, char *str, char *str2);
char		*clear_space(char *str);
char		**my_clear(char **tab);
char		*correct_str(char *str);
int		check_equal(char *str);
int		my_strlen(char *str);
int		my_getnbr(char *str);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, int n);
int		check_cd_av(char **av, char **env);
int		exec_bin(char **tab, char **env, char **path);

#endif		/* !BASIC_H */

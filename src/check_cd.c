/*
** check_cd.c for checkcd in /home/tatanouu/rendu/PSU/PSU_2015_minishell1
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Fri Jan 22 14:59:15 2016 Antoine Zaczyk
** Last update Tue May 17 19:51:17 2016 Antoine ZACZYK
*/

#include	<unistd.h>
#include	<basic.h>
#include	"minishell.h"

void		do_cd_moins(char **tab)
{
  static char	*pwd;

  if (tab)
    {
      if (tab[1] != NULL)
	{
	  if (my_strcmp(tab[1], "-") == 0)
	    {
	      if (pwd != NULL)
		if (chdir(pwd) == -1)
		  my_putstr("Cannot acces");
	    }
	  else
	    pwd = getcwd(pwd, 4096);
	}
      else
	pwd = getcwd(pwd, 4096);
    }
}

int		check_old(char *s1)
{
  if (s1[0] == 'O')
    if (s1[1] == 'L')
      if (s1[2] == 'D')
	if (s1[3] == 'P')
	  if (s1[4] == 'W')
	    return (1);
  return (0);
}

char		*find_old(char **env)
{
  int		i;

  i = 0;
  while (env[i])
    {
      if (check_old(env[i]) == 1)
	return (env[i] + 7);
      else
	i++;
    }
  return (NULL);
}

int		do_cd(char **tab, char **env)
{
  int		j;

  if (tab[1] == NULL)
    go_home(env);
  else if (tab[1][0] == '/')
    {
      j = chdir(tab[1]);
      if (j == -1)
	return (-1);
      return (0);
    }
  else
    {
      j = chdir(tab[1]);
      if (j == -1)
	return (1);
      return (0);
    }
  return (2);
}

int		check_cd(char **tab, char **env)
{
  if (tab[0] == NULL)
    return (0);
  if (my_strcmp(tab[0], "cd") == 0)
    {
      do_cd_moins(tab);
      do_cd(tab, env);
      return (1);
    }
  else if (my_strcmp(tab[0], "env") == 0)
    {
      print_env(env);
      return (1);
    }
  else
    return (0);
}

/*
** my_cd.c for cd in /home/tatanouu/rendu/PSU/PSU_2015_minishell1
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Fri Jan 22 17:55:31 2016 Antoine Zaczyk
** Last update Tue May 17 20:22:43 2016 Antoine ZACZYK
*/

#include	<unistd.h>
#include	<basic.h>

int		check_home(char *s1)
{
  if (s1[0] == 'H')
    if (s1[1] == 'O')
      if (s1[2] == 'M')
	if (s1[3] == 'E')
	  if (s1[4] == '=')
	    return (1);
  return (0);
}

char		*find_home(char **env)
{
  int		i;

  i = 0;
  while (env[i])
    {
      if (check_home(env[i]) == 1)
	return (env[i] + 5);
      else
	i++;
    }
  return (NULL);
}

int		go_home(char **env)
{
  char		*pwd;
  int		j;

  pwd = find_home(env);
  if (pwd != NULL)
    j = chdir(pwd);
  else
    my_putstr("Error cd\n");
  if (j == -1)
    return (-1);
  return (0);
}

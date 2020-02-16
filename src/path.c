/*
** env.c for get_env in /home/tatanouu/rendu/PSU/PSU_2015_minishell1
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Wed Jan 20 14:07:20 2016 Antoine Zaczyk
** Last update Tue May 17 19:37:18 2016 Antoine ZACZYK
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"basic.h"

int		check_path(char *s1)
{
  int		i;

  i = 0;
  while (s1[i])
    {
      if (s1[0] == 'P')
	if (s1[1] == 'A')
	  if (s1[2] == 'T')
	    if (s1[3] == 'H')
	      if (s1[4] == '=')
		return (1);
      i++;
    }
  return (0);
}

char		*find_path(char **env)
{
  int		i;

  i = 0;
  while (env[i])
    {
      if (check_path(env[i]) == 1)
	return (env[i] + 5);
      else
	i++;
    }
  return (NULL);
}

char		**give_me_path(char **env)
{
  char		*check;
  char		**path;

  check = find_path(env);
  if (check == NULL)
    return (NULL);
  path = str_to_wordtab(check, ':');
  if (path == NULL)
    return (NULL);
  return (path);
}

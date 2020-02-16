/*
** my_env.c for env in /home/tatanouu/minishell
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Tue Jan 19 10:53:16 2016 Antoine Zaczyk
** Last update Tue May 17 19:29:35 2016 Antoine ZACZYK
*/

#include	<stdlib.h>
#include	"basic.h"
#include	"minishell.h"

char		**my_unsetenv(char *str, char **env)
{
  int		i;

  i = 0;
  if (str[0] == '\0')
    return (env);
  while (env[i] != '\0')
    {
      if (my_strncmp(env[i], str, my_strlen(str)) == 0)
	{
	  while (env[i + 1] != NULL)
	    {
	      env[i] = env[i + 1];
	      i++;
	    }
	  env[i] = NULL;
	  return (env);
	}
      i++;
    }
  return (env);
}

char		**my_setenv(char **env, int i, char *str, char *str2)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  env = copy_env_no_exist(env, i, str, str2);
  if (env[i] == NULL)
    return (NULL);
  while (str[x] != '\0' && str[x] != '=')
    {
      env[i][x] = str[x];
      x++;
    }
  env[i][x] = '=';
  x++;
  while (str2[y] != '\0')
    {
      env[i][x] = str2[y];
      x++;
      y++;
    }
  env[i][x] = '\0';
  return (env);
}

char		**my_setenv_exist(char **env, int i, char *str, char *str2)
{
  int		x;
  int		y;

  env = copy_my_env(env, i, str, str2);
  y = 0;
  x = 0;
  while (str[x] != '\0' && str[x] != '=')
    {
      env[i][x] = str[x];
      x++;
    }
  env[i][x] = '=';
  x++;
  while (str2 && str2[y] != '\0')
    {
      env[i][x] = str2[y];
      x++;
      y++;
    }
  env[i][x] = '\0';
  return (env);
}

char		**check_setenv(char **tab, char **env)
{
  int		i;

  i = 0;
  while (env[i] != '\0')
    {
      if (tab[1])
	{
	  if (my_strncmp(env[i], tab[1], my_strlen(tab[1])) == 0)
	    {
	      env = my_setenv_exist(env, i, tab[1], tab[2]);
	      return (env);
	    }
	}
      i++;
    }
  if (check_equal(tab[1]) != 0)
    {
      if (tab[1] != NULL && tab[2] == NULL)
	env = my_setenv(env, i, tab[1], "\0");
      else if (tab[1] != NULL && tab[2] != NULL)
	env = my_setenv(env, i, tab[1], tab[2]);
    }
  return (env);
}

char		**do_env(char **tab, char **env)
{
  int		i;

  i = 0;
  while (my_strcmp(tab[i], "setenv") != 0
	 && my_strcmp(tab[i], "unsetenv") != 0)
    i++;
  if (my_strcmp(tab[i], "unsetenv") == 0 && tab[i + 1])
    env = my_unsetenv(tab[i + 1], env);
  else if (my_strcmp(tab[i], "setenv") == 0)
    env = check_setenv(tab, env);
  return (env);
}

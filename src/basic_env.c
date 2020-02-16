/*
** basic_function2.c for basicfunction2 in /home/tatanouu/rendu/PSU_2015_minishell2
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Wed Apr  6 16:42:17 2016 Antoine Zaczyk
** Last update Wed May 18 13:29:26 2016 Antoine ZACZYK
*/

#include	<stdlib.h>
#include	"basic.h"

char		**copy_my_env_end(char **env, char **tmp, int y)
{
  int		i;

  i = 0;
  while (env[y][i] != '\0')
    {
      tmp[y][i] = env[y][i];
      i++;
    }
  tmp[y][i] = '\0';
  return (tmp);
}

char		**copy_my_env(char **env, int i, char *str, char *str2)
{
  int		x;
  int		c;
  int		y;
  char		**tmp;

  c = (str2 ? my_strlen(str2) : 0);
  y = 0;
  x = 0;
  while (env[x] != NULL)
    x++;
  tmp = malloc(sizeof(char *) * (x + 1));
  while (y < x)
    {
      if (y == i)
	tmp[y] = malloc(sizeof(char) * (my_strlen(str) + c) + 2);
      else
	{
	  tmp[y] = malloc(sizeof(char) * (my_strlen(env[y]) + 1));
	  tmp = copy_my_env_end(env, tmp, y);
	}
      y++;
    }
  tmp[y] = NULL;
  free_my_tab(env);
  return (tmp);
}

char		**copy_env_no_exist(char **env, int i, char *str, char *str2)
{
  int		x;
  int		c;
  int		y;
  char		**tmp;

  c = (str2 ? my_strlen(str2) : 0);
  y = 0;
  x = 0;
  while (env[x] != NULL)
    x++;
  tmp = malloc(sizeof(char *) * (x + 2));
  while (y < (x + 1))
    {
      if (y == i)
	tmp[y] = malloc(sizeof(char) * (my_strlen(str) + c) + 2);
      else
	{
	  tmp[y] = malloc(sizeof(char) * (my_strlen(env[y]) + 1));
	  tmp = copy_my_env_end(env, tmp, y);
	}
      y++;
    }
  tmp[y] = NULL;
  free_my_tab(env);
  return (tmp);
}

void		print_env(char **env)
{
  int		i;

  i = 0;
  while (env[i] != NULL)
    {
      my_putstr(env[i]);
      my_putchar('\n');
      i++;
    }
}

int		check_equal(char *str)
{
  int		i;

  i = 0;
  while (str && str[i])
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	i++;
      else if (str[i] >= 'A' && str[i] <= 'Z')
	i++;
      else
	{
	  my_putstr("setenv: ");
	  my_putstr("Variable name must contain alphanumeric characters.\n");
	  return (0);
	}
    }
  if (!str)
    my_putstr("Command not found\n");
  return (1);
}

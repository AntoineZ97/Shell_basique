/*
** check_env.c for check_env in /home/tatanouu/rendu/PSU_2015_minishell2
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Thu Apr  7 10:46:40 2016 Antoine Zaczyk
** Last update Tue May 17 13:09:59 2016 Antoine ZACZYK
*/

#include	"basic.h"

int		check_env(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      if (my_strcmp(tab[i], "setenv") == 0)
	return (0);
      else if (my_strcmp(tab[i], "unsetenv") == 0)
	return (0);
      i++;
    }
  return (1);
}

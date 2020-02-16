/*
** check_av_cd.c for av on cd in /home/tatanouu/rendu/PSU/PSU_2015_minishell1
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Fri Jan 22 18:53:57 2016 Antoine Zaczyk
** Last update Thu Apr  7 15:13:21 2016 Antoine Zaczyk
*/

#include	<unistd.h>
#include	"minishell.h"

int		check_cd_av(char **av, char **env)
{
  if (av[0][0] == 'c' && av[0][1] == 'd')
    {
      check_cd(av, env);
      return (1);
    }
  return (0);
}

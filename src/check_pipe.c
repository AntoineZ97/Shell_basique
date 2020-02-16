/*
** check_pipe.c for check_pipe in /home/zaczyk_a/minishell/PSU_2015_minishell2
**
** Made by Antoine ZACZYK
** Login   <zaczyk_a@epitech.net>
**
** Started on  Tue May 17 13:10:28 2016 Antoine ZACZYK
** Last update Tue May 17 23:31:45 2016 Antoine ZACZYK
*/

#include	"basic.h"

int		check_my_pipe(char *str)
{
  int		i;
  int		p;

  p = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '|')
	p++;
      i++;
    }
  return (p);
}

int		verif_pipe(char *str)
{
  int		i;
  int		verif;

  i = 0;
  verif = 0;
  while (str[i] != '\0')
    {
      while (str[i]!= '\0'  && str[i] != '|')
	{
	  if (str[i] != ';' && str[i] != ' ' && str[i] != '\t' && str[i] != '>')
	    verif = 1;
	  i++;
	}
      if (verif != 1)
	{
	  my_putstr("Invalid null command\n");
	  return (0);
	}
      else
	verif = 0;
      if (str[i])
	i++;
    }
  return (1);
}

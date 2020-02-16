/*
** basics_other.c for basic_other in /home/zaczyk_a/minishell/PSU_2015_minishell2
**
** Made by Antoine ZACZYK
** Login   <zaczyk_a@epitech.net>
**
** Started on  Tue May 17 13:09:32 2016 Antoine ZACZYK
** Last update Tue May 17 23:36:15 2016 Antoine ZACZYK
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"basic.h"

void		get_sigint(int sig)
{
  sig = sig;
  my_putstr("\n$> ");
}

int		my_getnbr(char *str)
{
  int		count;
  int		s;
  int		nbr;

  s = 1;
  count = 0;
  while (str[count] != '\0' && (str[count] == '+' || str[count] == '-'))
    {
      if (str[count] == '-')
	{
	  s = s * -1;
	}
      count = count + 1;
    }
  str = str + count;
  nbr = 0;
  count = 0;
  while (str[count] >= '0' && str[count] <= '9')
    {
      nbr = nbr * 10;
      nbr = nbr - (str[count] - '0');
      count = count + 1;
    }
  return (nbr * s * -1);
}

void		control_d(char *s, char **path)
{
  if (path != NULL)
    free_my_tab(path);
  my_free(s);
  exit (0);
}

char		*correct_str(char *str)
{
  int		i;
  char		*new;
  int		max;
  int		a;

  max = my_strlen(str);
  a = 0;
  i = 0;
  while ((str[--max] == ' ' || str[max] == '|' || str[max] == '\t'
	  || str[max] == ';') && max > 0 && str && str[max]);
  if (max <= 0)
    return (str);
  max++;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  new = malloc(sizeof(char) * (max - i + 1));
  while (i != max && str[i])
    {
      new[a] = str[i];
      i++;
      a++;
    }
  new[a] = '\0';
  my_free(str);
  return (new);
}

void		check_not_found(char **path, int i)
{
  if (path == NULL && i == 0)
    my_putstr("Command not found\n");
}

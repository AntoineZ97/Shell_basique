/*
** check_minishell2.c for check_minishell in /home/tatanouu/rendu/PSU_2015_minishell2
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Wed Apr  6 12:35:58 2016 Antoine Zaczyk
** Last update Tue May 17 13:10:12 2016 Antoine ZACZYK
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	"minishell.h"
#include	"minishell2.h"
#include	"basic.h"

int		check_minishell2(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '<' || str[i] == '>' || str[i] == ';' || str[i] == '|')
	return (1);
      i++;
    }
  return (0);
}

void		do_minishell2(char *s, char **env, char **path)
{
  char		**tab;
  char		**check;
  int		i;

  if (path == NULL)
    return ;
  if ((i = check_my_pipe(s)) > 0 && verif_pipe(s) == 1)
    my_multi_pipe(s, env, path);
  if (i == 0 && verif_pipe(s) == 1)
    {
      tab = str_to_wordtab(s, ';');
      if (tab)
	{
	  while (tab[i])
	    {
	      check = simple_str_to_wordtab(tab[i]);
	      if (check_cd(check, env) == 0)
		exec_it(path, env, check);
	      free_my_tab(check);
	      i++;
	    }
	  free_my_tab(tab);
	}
    }
}

/*
** basic_free.c for basic_free in /home/zaczyk_a/minishell/PSU_2015_minishell2
**
** Made by Antoine ZACZYK
** Login   <zaczyk_a@epitech.net>
**
** Started on  Tue May 17 13:08:30 2016 Antoine ZACZYK
** Last update Tue May 17 13:08:32 2016 Antoine ZACZYK
*/

#include	<stdlib.h>
#include	"basic.h"

void		free_my_tab(char **tab)
{
  int		i;

  i = 0;
  if (tab)
    {
      while (tab[i] != NULL)
	{
	  my_free(tab[i]);
	  i++;
	}
      free(tab);
    }
  tab = NULL;
}

void		free_my_loop(char *s, char **tab, char **path)
{
  my_free(s);
  free_my_tab(tab);
  free_my_tab(path);
}

void		my_free(char *str)
{
  if (str)
    free(str);
}

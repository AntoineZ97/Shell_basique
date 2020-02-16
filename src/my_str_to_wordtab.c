/*
** my_str_to_wordtab.c for str_to_word_tab in /home/tatanouu/verif/PSU_2015_minishell2
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Fri Apr 15 15:23:56 2016 Antoine Zaczyk
** Last update Tue May 17 13:30:45 2016 Antoine ZACZYK
*/

#include	<stdlib.h>
#include	"basic.h"

int		strlen_word(char *str, char c)
{
  int		i;
  static int	pos = 0;

  i = 0;
  while (str && str[pos] != '\0')
    {
      if (str[pos] == c)
	while (str[pos] == c)
	  pos++;
      if (str[pos] != c)
	{
	  while (str[pos] != c && str[pos] != '\0')
	    {
	      i++;
	      pos++;
	    }
	  pos = (str[pos] == '\0' ? 0 : pos);
	  return (i);
	}
    }
  pos = (str[pos] == '\0' ? 0 : pos);
  return (-1);
}

int		count_word(char *str, char c)
{
  int		i;
  int		check;
  int		count;

  count = 0;
  i = 0;
  check = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	check = 0;
      else if (str[i] != c && check == 0)
	{
	  check = 1;
	  count++;
	}
      i++;
    }
  return (count);
}

char		**fill_my_tab(char cara, char **tab, char *str)
{
  int		i;
  int		l;
  int		c;

  c = 0;
  l = 0;
  i = -1;
  while (str[++i] != '\0')
    {
      if (str[i] != cara)
	{
	  while (str[i] != cara && str[i] != '\0')
	    {
	      tab[c][l] = str[i];
	      l++;
	      i++;
	    }
	  tab[c][l] = '\0';
	  c++;
	  l = 0;
	  if (str[i] == '\0')
	    return (tab);
	}
    }
  return (tab);
}

char		**str_to_wordtab(char *str, char c)
{
  int		i;
  int		j;
  char		**tab;

  j = 0;
  if (str != NULL)
    {
      i = count_word(str, c);
      if ((tab = malloc(sizeof(char *) * (i + 1))) == NULL)
	return (NULL);
      while (j < i)
	{
	  if ((tab[j] = malloc(sizeof(char) * strlen_word(str, c) + 1)) == NULL)
	    return (NULL);
	  j++;
	}
      tab = fill_my_tab(c, tab, str);
      tab[i] = NULL;
      return (tab);
    }
  return (NULL);
}

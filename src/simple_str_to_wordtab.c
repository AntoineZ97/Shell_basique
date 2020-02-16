/*
** my_str_to_wordtab.c for str_to_word_tab in /home/tatanouu/verif/PSU_2015_minishell2
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Fri Apr 15 15:23:56 2016 Antoine Zaczyk
** Last update Tue May 17 13:30:59 2016 Antoine ZACZYK
*/

#include	<stdlib.h>
#include	"basic.h"

int		simple_strlen_word(char *str)
{
  int		i;
  static int	pos = 0;

  i = 0;
  while (str && str[pos] != '\0')
    {
      if (str[pos] == ' ' || str[pos] == '\t')
	while (str[pos] == ' ' || str[pos] == '\t')
	  pos++;
      if (str[pos] != '\t' && str[pos] != ' ')
	{
	  while (str[pos] != '\t' && str[pos] != ' ' && str[pos] != '\0')
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

int		simple_count_word(char *str)
{
  int		i;
  int		check;
  int		count;

  count = 0;
  i = 0;
  check = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\t' || str[i] == ' ')
	check = 0;
      else if ((str[i] != ' ' || str[i] == '\t') && check == 0)
	{
	  check = 1;
	  count++;
	}
      i++;
    }
  return (count);
}

char		**simple_fill_my_tab(char **tab, char *str)
{
  int		i;
  int		l;
  int		c;

  c = 0;
  l = 0;
  i = -1;
  while (str[++i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t')
	{
	  while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
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

char		*correct_my_str(char *str)
{
  int		max;
  int		i;

  max = my_strlen(str);
  max--;
  i = max;
  while (str[max] == ' ' || str[max] == '\t')
    max--;
  if (i != max)
    str[max + 1] = '\0';
  return (str);
}

char		**simple_str_to_wordtab(char *str)
{
  int		i;
  int		j;
  int		e;
  char		**tab;

  j = 0;
  if (str)
    {
      str = correct_my_str(str);
      i = simple_count_word(str);
      if ((tab = malloc(sizeof(char *) * (i + 1))) == NULL)
	return (NULL);
      while (j < i)
	{
	  e = (simple_strlen_word(str) + 1);
	  if ((tab[j] = malloc(sizeof(char) * e)) == NULL)
	    return (NULL);
	  j++;
	}
      tab = simple_fill_my_tab(tab, str);
      tab[i] = NULL;
    }
  return (tab);
}

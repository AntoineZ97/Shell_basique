/*
** basic_function.c for basic in /home/zaczyk_a/rendu/marvin_huguet_t
**
** Made by Antoine ZACZYK
** Login   <zaczyk_a@epitech.net>
**
** Started on  Sat May 14 19:45:04 2016 Antoine ZACZYK
** Last update Tue May 17 13:08:57 2016 Antoine ZACZYK
*/

#include	<stdlib.h>

int		my_strncmp(char *s1, char *s2, int n)
{
  int		i;

  i = 0;
  if (!s2)
    return (-1);
  while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
    i++;
  if ((s1[i] == '\0' && s2[i] == '\0') || i == n)
    return (0);
  else if (s1[i] > s2[i])
    return (1);
  else
    return (-1);
}

int		my_strcmp(char *s1, char *s2)
{
  int		a;

  a = 0;
  if (s1[a] == '\0')
    return (-1);
  if (s2[a] == 0)
    return (-1);
  while (*s1 != '\0' && *s2 != '\0')
    {
      if (*s1++ == *s2++)
	a = 1;
      else
	return (-1);
    }
  return (0);
}

char		*my_strcat_end(char *s1, char *s2, char *dest)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (s1[i])
    {
      dest[i] = s1[i];
      i++;
    }
  if (dest[i - 1] != '/')
    dest[i++] = '/';
  while (s2[j])
    {
      dest[i + j] = s2[j];
      j++;
    }
  dest[i + j] = '\0';
  return (dest);
}

char		*my_strcat(char *s1, char *s2)
{
  char		*dest;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (s1 == NULL || s2 == NULL)
    return (NULL);
  while (s1[i] != '\0')
    i++;
  while (s2[j] != '\0')
    j++;
  if ((dest = malloc(sizeof(char) * (i + j + 2))) == NULL)
    return (NULL);
  dest = my_strcat_end(s1, s2, dest);
  return (dest);
}

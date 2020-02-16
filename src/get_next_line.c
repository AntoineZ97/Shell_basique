/*
** get_next_line.c for get_next_line in /home/tatanouu/rendu/CPE/CPE_2015_getnextline
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Fri Jan  8 16:49:03 2016 Antoine Zaczyk
** Last update Tue May 17 13:30:13 2016 Antoine ZACZYK
*/

#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<sys/stat.h>
#include	 <fcntl.h>
#include	"get_next_line.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char		*my_malloc(char *line, int size)
{
  int		i;
  char		*tmp;

  i = 0;
  tmp = malloc(sizeof(char) * ((my_strlen(line) + size + 1)));
  if (tmp == NULL)
    {
      if (line)
	free(line);
      return (NULL);
    }
  while (line[i] != '\0')
    {
      tmp[i] = line[i];
      if (line)
	i++;
    }
  tmp[i] = '\0';
  free(line);
  return (tmp);
}

char		find_c(const int fd, char c)
{
  static char	buffer[READ_SIZE];
  static int	rd = 0;
  static int	i = 0;

  if (fd == -1 || READ_SIZE == 0)
    return ('\0');
  if (rd == 0)
    {
      i = 0;
      while (i < READ_SIZE)
	buffer[i++] = 0;
      i = 0;
      rd = read(fd, buffer, READ_SIZE);
      if (rd <= 0)
	return ('\0');
      buffer[rd] = '\0';
    }
  c = buffer[i];
  rd--;
  i++;
  return (c);
}

char		*get_next_line(const int fd)
{
  char		c;
  char		*line;
  int		i;

  c = 0;
  i = 0;
  if ((line = malloc(sizeof(char) * READ_SIZE + 1)) == NULL)
    return (NULL);
  line[READ_SIZE] = '\0';
  c = find_c(fd, c);
  if (c == '\0')
    {
      free(line);
      return (NULL);
    }
  while (c != '\0' && c != '\n')
    {
      if (i % READ_SIZE == 0 && i != 0)
	line = my_malloc(line, READ_SIZE);
      line[i] = c;
      i++;
      c = find_c(fd, c);
    }
  line[i] = '\0';
  return (line);
}

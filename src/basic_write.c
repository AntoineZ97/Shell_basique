/*
** basic_write.c for basic_write in /home/zaczyk_a/minishell/PSU_2015_minishell2
**
** Made by
** Login   <zaczyk_a@epitech.net>
**
** Started on  Fri May 13 18:04:14 2016
** Last update Fri May 13 18:54:28 2016 
*/

#include	<unistd.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

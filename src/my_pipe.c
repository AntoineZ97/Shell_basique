/*
** my_pipe.c for my_pipe in /home/tatanouu/rendu/PSU_2015_minishell2
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Tue Apr 12 14:15:26 2016 Antoine Zaczyk
** Last update Tue May 17 23:24:37 2016 Antoine ZACZYK
*/

#include	<unistd.h>
#include	<wait.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	"basic.h"
#include	"minishell.h"
#include	"minishell2.h"

int		*create_pipe(int p, int *pipefd)
{
  int		i;

  i = 0;
  if ((pipefd = malloc(sizeof(int) * (p * 2))) == NULL)
    return (0);
  while (i < p)
    {
      pipe((pipefd + (i * 2)));
      i++;
    }
  return (pipefd);
}

void		my_close(int p, int *pipefd)
{
  int		i;

  i = 0;
  while (i < (2 * p))
    {
      if (close(pipefd[i]) < 0)
	my_putstr("Error on closing pipe\n");
      i++;
    }
}

void		final_pipe(int p, int *pipefd)
{
  int		i;
  int		status;

  i = 0;
  my_close(p, pipefd);
  while (i <= (p * 2))
    {
      wait(&status);
      i++;
    }
  free(pipefd);
}

void		my_do_pipe(int p, char **tab, char **env, char **path)
{
  int		i;
  int		*pipefd;
  pid_t		pid;
  char		**tmp;

  i = -1;
  pipefd = 0;
  pipefd = create_pipe(p, pipefd);
  while (tab[++i] && pipefd != 0)
    {
      if ((pid = fork()) == -1)
	return ;
      if (pid == 0)
	{
	  if (i < p)
	    dup2(pipefd[(i * 2) + 1], 1);
	  if (i > 0)
	    dup2(pipefd[(i * 2) - 2], 0);
	  my_close(p, pipefd);
	  exec_it(path, env, (tmp = simple_str_to_wordtab(tab[i])));
	  free_my_tab(tmp);
	  exit(1);
	}
    }
  final_pipe(p, pipefd);
}

void		my_multi_pipe(char *s, char **env, char **path)
{
  char		**tab;
  int		p;

  p = check_my_pipe(s);
  tab = str_to_wordtab(s, '|');
  my_do_pipe(p, tab, env, path);
  free_my_tab(tab);
}

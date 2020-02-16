/*
** check.c for check in /home/tatanouu/rendu/PSU/PSU_2015_minishell1
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Thu Jan 21 17:24:36 2016 Antoine Zaczyk
** Last update Tue May 17 23:23:40 2016 Antoine ZACZYK
*/

#include	<stdlib.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	<signal.h>
#include	"basic.h"

void		check_exit2(int nb, char *s, char **new_env, char **path)
{
  free_my_tab(new_env);
  free_my_tab(path);
  my_free(s);
  exit(nb);
}

int		check_exit(char *check, char **new_env, char **path)
{
  int		i;
  int		ex;
  char		**check_exit;

  ex = 0;
  check_exit = simple_str_to_wordtab(check);
  if (check_exit && check_exit[0] && check_exit[1])
    ex = my_getnbr(check_exit[1]);
  i = 0;
  free_my_tab(check_exit);
  if (check == NULL)
    return (0);
  while (check[i] != '\0')
    {
      if (check[i] == ' ' || check[i] == '\t')
	i = i;
      else if (check[i] == 'e' && check[i + 1] == 'x'
	       && check[i + 2] == 'i' && check[i + 3] == 't')
	{
	  if (check[i + 4] == ' ' || check[i + 4] == '\0')
	    check_exit2(ex, check, new_env, path);
	}
      i++;
    }
  return (1);
}

int		check_cmd(char **tab, char **env)
{
  pid_t		childID;
  int		status;

  if (tab != NULL)
    {
      if (access(tab[0], F_OK) == 0)
	{
	  if ((childID = fork()) == 0)
	    execve(tab[0], tab, env);
	  else
	    waitpid(-1, &status, 0);
	  check_segfault(status);
	  return (1);
	}
      if (tab[0][0] == '.' || tab[0][0] == '/')
	{
	  my_putstr("Command not found.\n");
	  return (1);
	}
      return (0);
    }
  return (0);
}

void		exec_it(char **path, char **env, char **tab)
{
  int		i;
  pid_t		childID;
  char		*com;
  int		status;

  i = 0;
  if (( i = check_cmd(tab, env)) == 0 && path != NULL
      && tab && exec_bin(tab, env, path) == 0)
    {
      com = my_strcat(path[i], tab[0]);
      while (com != NULL && access(com, F_OK) != 0 && path[i] != NULL)
	{
	  i++;
	  my_free(com);
	  com = my_strcat(path[i], tab[0]);
	}
      if (com == NULL && path[i] == NULL)
	my_putstr("Comand not found.\n");
      else
	if ((childID = fork()) == 0)
	  execve(com, tab, env);
      waitpid(-1, &status, 0);
      my_free(com);
    }
  check_not_found(path, i);
}

void		exec_pipe(char **path, char **env, char **tab)
{
  int		i;
  char		*com;

  i = 0;
  if (path == NULL)
    return ;
  if (tab && exec_bin(tab, env, path) == 0)
    {
      com = my_strcat(path[i], tab[0]);
      while (com != NULL && access(com, F_OK) != 0 && path[i] != NULL)
	{

	  i++;
	  my_free(com);
	  com = my_strcat(path[i], tab[0]);
	}
    }
  if (com == NULL && path[i] == NULL)
    my_putstr("Comand not found.\n");
  if (com != NULL)
    {
      execve(com, tab, env);
      free(com);
    }
}

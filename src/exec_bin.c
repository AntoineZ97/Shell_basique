/*
** exec_bin.c for exec_bin in /home/tatanouu/rendu/PSU/PSU_2015_minishell1
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Fri Jan 22 15:16:46 2016 Antoine Zaczyk
** Last update Tue May 17 13:10:37 2016 Antoine ZACZYK
*/

#include	<stdlib.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	<signal.h>
#include	"basic.h"

char		*check_acces(char **path, char **tab)
{
  char		*com;
  int		i;

  i = 0;
  com = NULL;
  if (!(com = my_strcat(path[i], tab[0])))
    return (NULL);
  while (com != NULL && access(com, F_OK) != 0 && path[i] != NULL)
    {
      free(com);
      i++;
      if ((com = my_strcat(path[i], tab[0])) == NULL)
	return (NULL);
    }
  return (com);
}

char		*check_acces_path(char **path, char **tab)
{
  char		*com;
  int		i;

  i = 0;
  if (!(com = my_strcat(path[i], tab[0])))
    return (NULL);
  while (com != NULL && access(com, F_OK) != 0 && path[i] != NULL)
    {
      free(com);
      i++;
      com = my_strcat(path[i], tab[0]);
    }
  return (path[i]);
}

void		check_segfault(int status)
{
  if (WIFSIGNALED(status) == 1)
    if (WTERMSIG(status) == 11)
      my_putstr("Segmentation Fault\n");
}

int		exec_bin(char **tab, char **env, char **path)
{
  int		childID;
  char		*com;
  int		status;
  int		i;
  char		*path2;

  i = 0;
  if (tab[0] != '\0' && (tab[0][0] == '.' || tab[0][0] == '/'))
    {
      com = check_acces(path, tab);
      path2 = check_acces_path(path, tab);
      if ((com ? access(com, F_OK) : -1) == 0 && path2 != NULL)
	return (0);
      else
	{
	  i = (childID = fork() == 0 ? execve(tab[0], tab, env) : i);
	  if (i == -1)
	    exit (0);
	  else
	    waitpid(-1, &status, 0);
	  check_segfault(status);
	}
    }
  return ((tab[0][0] == '.' || tab[0][0] == '/') ? -1 : 0);
}

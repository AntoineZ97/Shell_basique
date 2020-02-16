/*
** main.c for main in /home/tatanouu/rendu/PSU/PSU_2015_minishell1
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Mon Jan 18 15:01:14 2016 Antoine Zaczyk
** Last update Tue May 17 13:30:19 2016 Antoine ZACZYK
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<signal.h>
#include	<unistd.h>
#include	"get_next_line.h"
#include	"basic.h"
#include	"minishell.h"
#include	"minishell2.h"

char		**copy_env(char **env, char **tmp, int j)
{
  int		i;

  i = 0;
  while (env[j][i] != '\0')
    {
      tmp[j][i] = env[j][i];
      i++;
    }
  tmp[j][i] = '\0';
  return (tmp);
}

char		**check_av_env(int ac, char **av, char **env)
{
  int		i;
  char		**tmp;
  int		j;

  j = 0;
  i = 0;
  ac = ac;
  av = av;
  if (!env)
    return (NULL);
  while (env[i] != NULL)
    i++;
  tmp = malloc(sizeof(char *) * (i + 1));
  while (j < i)
    {
      tmp[j] = malloc(sizeof(char) * (my_strlen(env[j]) + 1));
      tmp = copy_env(env, tmp, j);
      j++;
    }
  tmp[j] = NULL;
  return (tmp);
}

int		main(int ac, char **av, char **env)
{
  char		*s;
  char		**new_env;
  char		**path;
  char		**tab;

  new_env = check_av_env(ac, av, env);
  while (42)
    {
      my_putstr(isatty(1) == 1 ? "$> " : "");
      path = give_me_path(new_env);
      signal(SIGINT, SIG_IGN);
      if ((s = get_next_line(0)) == NULL)
	control_d(s, path);
      s = correct_str(s);
      signal(SIGINT, get_sigint);
      check_exit(s, new_env, path);
      tab = simple_str_to_wordtab(s);
      if (check_minishell2(s) != 0)
	do_minishell2(s, new_env, path);
      else if (check_env(tab) == 0)
	new_env = do_env(tab, new_env);
      else if (my_strlen(s) != 0 && check_cd(tab, new_env) == 0)
	exec_it(path, new_env, tab);
      free_my_loop(s, tab, path);
    }
}

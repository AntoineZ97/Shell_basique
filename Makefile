##
## Makefile for makefile in /home/tatanouu/verif/PSU_2015_minishell2
## 
## Made by Antoine Zaczyk
## Login   <tatanouu@epitech.net>
## 
## Started on  Thu Apr 21 12:31:30 2016 Antoine Zaczyk
## Last update Tue May 17 23:37:53 2016 Antoine ZACZYK
##

NAME    =               mysh

SRC     =		 src/get_next_line.c             \
			 src/basic_env.c                 \
			 src/basic_free.c                \
			 src/basic_write.c               \
			 src/basics_other.c		 \
			 src/basic_function.c		 \
			 src/my_str_to_wordtab.c         \
			 src/simple_str_to_wordtab.c	 \
			 src/check_env.c                 \
			 src/check_exit_and_exec.c       \
			 src/check_pipe.c	         \
			 src/my_pipe.c                   \
			 src/check_cd.c                  \
			 src/check_av_cd.c               \
			 src/my_cd.c                     \
			 src/exec_bin.c                  \
			 src/path.c                      \
			 src/check_minishell2.c          \
			 src/my_env.c                    \
			 src/main.c


INC     =               -Iinclude/

OBJ     =               $(SRC:.c=.o)

CFLAGS  =               -W -Wall -ansi -pedantic -Iinclude/

RM      =               rm -f

ECHO    =               echo -e

DEBUG   =               -ggdb3

$(NAME):		$(OBJ)
			gcc $(CFLAGS) -o $(NAME) $(OBJ)
			@$(ECHO) '[0;32m> Compiled[0m'

clean:
			-@$(RM) $(OBJ)
			-@$(RM) *~
			-@$(RM) #*#
			@$(ECHO) '[0;35m> Directory cleaned[0m'

all:			$(NAME)

fclean:			clean
			@$(RM) $(NAME)
			@$(ECHO) '[0;35m> Remove executable[0m'
re:			fclean all

.PHONY:			all clean re

debug:			$(OBJ)
			gcc $(INC) $(DEBUG) $(CFLAGS) -o $(NAME) $(OBJ)
			@$(ECHO) '[0;32m> Mode Debug: done[0m'
			@$(ECHO) 'gdb -tui' $(NAME)

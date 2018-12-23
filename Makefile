# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 11:59:13 by otimofie          #+#    #+#              #
#    Updated: 2018/12/22 15:44:48 by otimofie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

CORE		= main.c \
			cd.c \
			cd_2.c \
			env.c \
			env_infrastructure.c \
			signal.c \
			fork_execve_module.c \
			fork_execve_module_2.c \
			echo.c \
			echo_2.c \
			exit.c \
			setenv.c \
			unsetenv.c \
			special_char.c \
			special_char_fork.c \
			tilda_fork.c \

			
SRCS        = $(addprefix srcs/, $(CORE))

CFLAGS		= -Wall -Wextra -Werror
OBJECTS 	= $(SRCS:.c=.o)
LIB			= ./libft.a
INC			= ./includes/minishell.h

#colors
RESET		= \033[m
RED         = \033[1;31m
GREEN       = \033[01;38;05;46m
YELLOW      = \033[01;38;05;226m
BLUE        = \033[03;38;05;21m
VIOLET      = \033[01;38;05;201m
CYAN        = \033[1;36m
WHITE       = \033[01;38;05;15m

all: $(NAME)

$(NAME): $(LIB) $(OBJECTS) $(INC)
	@ gcc $(CFLAGS) -I $(INC) $(SRCS) -L ./libft -lft -o $(NAME)
	@ echo  "$(YELLOW) : OK$(RESET)"

$(LIB):
	@ echo  "$(GREEN)Compiling: $(WHITE)libft$(RESET)$(YELLOW) : $(RESET)\c)"
	@ make -C ./libft
	@ echo  "$(GREEN)Compiling: $(WHITE)$(NAME)$(RESET)$(YELLOW) : $(RESET)\c)"

$(OBJECTS): %.o: %.c
	@ gcc -c $(CFLAGS) $< -o $@
	@ echo  "$(YELLOW)█$(RESET)\c)"

clean:
	@ make -C ./libft clean
	@ rm -f $(OBJECTS)

fclean: clean
	@ make -C ./libft fclean
	@ rm -f $(NAME) $(LIB)

re: fclean all

.PHONY: all clean fclean re

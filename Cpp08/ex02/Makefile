# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 11:02:57 by amorcill          #+#    #+#              #
#    Updated: 2022/07/07 15:04:39 by amorcill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	mutated
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

OBJS	= 	$(patsubst %.c, %.o, $(SRCS))
SRCS	=	main.cpp \


all:		$(NAME)
# Linking
$(NAME):	$(OBJS)
			@echo "\033[1;32m$(NAME)\033[1;0m\033[32m linking...\033[0m"
			@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
			@echo "\033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

# Compiling
%.o:		%.c
			@echo "\033[1;32m$(NAME)\033[1;0m\033[32m compiling...\033[0m"
			@$(CC) $(FLAGS) -c $< -o $@

clean:
			@rm -rf *.o
			@echo "\033[31m Objects Files\033[1;31m\033[1;0m\033[31m removed.\033[0m"

fclean: 	clean
			@rm -rf *.out
			@rm -rf *.replace
			@rm -f $(NAME)
			@echo "\033[1;31m $(NAME)\033[1;0m\033[31m removed.\033[0m"

re: 		fclean $(NAME)

val:
			valgrind --leak-check=full -s ./$(NAME)

leaks:
			leaks --atExit -- ./$(NAME)
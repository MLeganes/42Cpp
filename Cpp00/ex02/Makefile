# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 11:49:03 by amorcill          #+#    #+#              #
#    Updated: 2022/04/08 17:18:32 by amorcill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	account
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

OBJS	= 	$(patsubst %.cpp, %.o, $(SRCS))
SRCS	=	Account.cpp tests.cpp

all:		$(NAME)
# Linking
$(NAME):	$(OBJS)
			@echo "\033[1;32m$(NAME)\033[1;0m\033[32m linking...\033[0m"
			@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
			@echo "\033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

# Compiling
%.o:		%.cpp
			@echo "\033[1;32m$(NAME)\033[1;0m\033[32m compiling...\033[0m"
			@$(CC) $(FLAGS) -c $< -o $@

clean:
			@rm -rf *.o
			@echo "\033[31m Objects Files\033[1;31m\033[1;0m\033[31m removed.\033[0m"

fclean: 	clean
			@rm -rf *.out
			@rm -f $(NAME)
			@echo "\033[1;31m $(NAME)\033[1;0m\033[31m removed.\033[0m"

re: 		fclean $(NAME)

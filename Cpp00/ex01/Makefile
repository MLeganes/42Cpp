# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 11:49:03 by amorcill          #+#    #+#              #
#    Updated: 2022/03/28 15:50:05 by amorcill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

OBJS	= 	$(patsubst %.c, %.o, $(SRCS))
SRCS	=	phonebook.cpp

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
			@rm -rf $(O)
			@rm -rf $(NAME)
			@echo "\033[31mObjects Files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31mremoved.\033[0m"

fclean: 	clean
			@rm -f $(NAME)
			@echo "\033[1;31m$(NAME)\033[1;0m\033[31m Removed.\033[0m"

re: 		fclean $(NAME)
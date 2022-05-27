# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 11:49:03 by amorcill          #+#    #+#              #
#    Updated: 2022/05/25 21:55:16 by amorcill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	zombie
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

OBJS	= 	$(patsubst %.c, %.o, $(SRCS))
SRCS	=	main.cpp \
			zombieHorde.cpp \
			Zombie.cpp \

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
			@rm -f $(NAME)
			@echo "\033[1;31m $(NAME)\033[1;0m\033[31m removed.\033[0m"

re: 		fclean $(NAME)

test:		$(NAME)
			./megaphone "shhhhh... I think the students are asleep..."
			./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
			./megaphone
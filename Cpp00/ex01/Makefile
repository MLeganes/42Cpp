# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 11:49:03 by amorcill          #+#    #+#              #
#    Updated: 2022/04/05 19:05:21 by amorcill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

S		=	src/
O		=	obj/

OBJS	= 	$(patsubst $S%.c, $O%.o, $(SRCS))
SRCS	=	$Smain.cpp \
			$Snumber.cpp \
			$SContact.class.cpp \
			$SPhonebook.class.cpp \

INC		=	-I ./inc

all:		$(NAME)
# Linking
$(NAME):	$(OBJS)
			@echo "\033[1;32m$(NAME)\033[1;0m\033[32m linking...\033[0m"
			@$(CC) $(FLAGS) $(OBJS) -o $(NAME) 
			@echo "\033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

# Compiling
$O%.o:		$S%.c
			@[ -d $(O) ]	|| mkdir -p $(O)
			@echo "\033[1;32m$(NAME)\033[1;0m\033[32m compiling...\033[0m"
			@$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
			@rm -rf $(O)
			@rm -rf $(NAME)
			@echo "\033[31mObjects Files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31mremoved.\033[0m"

fclean: 	clean
			@rm -f $(NAME)
			@echo "\033[1;31m$(NAME)\033[1;0m\033[31m Removed.\033[0m"

re: 		fclean $(NAME)

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/10 18:40:58 by clouden           #+#    #+#              #
#    Updated: 2025/12/10 19:48:53 by clouden          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED		=	\033[0;31m
GREEN   =	\033[0;32m
RESET   =	\033[0m  
YELLOW  =	\033[1;33m
BLUE    =	\033[0;34m

# Project Variables
CC		= 	cc
CFLAGS 	= 	-Wall -Wextra -Werror -g3
NAME	=	philo

SRCS	= 	main.c \
			utils.c \

OBJS	= $(SRCS:%.c=%.o)

all:$(NAME)

$(NAME):$(OBJS)
	@echo "(BLUE)[PHILO]$(RESET) $< -> $@"
	@$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	@printf "$(BLUE)[COMPILING]$(RESET) %021s -> %s\n" $< $@
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)"
	@echo "+---------------------------+"
	@echo "|      CLEANING OBJECTS     |"
	@echo "+---------------------------+"
	@rm -rf *.o $(OBJS)

fclean: clean
	@echo "$(YELLOW)"
	@echo "+---------------------------+"
	@echo "|   REMOVING EXECUTABLES    |"
	@echo "+---------------------------+"
	@rm -f $(NAME)
	@echo "$(RESET)"
	@echo "...now THAT'S effin' clean!\n"

re: fclean all

.PHONY: re all clean fclean


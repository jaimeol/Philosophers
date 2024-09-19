# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 18:02:03 by jolivare          #+#    #+#              #
#    Updated: 2024/09/19 10:54:35 by jolivare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SOURCES = src/main.c src/actions.c src/args.c src/dead.c src/create_threads.c src/routine.c  src/clean.c\
			utils/ft_atoi.c utils/print_action.c utils/time.c utils/parse.c

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3
REMOVE = rm -f
CC = cc

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(NAME)

clean:
	$(REMOVE) $(OBJECTS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

c: all clean

.PHONY: all clean fclean re
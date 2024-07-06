# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 18:02:03 by jolivare          #+#    #+#              #
#    Updated: 2024/07/06 12:39:05 by jolivare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

SOURCES = src/main.c src/actions.c src/args.c src/dead.c src/create_threads.c src/routine.c \
			utils/ft_atoi.c utils/print_action.c utils/time.c

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -f
CC = cc

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(NAME)

clean:
	$(REMOVE) $(OBJECTS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all


.PHONY: all clean fclean re
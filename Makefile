# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 18:02:03 by jolivare          #+#    #+#              #
#    Updated: 2024/05/16 18:21:02 by jolivare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

SOURCES = src/main.c

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
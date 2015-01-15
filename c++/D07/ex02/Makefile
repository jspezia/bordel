# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/14 18:10:52 by jspezia           #+#    #+#              #
#    Updated: 2015/01/14 18:10:55 by jspezia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	array
SRCS =	main.cpp

CPPFLAGS = -Wall -Wextra -Werror
RM = rm -f

all:
	@g++ $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


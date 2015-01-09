# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fyadaba <fyadaba@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 12:20:30 by fyadaba           #+#    #+#              #
#    Updated: 2015/01/05 12:25:59 by fyadaba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	winnerSed
SRCS =	main.cpp				\

CPPFLAGS = -Wall -Wextra -Werror
RM = rm -f

all:
	@g++ $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:
	@$(RM) *.replace

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


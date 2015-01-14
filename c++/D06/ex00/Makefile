# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/13 18:11:00 by jspezia           #+#    #+#              #
#    Updated: 2015/01/13 23:57:29 by jspezia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPATH	= src
OPATH	= obj
HPATH	= includes

CC		= g++ $(FLAGS)
FLAGS	= -Wall -Werror -Wextra -g

NAME	= exec

SRC		= main.cpp \
		  Scalar.cpp

CFILE	= $(patsubst %,$(CPATH)/%, $(SRC))
OFILE	= $(patsubst %.cpp,$(OPATH)/%.o, $(SRC))

# COLORS
C_NO	= "\033[00m"
C_GOOD	= "\033[32m"

all: $(NAME)

$(NAME): $(OPATH) $(OFILE)
	@$(CC) $(OFILE) -I $(HPATH) -o $(NAME)
	@echo $(C_GOOD)Creation Executable$(C_NO)

$(OPATH):
	@echo "Creation of building directory"
	@mkdir $(OPATH)

$(OPATH)/%.o: $(CPATH)/%.cpp
	@echo "Creating file $@"
	@$(CC) -o $@ -c $^ -I $(HPATH)

clean:
	@echo "Deletion of building directory"
	@rm -rf $(OPATH)

fclean: clean
	@echo "Deletion of $(NAME)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

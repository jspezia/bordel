# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/23 19:10:49 by jspezia           #+#    #+#              #
#    Updated: 2014/04/15 17:19:35 by jspezia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPATH	= src
OPATH	= obj
HPATH	= include
LIBPATH	= ~/libft
HLIB	= $(LIBPATH)/include
LIB		= $(LIBPATH) -lft

CC		= cc $(FLAGS) $(XFLAGS)
FLAGS	= -Wall -Werror -Wextra
XFLAGS	= -g -O2
LDFLAGS	= -lncurses

NAME	= exec

SRC		= main.c

CFILE	= $(patsubst %,$(CPATH)/%, $(SRC))
OFILE	= $(patsubst %.c,$(OPATH)/%.o, $(SRC))

# COLORS
C_NO	= "\033[00m"
C_GOOD	= "\033[32m"

all: $(NAME)

$(NAME): $(OPATH) $(OFILE)
	@$(CC) $(LDFLAGS) -I $(HLIB) -I $(HPATH) -L $(LIB) $(OFILE) -o $(NAME)
	@echo $(C_GOOD)Creation Executable$(C_NO)

$(OPATH):
	@echo "Creation of building directory"
	@mkdir $(OPATH)

$(OPATH)/%.o: $(CPATH)/%.c
	@echo "Creating file $@"
	@$(CC) -o $@ -c $^ -I $(HPATH) -I $(HLIB)

clean:
	@echo "Deletion of building directory"
	@rm -rf $(OPATH)

fclean: clean
	@echo "Deletion of $(NAME)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

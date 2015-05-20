
CPATH	= src
OPATH	= obj
HPATH	= includes -lncurses

CC		= g++ $(FLAGS)
FLAGS	= -Wall -Werror -Wextra -g

NAME	= ft_retro

SRC		= main.cpp \
		  Input.cpp \
		  Map.cpp \
		  MapObject.cpp \
		  AFighter.cpp \
		  XWing.cpp \
		  TieFighter.cpp \
		  Projectile.cpp \
		  Deathstar.cpp

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

CPATH	= src
OPATH	= obj
HPATH	= includes -lncurses `pkg-config --libs gtk+-3.0`
CC		= g++ -Wall -Werror -Wextra $(FLAGS)
FLAGS	=  `pkg-config --cflags gtk+-3.0`

NAME	= ft_gkrellm

SRC		= main.cpp \
		  Input.cpp \
		  TodoModule.cpp \
		  Sysctl.cpp \
		  GTKDisplay.cpp \
		  TimeModule.cpp \
		  NCDisplay.cpp

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

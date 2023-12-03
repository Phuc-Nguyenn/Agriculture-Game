files = main.cpp\
			GameTile.cpp\
			Farm.cpp\
			Inventory.cpp\
			Plot.cpp\
			Entity.cpp\
			Plant.cpp\
			Wheat.cpp\
			Barley.cpp\
			Shop.cpp\
			Animal.cpp\
			Sheep.cpp\
			Chicken.cpp\

srcs = $(addprefix srcs/, $(files))
objs = $(srcs:.cpp=.o)



ifeq ($(OS),mac) # macOS
    NAME = farmgame_mac
    LIBS = -I/opt/homebrew/Cellar/sfml/2.6.0/include -L/opt/homebrew/Cellar/sfml/2.6.0/lib -lsfml-graphics -lsfml-window -lsfml-system -Wl,-rpath,/opt/homebrew/Cellar/sfml/2.6.0/lib
else ifeq ($(OS),linux) # Linux
    NAME = farmgame_linux
    LIBS = -lsfml-graphics -lsfml-window -lsfml-system
else
    $(error Unsupported operating system: $(OS))
endif

all: $(NAME)

$(NAME): $(objs)
	g++ -Wextra -Werror -Wall -I./headers $(objs) -o $(NAME) $(LIBS)

# Compilation rule for generating object files
%.o: %.cpp
	g++ -Wextra -Werror -Wall -I./headers -c $< -o $@

clean:
	rm -rf $(objs)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
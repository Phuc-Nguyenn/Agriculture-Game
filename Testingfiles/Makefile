files = 	GameTile.cpp\
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

test_files = mainTest.cpp\

srcs = $(addprefix ../srcs/, $(files))
test_srcs = $(addprefix ./, $(test_files))
objs = $(srcs:.cpp=.o)
test_objs = $(test_srcs:.cpp=.o)



ifeq ($(OS),mac) # macOS
    NAME = test_build_mac
    LIBS = -I/opt/homebrew/Cellar/sfml/2.6.0/include -L/opt/homebrew/Cellar/sfml/2.6.0/lib -lsfml-graphics -lsfml-window -lsfml-system -Wl,-rpath,/opt/homebrew/Cellar/sfml/2.6.0/lib
else ifeq ($(OS),linux) # Linux (e.g., Ubuntu)
    NAME = test_build_linux
    LIBS = -lsfml-graphics -lsfml-window -lsfml-system
else
    $(error Unsupported operating system: $(OS))
endif

all: $(NAME)

$(NAME): $(objs) $(test_objs)
	g++ -Wextra -Werror -Wall -I../headers -I./ $(objs) $(test_objs) -o $(NAME) $(LIBS)

# Compilation rule for generating object files
%.o: %.cpp
	g++ -Wextra -Werror -Wall -I../headers -I./ -c $< -o $@

clean:
	rm -rf $(objs) $(test_objs)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
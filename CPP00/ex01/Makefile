NAME = phonebook
CXXFLAGS = -Wall -Wextra -Werror -std=c++09

CXX = c++

SRCS := main.cpp Contact.hpp Contact.cpp

OBJS := ${SRCS:.cpp=.o}

all: ${NAME}

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re

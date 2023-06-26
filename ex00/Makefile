SRCS			= main.cpp Fixed.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= c++ -g3
RM				= rm -f
CXXFLAGS		= -Wall -Wextra -Werror -I.

NAME			= diff

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
NAME		=	Seriliazer

CC			=	c++
FLAG		=	-Wall -Wextra -Werror -std=c++98

LISTCPP		=	main.cpp \
				Data.cpp \
				Serializer.cpp


LISTINCS	=	Data.hpp \
				Serializer.hpp

				
SRC_DIR		=	./core/
SRC			=	$(addprefix $(SRC_DIR),$(LISTCPP))
OBJ			=	$(SRC:.cpp=.o)
INCS_DIR	=	./includes/
INCS		=	$(addprefix $(INCS_DIR),$(LISTINCS))

vpath %hpp includes

%.o : %.cpp
	$(CC) $(FLAG) -Iincludes -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(INCS)
	$(CC) $(OBJ) -o $(NAME) 
clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
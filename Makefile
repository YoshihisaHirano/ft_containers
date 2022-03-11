SRC		=	main.cpp
HDRS	=	vector.hpp iterator.hpp
NAME	=	ft_containers

.PHONY	:	all fclean

all		:	$(NAME)

$(NAME)	:	$(SRC) $(HDRS)
			c++ -Wall -Wextra -Werror -std=c++98 $(SRC) -o $(NAME)

fclean	:	
			rm -f $(NAME)
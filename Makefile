SRC		=	main.cpp
HDRS	=	vector.hpp stack.hpp bst.hpp map.hpp set.hpp
NAME	=	ft_containers

.PHONY	:	all fclean

all		:	$(NAME)

$(NAME)	:	$(SRC) $(HDRS)
			c++ -Wall -Wextra -Werror -std=c++98 -g $(SRC) -o $(NAME)

fclean	:	
			rm -f $(NAME)
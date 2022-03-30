SRC		=	main.cpp
HDRS	=	vector.hpp iterator.hpp equal.hpp pair.hpp stack.hpp is_integral.hpp enable_if.hpp bst.hpp
NAME	=	ft_containers

.PHONY	:	all fclean

all		:	$(NAME)

#-g -fsanitize=address
$(NAME)	:	$(SRC) $(HDRS)
			c++ -Wall -Wextra -Werror -std=c++98 -g $(SRC) -o $(NAME)

fclean	:	
			rm -f $(NAME)
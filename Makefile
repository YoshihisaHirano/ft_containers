SRC		=	main.cpp tests/utils_test.cpp tests/vector_tests.cpp\
            tests/stack_tests.cpp tests/pair_test.cpp tests/map_tests.cpp tests/set_tests.cpp
HDRS	=	vector.hpp stack.hpp bst.hpp map.hpp set.hpp
NAME	=	ft_containers

.PHONY	:	all fclean

all		:	$(NAME)

$(NAME)	:	$(SRC) $(HDRS)
			c++ -Wall -Wextra -Werror -std=c++98 -g $(SRC) -o $(NAME)

fclean	:	
			rm -f $(NAME)

re		:	fclean all
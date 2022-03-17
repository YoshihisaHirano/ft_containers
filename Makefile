SRC		=	main.cpp
HDRS	=	vector.hpp iterator.hpp
NAME	=	ft_containers

.PHONY	:	all fclean

all		:	$(NAME)

#-g -fsanitize=address
$(NAME)	:	$(SRC) $(HDRS)
			c++ -Wall -Wextra -Werror -std=c++98 -g $(SRC) -o $(NAME)

fclean	:	
			rm -f $(NAME)
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 20:02:24 by ahajji            #+#    #+#              #
#    Updated: 2023/10/13 22:19:59 by ahajji           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = check_arg.c philo.c simulation_philo.c utils.c philo_init.c check_death.c

OBJ = $(SRC:.c=.o)
 
all : $(NAME)

$(NAME) : $(OBJ)
	@cc $(OBJ) -Wall -Werror -Wextra -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/13 09:36:31 by hyenam            #+#    #+#              #
#    Updated: 2021/11/24 15:30:43 by hyenam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC := gcc
RM := rm -rf
CFLAGS := -Wall -Werror -Wextra -pthread
SRCS = 	./main.c ./data_parse.c ./action.c ./philo_utils.c\
		./ft_atoi.c ./ft_split.c ./utils.c 

OBJS = $(SRCS:.c=.o)

all : $(NAME)

.PHONY : all clean fclean re

$(NAME): $(OBJS)
		gcc $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

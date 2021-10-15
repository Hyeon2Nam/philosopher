# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/13 09:36:31 by hyenam            #+#    #+#              #
#    Updated: 2021/10/15 11:58:26 by hyenam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC := gcc
RM := rm -rf
CFLAGS := -Wall -Werror -Wextra -pthread
SRCS = 	./main.c ./philo.c

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

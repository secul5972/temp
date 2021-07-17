# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/12 14:12:53 by seungcoh          #+#    #+#              #
#    Updated: 2021/07/18 03:48:25 by seungcoh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
SRCS = push_swap.c\
       push_swap2.c\
       ternary_div.c\
       ternary_div2.c\
       ternary_div3.c\
       list.c\
       push_swap_ins.c\
       push_swap_utils.c\
       push_swap_utils2.c\
       ins_merge.c
OBJS = $(SRCS:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

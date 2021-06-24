# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 19:20:46 by seungcoh          #+#    #+#              #
#    Updated: 2021/05/17 13:54:11 by seungcoh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRCS = ft_printf.c\
       ft_printf_utils.c\
       ft_printf_utils2.c\
       print.c\
       check.c
OBJS = $(SRCS:.c=.o)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJS)
			ar -rc $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)

re:			fclean all

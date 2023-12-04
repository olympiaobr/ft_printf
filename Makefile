# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 17:46:05 by olobresh          #+#    #+#              #
#    Updated: 2023/12/04 17:37:40 by olobresh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

HEAD	= ./include

SRCS	= ./srcs/ft_printf.c \
	  ./srcs/ft_prtchar.c \
	  ./srcs/ft_prthex.c \
	  ./srcs/ft_prtint.c \
	  ./srcs/ft_prtptr.c \
	  ./srcs/ft_prtstr.c \
	  ./srcs/ft_prtunsint.c \

OBJS	= $(SRCS:.c=.o)

CC	= cc

CFLAGS	= -Wall -Wextra -Werror -I $(HEAD)

RM	= rm -f

AR	= ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
		
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
	  

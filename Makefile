NAME	= libftprintf.a

LIBFT	= libft

LIB		= libftprint.h -L./libft -lft

SRCS	= ./srcs/ft_printf.c

OBJS	= $(SRCS:.c=.o)

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

AR		= ar rcs

all: $(NAME)

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

.o.c:
	@$(CC) $(CFLAGS) -I $(LIB) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFT)

fclean:	clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT)

re:		fclean all

.PHONY:	all clean fclean re

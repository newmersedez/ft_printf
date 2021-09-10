NAME	= libftprintf.a

LIBFT 	= libft

CC 		= gcc

FLAGS	= -Wall -Wextra -Werror

RM		= rm -rf

HEADER 	= headers

DIR_S 	= sources

DIR_O 	= obj

SOURCES	= ft_printf.c \
			ft_min_max.c \
			ft_is_allowed_char.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putnbr_decimal.c \
			ft_putnbr_hexadecimal.c \
			ft_putspecifiers.c \
			ft_fill_flags.c \
			ft_fill_width.c \
			ft_fill_precision.c \
			ft_fill_specifiers.c \
			ft_is_specifier.c \
			ft_numberlen.c \
			ft_output_specifiers.c \
			ft_output_spaces.c \
			ft_output_zeros.c \
			ft_output_char.c \
			ft_output_string.c \
			ft_output_decimal.c \
			ft_output_hexadecimal.c \
			ft_output_address.c \
			ft_output_percent.c \

SRCS 			= $(addprefix $(DIR_S)/,$(SOURCES))

OBJS 			= $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: 			$(NAME)

$(NAME):		$(OBJS)
				make -C $(LIBFT)
				cp libft/libft.a ./$(NAME)
				ar rc $(NAME) $(OBJS)

$(DIR_O)/%.o:	$(DIR_S)/%.c $(HEADER)/ft_printf.h
				mkdir -p obj
				$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
				${RM} $(OBJS)
				${RM} $(DIR_O)
				make clean -C $(LIBFT)

fclean: 		clean
				${RM} $(NAME)
				make fclean -C $(LIBFT)

re: 			fclean all

.PHONY: 		all clean fclean re

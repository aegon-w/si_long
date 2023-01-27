NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c mlx.c so_long.c func.c check_path.c get_next_line.c get_next_line_utils.c read_map.c moves.c func2.c \
		ft_printf/ft_printf.c    ft_printf/ft_putnbr.c    ft_printf/ft_putnbrhex.c ft_printf/ft_putstr1.c   ft_printf/ft_strlen1.c\
ft_printf/ft_putchar.c   ft_printf/ft_putnbrha.c  ft_printf/ft_putp.c      ft_printf/ft_putunbr.c

all : $(NAME)

$(NAME) :  ${PRINTF} $(SRCS)
	$(CC) $(CFLAGS) $(SRCS)  -lmlx -framework OpenGL -framework AppKit  -o $(NAME)


${PRINTF}:
	@make -C ft_printf


clean :
	rm -f $(NAME)
	@make clean -C ft_printf

fclean :	clean

re : fclean all

.PHONY: re all fclean clean bonus
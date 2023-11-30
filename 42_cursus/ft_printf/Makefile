NAME = libftprintf.a
SRC =	ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_strchr.c \
		ft_putnbr_hex_l.c ft_putnbr_hex_u.c ft_putnbr_hex_p.c ft_putnbr_u.c \

OBJ = ${SRC:.c=.o}
LIBC = ar -rc
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME} : ${OBJ}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@
	${LIBC} ${NAME} $@

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all


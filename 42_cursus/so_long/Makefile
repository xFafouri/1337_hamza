NAME = so_long
CC = gcc 
CFLAGS = -Wall -Wextra -Werror -Imlx
SOURCE = ./src/so_long.c ./src/key_press.c ./src/free_map.c ./src/player_pos.c ./src/check_ext.c ./src/ft_printf/ft_printf.c ./src/ft_printf/ft_putchar.c ./src/ft_printf/ft_putnbr.c ./src/ft_printf/ft_putstr.c ./src/ft_printf/ft_strchrr.c ./src/ft_printf/ft_putnbr_hex_l.c ./src/ft_printf/ft_putnbr_hex_u.c ./src/ft_printf/ft_putnbr_hex_p.c ./src/ft_printf/ft_putnbr_u.c ./src/get_next_line/get_next_line.c ./src/get_next_line/get_next_line_utils.c ./src/check_valid_map.c ./src/load_map.c ./src/Validate_PCE.c ./src/load.c ./src/check_tools.c ./src/put_image.c
SOURCEB = ./bonus/so_long_bonus.c ./bonus/player_pos.c ./bonus/ft_enemy.c ./bonus/key_press.c ./bonus/key_animate.c ./bonus/free_map.c ./bonus/check_ext.c ./bonus/ft_printf/ft_printf.c ./bonus/ft_printf/ft_putchar.c ./bonus/ft_printf/ft_putnbr.c ./bonus/ft_printf/ft_putstr.c ./bonus/ft_printf/ft_strchrr.c ./bonus/ft_printf/ft_putnbr_hex_l.c ./bonus/ft_printf/ft_putnbr_hex_u.c ./bonus/ft_printf/ft_putnbr_hex_p.c ./bonus/ft_printf/ft_putnbr_u.c ./bonus/get_next_line/get_next_line.c ./bonus/get_next_line/get_next_line_utils.c ./bonus/check_valid_map.c ./bonus/load_map_bonus.c ./bonus/Validate_PCE_bonus.c ./bonus/load_bonus.c ./bonus/check_tools_bonus.c ./bonus/put_image_bonus.c
OBJ		= ${SOURCE:.c=.o}
BOBJ	= ${SOURCEB:.c=.o}

all:$(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

bonus: $(BOBJ)
	$(CC) $(BOBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean: 
	rm -rf ${OBJ} ${BOBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

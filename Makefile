NAME = fractol
FLAGS = -lX11 -lXext -pthread -lm -L. -Wpsabi -march=native -Ofast -mavx2 -mbmi2 -mpopcnt -mfma -mcx16 
LIBRARY = libft/libft.a minilibx-linux/libmlx_Linux.a
HEADER = fractol.h
SRC = fractol.c key_mouse_control.c draw.c image_changes.c \
image_utils.c init.c color.c args_parse.c threads.c \
change_fractal.c draw_calc.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBRARY):
		@make -C libft/
		@make -C minilibx-linux/
$(OBJ): %.o: %.c
		gcc -c $(FLAGS) -I libft/ -o $@ $<
$(NAME): $(LIBRARY) $(OBJ)
		@gcc $(OBJ) $(LIBRARY) -o $(NAME) $(FLAGS)
clean:
	@rm -f *.o
	@make -C libft clean

fclean: clean
	@rm -f *.o $(NAME)
	@make -C libft fclean

re: fclean all

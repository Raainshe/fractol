NAME    := fractol
CFLAGS  := -Wextra -Wall -Werror -Wunreachable-code -Ofast 
LIBMLX  := ./MLX42
LIBFT   := ./libft
CC	  := cc

# Headers
HEADERS	:= -I . -I $(LIBMLX)/include -I $(LIBFT)

# Libraries
LIBS    := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)/libft.a

# Source files - Add your files here
SRCS := src/fractol.c \
        src/mandelbrot.c \
		src/julia.c \
        src/initialise.c \
        src/hooks.c

OBJS    := ${SRCS:.c=.o}

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT) clean
	@printf "Cleaning object files...\n"

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean
	@printf "Cleaning executable and libraries...\n"

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft
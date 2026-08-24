NAME		= cub3D

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

MLX_DIR		= minilibx-linux
MLX_LIB		= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

LIBFT_DIR	= libft
LIBFT_LIB	= $(LIBFT_DIR)/libft.a
LIBFT_FLAGS	= -L$(LIBFT_DIR) -lft

INC_DIR		= includes
SRC_DIR		= src
OBJ_DIR		= obj

SRCS		= mlx/main.c \
			  mlx/hooks.c \
			  rendering/raycast.c \
			  rendering/render.c \
			  rendering/dda.c \
			  movement/player.c \
			  utils/stub_map.c

OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/mlx $(OBJ_DIR)/rendering $(OBJ_DIR)/movement $(OBJ_DIR)/utils

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/cub3d.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

$(NAME): $(MLX_LIB) $(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
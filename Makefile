NAME        = cub3D

# Compilateur et flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3
RM          = rm -f

# Chemins des répertoires
SRC_DIR     = src
INC_DIR     = include
OBJ_DIR     = obj
MLX_DIR     = minilibx-linux

# Liste des fichiers source
SRC_FILES   =  main.c \
               check_and_pars.c \
               check_and_pars_1.c \
               check.c \
               error.c \
               toolbox.c \
               toolbox_1.c \
               toolbox_2.c \
               toolbox_3.c \
               toolbox_4.c \
               fill_map.c \
               init_data.c \
               split.c \
               free.c \
               ft_free_elem.c \
               raycasting.c \
               raycasting2.c \
               texture.c \
               orientation.c \
               put_texture.c \
               rotate.c \
               move.c \
               key_press.c

# Préfixer les chemins des sources et objets
SRC         = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ         = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Bibliothèque MLX
MLX_LIB     = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Headers
INCLUDES    = -I$(INC_DIR) -I$(MLX_DIR)

# Règles
all: $(OBJ_DIR) $(MLX_LIB) $(NAME)

# Création du répertoire des objets
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compilation de MLX
$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

# Compilation des fichiers .c en .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compilation finale
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_LIB) $(MLX_FLAGS)
	@echo "\033[32m[ ✓ ] $(NAME) compiled\033[0m"

# Nettoyage des fichiers objets
clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(MLX_DIR) clean
	@echo "\033[31m[ ✓ ] Removed object files\033[0m"

# Nettoyage complet
fclean: clean
	$(RM) $(NAME)
	@echo "\033[31m[ ✓ ] Removed $(NAME)\033[0m"

# Recompilation
re: fclean all

# Pour éviter les conflits avec des fichiers
.PHONY: all clean fclean re
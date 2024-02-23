CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra -g

SRCS	=	so_long.c \
			player_movement.c \
			player_movement_2.c	\
			map_utils.c \
			image_utils.c \
			hooks.c \
			check_map.c \
			check_map_2.c	\
			build_map.c \
			end_game.c \
			check_map_utils.c \
			check_map_utils_2.c		\
			itoa.c	\
			main.c	\

SRCS_DIR	= srcs/
SRCS_PATH	= $(addprefix $(SRCS_DIR), $(SRCS))

#ft_printf
PRINTF_A	= ft_printf.a
PRINTF_PATH = $(addprefix $(PRINTF_DIR), $(PRINTF_A))
PRINTF_DIR = ./printf/
CFLAGS_PRINTF = -L $(PRINTF_DIR) -lftprintf
 

NAME	=	./so_long

DEPS	=	check_map.h \
			image.h \
			map.h \
			player_movement.h \
			player_movement_2.h	\
			so_long.h \
			hooks.h \
			end_game.h \
			itoa.h	\

DEPS_DIR	= deps/
DEPS_PATH	= $(addprefix $(DEPS_DIR), $(DEPS))

OBJS		=	$(SRCS:.c=.o)
OBJS_DIR	=	objs/
OBJS_PATH	=	$(addprefix $(OBJS_DIR), $(OBJS))

#Minilibx
MLX_DIR		=	./minilibx-linux
CFLAGS_MLX	=	-I $(MLX_DIR)
LDFLAGS		=	-L $(MLX_DIR) -lmlx -lX11 -lXext

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c $(DEPS_PATH)
		@mkdir -p $(OBJS_DIR)
		@${CC} $(CFLAGS) -c $< -o $@

all:		$(NAME)

bonus:		$(NAME)

printf:
	@make -C $(PRINTF_DIR) --no-print-directory

minilibx-linux: 
	@make -C $(MLX_DIR) --no-print-directory

$(NAME): minilibx-linux printf ${OBJS_PATH} 
	@$(CC) $(CFLAGS) -g $(OBJS_PATH) $(CFLAGS_MLX) $(LDFLAGS) $(CFLAGS_PRINTF) -o $(NAME) -lm

valgrind :	minilibx-linux printf ${OBJS_PATH}
	@$(CC) $(CFLAGS) $(OBJS_PATH) $(CFLAGS_MLX) $(LDFLAGS) $(CFLAGS_PRINTF) -o $(NAME).vgr -g -lm

mac :		${OBJS_PATH}
	@$(CC) $(OBJS_PATH) -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit -o $(NAME)

clean_printf:
	@make clean -C $(PRINTF_DIR)

fclean_printf:
	@make fclean -C $(PRINTF_DIR)

clean_minilibx:
	@make clean -C $(MLX_DIR)

clean: clean_printf clean_minilibx
	@rm -rf ${OBJS_DIR}

fclean:		clean fclean_printf
	@rm -f ${NAME} $(NAME).vgr $(NAME).test

re:			fclean all

.PHONY:	all valgrind mac clean fclean re minilibx-linux printf


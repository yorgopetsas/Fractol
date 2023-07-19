# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzisis-p <yzisis-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 10:18:58 by yzisis-p          #+#    #+#              #
#    Updated: 2023/07/19 13:51:27 by yzisis-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fractol

MKF =	Makefile

SRC =	src/main.c \
			src/hooks.c	\
			src/draw.c	\
			src/fractals.c \
			src/controls.c \
			src/mandelbrod.c \
			src/tools.c \
			src/temp.c
			# src/menu.c

STR_DIR =	src/

# Header of fractol.h (funcitons)
HEADER_FRAC =	inc/fractol.h

# Headers of libtf
DIR_LIBFT =	libft/include

# Headers of mlx
DIR_MLX =	inc/mlx

# Headers of fractol
DIR_HEDS =	inc/

# All the objects of startup
OBJ_STR =	$(SRC:.c=.o)

ALL_DEPS =$(SRC:.c=.d)

# Mlx libraries
MLX =	inc/mlx/libmlx.a

# Makefile mlx
MAKE_MLX =	inc/mlx

# Variable to compile .c files
GCC =	gcc -o3

FLAGS =	-Wall -Werror -Wextra -MMD -MP

MINILIBXCC :=	-I mlx -L $(DIR_MLX) -lmlx

OPENGL :=	-framework OpenGL -framework AppKit

# Colors
DEL_LINE =		\033[2K
ITALIC =		\033[3m
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m


#	----------------------------------------	ACTIONS
all:
	@$(MAKE) -C $(MAKE_MLX)
	@$(MAKE) $(NAME)

clean:
	@rm -f $(ALL_DEPS)
	@rm -f $(OBJ_STR)
	@printf "All fractol objects removed\n"

fclean:
	@rm -f $(ALL_DEPS)
	@rm -f $(OBJ_STR)
	@rm -f $(NAME)
	@printf "All fractol files $(RED)removed\n$(DEF_COLOR)"

fcleanall:
	@$(MAKE) clean -C $(MAKE_MLX)
	@printf "All mlx files $(RED)removed\n$(DEF_COLOR)"
	@$(MAKE) fclean

re:
	@$(MAKE) fclean
	@$(MAKE) all

reall:
	@$(MAKE) fcleanall
	@$(MAKE) all			

clean_objs:
	@rm -f $(ALL_DEPS)
	@rm -f $(OBJ_STR)
	@printf "All fractol objects removed\n"		

$(NAME) ::	$(OBJ_STR)
				@printf "$(DEL_LINE)\r Compiling $@\n"
				@$(GCC) $(FLAGS) $^ $(MINILIBXCC) $(OPENGL) -o $@

	  -c $< -o $@

$(NAME) ::
				@printf "$(DEL_LINE)\r$(BOLD)$(DARK_GREEN)FRACTOL COMPILED ✅$(DEF_COLOR)\n"

%.o :	%.c $(MKF)
			@printf "$(DEL_LINE)\rcompiling fractol file:\t$@"
			@$(GCC) $(FLAGS) -I$(DIR_HEDS) -c $< -o $@

-include $(ALL_DEPS)

.PHONY:	all update clean fclean re reall
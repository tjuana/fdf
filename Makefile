# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 12:19:09 by flklein           #+#    #+#              #
#    Updated: 2019/06/04 15:04:07 by tjuana           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

# src / obj files
SRC		= main.c \
		= read_and_count.c\
		= mlx_hook.c\
		= take_pic.c\
		= map_to_image.c\
		= button.c\
		= setup.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

# mlx library
MLX		= /Users/tjuana/42/FdF/minilibx
MLX_LIB	= $(addprefix $(MLX),mlx.a)
MLX_INC	= -I ./minilibx
MLX_LNK	= -L /Users/tjuana/42/FdF/minilibx  -lmlx -framework OpenGL -framework AppKit

# ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I /Users/tjuana/42/FdF
FT_LNK	= -L ./libft -l ft

OBJDIR = ./objec/

.PHONY: all, clean, fclean, re

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I *.h -o $@ -c $<
	@echo "Object done."

$(FT_LIB):
	@make -C $(FT)
	@echo "Libft compilen man."

$(MLX_LIB):
	@make -C $(MLX)
	@echo "MiniLibX done man."

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)
	@echo "Everything done."


clean:
	@rm -rf $(OBJDIR)
	@make -C $(FT) clean
	@make -C $(MLX) clean
	@echo "Objects cleaned."

fclean: clean
	@rm -rf $(NAME)
	@make -C $(FT) fclean
	@echo "Everything cleaned."

re: fclean all

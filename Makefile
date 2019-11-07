# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/29 18:38:09 by dtoy              #+#    #+#              #
#    Updated: 2019/04/29 20:23:22 by dtoy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf
SRCS = main.c ft_validation.c ft_rotate.c ft_readfile.c ft_push_list.c ft_movedots.c ft_key_press.c ft_find_color.c ft_draw_map.c ft_draw_line.c ft_clear_struct.c ft_clear_arr.c get_next_line.c
OBJ = main.o ft_validation.o ft_rotate.o ft_readfile.o ft_push_list.o ft_movedots.o ft_key_press.o ft_find_color.o ft_draw_map.o ft_draw_line.o ft_clear_struct.o ft_clear_arr.o get_next_line.o
INCLUDES = includes

all: $(NAME)

$(NAME):
	make -C libft
	make -C minilibx_macos
	gcc -Wall -Werror -Wextra -c $(SRCS) -I$(INCLUDES)
	gcc -o $(NAME) $(OBJ) -L libft -lft -L minilibx_macos -lmlx -framework OpenGL -framework Appkit

clean:
	make -C libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft fclean
	make -C minilibx_macos clean
	rm -rf $(NAME)

re: fclean all
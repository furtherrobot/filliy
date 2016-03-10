# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/25 18:16:27 by bchevali          #+#    #+#              #
#    Updated: 2016/03/10 15:21:13 by bchevali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	fillit

SRC_DIR				=	srcs
INCLUDE_DIR			=	includes
OBJ_DIR				=	objs

LIBFT				=	ft
LIBFT_DIR			=	libft
LIBFT_NAME			=	$(LIBFT_DIR)/libft.a
LIBFT_INCLUDE_DIR	=	$(LIBFT_DIR)/includes

COMPILER			=	gcc
CFLAGS				=	-Wall -Wextra -Werror -c\
						-I$(INCLUDE_DIR) -I$(LIBFT_INCLUDE_DIR)
LFLAGS				=	-L$(LIBFT_DIR) -l$(LIBFT)

SRC					=	main.c				\
						read_file.c			\
						check_file.c		\
						opt_check.c			\
						sequence.c			\
						create_piece.c		\
						piece_tools.c		\
						map.c				\
						solve_map.c			\
						piece_tools2.c		\
						fillit.c

OBJ					=	$(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all:
	@$(MAKE) $(LIBFT_NAME)
	@$(MAKE) $(NAME)

$(LIBFT_NAME):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(COMPILER) $(LFLAGS) $^ -o $@

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(COMPILER) $(CFLAGS) $^ -o $@

clean:
	@rm -rf $(OBJ)
	@rm -rdf $(OBJ_DIR)

fcleanlib:
	@(cd $(LIBFT_DIR) && $(MAKE) fclean)

fclean: clean fcleanlib
	@rm -f $(NAME)

re:
	@$(MAKE) fcleanlib
	@$(MAKE) fclean
	@$(MAKE) all

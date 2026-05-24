# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/22 20:00:40 by juan-her          #+#    #+#              #
#    Updated: 2026/05/25 01:07:35 by juan-her         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= bandera
SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= includes
LIBFT_DIR	= libft
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
INCLUDES	= -I$(INC_DIR) -I$(LIBFT_DIR)
LDFLAGS		= -L$(LIBFT_DIR)
MAIN_SRCS	= main.c

# SRC FILES
PARSE_SRCS = init_parse.c \
				parse.c \
				header.c \
				check_header.c \
				map.c \
				check_map.c

CLEAN_SRCS = clean_1.c

UTILS_FILE_SRC = get_next_line.c \
					utils.c

SRCS		= $(addprefix $(SRC_DIR)/, $(MAIN_SRCS)) \
				$(addprefix $(SRC_DIR)/parseo/, $(PARSE_SRCS)) \
				$(addprefix $(SRC_DIR)/clean/, $(CLEAN_SRCS)) \
				$(addprefix $(SRC_DIR)/utils/parse_file/, $(UTILS_FILE_SRC))

OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT		= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "Bandera Negra done"

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re

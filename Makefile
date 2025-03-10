# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thessena <thessena@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 12:05:54 by thessena          #+#    #+#              #
#    Updated: 2025/03/10 13:16:37 by thessena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror

# Project name and files
NAME        = push_swap
SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR     = include
SRC_FILES   = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ_FILES   = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Colors
GREEN       = \033[0;32m
RESET       = \033[0m  

# Rules
all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) -I$(INC_DIR) $^ -o $@
	@echo "$(GREEN)$(NAME) successfully built!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)Object files removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)$(NAME) executable removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re

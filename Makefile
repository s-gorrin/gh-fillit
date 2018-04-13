NAME := fillit

CC := gcc
CFLAGS += -Wall -Wextra -Werror

SOURCE_DIR := src
BIN_DIR := obj


# SOURCE_DIR := $(addprefix $(SOUCE_DIR)/,$())

FILES += main	file_to_mino_list	is_valid_mino_list	mino_id	\
		 place_mino	unplace_mino	fillit_solver	ft_error	\
		 map_line_len

BIN := $(addsuffix .o,$(FILES))

OBJ := $(addprefix $(BIN_DIR)/,$(BIN))

INC := inc

$(BIN_DIR)/%.o: $(SOURCE_DIR)/%.c
	@$(CC) $(CFLAGS) -I $(INC) -c $^
	@/bin/echo -n "#"

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n\033[32m[ object files created ( ͡° ͜ʖ ͡°) ]\033[0m"
	@$(CC) $(OBJ) -o $(NAME)
	@echo "\033[32m[ executable $(NAME) created ( ͡° ͜ʖ ͡°) ]\033[0m"

$(OBJ): | $(BIN_DIR)

$(BIN_DIR):
	@mkdir -p $(addprefix $(BIN_DIR)/,$(BIN))


clean:
	@rm -rf $(BIN_DIR)
	@echo "\033[31m[ object files deleted (╯°□°）╯︵ ┻━┻ ]\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31m[ executable $(NAME) deleted ᕙ(⇀‸↼‶)ᕗ ]\033[0m"

re: fclean all

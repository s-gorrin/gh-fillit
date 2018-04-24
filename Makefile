NAME := fillit

CC := gcc
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I inc

FILES +=	src/mino_id.c	src/check_place_mino.c	src/file_to_mino_list.c	src/fillit_map.c	\
			src/fillit_mino.c	src/fillit_solver.c	src/main.c	src/place_mino.c	\
			src/unplace_mino.c	src/check_tools.c src/verify_input.c	src/fillit_cleanup.c

LIBFT := libft/libft.a
DEBUG := -g
.PHONY: clean fclean re

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(FILES) $(LIBFT) -o $(NAME)
	@echo "\033[32m[ executable $(NAME) created ( ͡° ͜ʖ ͡°) ]\033[0m"

debug:
	@$(CC) $(CFLAGS) $(FILES) $(LIBFT) -o $(NAME) $(DEBUG)
	@echo "\033[32m[ executable with debugging: $(NAME) created ( ͡° ͜ʖ ͡°) ]\033[0m"

clean:
	@rm -rf $(NAME)
	@echo "\033[31m[ object files deleted (╯°□°）╯︵ ┻━┻ ]\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31m[ executable $(NAME) deleted ᕙ(⇀‸↼‶)ᕗ ]\033[0m"

re: fclean all

NAME := libft.a

CC := gcc
FLAGS := -Wall -Wextra -Werror

BIN_DIR := objs

# Files names
FILES +=	ft_isupper	ft_islower	ft_isalpha	ft_isspace	\
		ft_isdigit	ft_isalnum	ft_ispunct	ft_isgraph	\
		ft_isprint	ft_isascii	ft_iscntrl	ft_isxdigit	\
		ft_toupper	ft_tolower	\
		ft_strlen	ft_strcpy	ft_strncpy	ft_strcat	\
		ft_strncat	ft_strlcat	ft_strdup	ft_strndup	\
		ft_strchr	ft_strrchr	ft_strcmp	ft_strncmp	\
		ft_strstr	ft_strnstr	ft_strclr	ft_strdel	\
		ft_strequ	ft_strnequ	ft_striter	ft_striteri	\
		ft_strjoin	ft_strmap	ft_strmapi	ft_strnew	\
		ft_strsplit	ft_strsub	ft_strtrim	ft_strlcpy	\
		ft_strnjoin	\
		ft_memset	ft_bzero	ft_memcpy	ft_memccpy	\
		ft_memcpy_bwd	ft_memmove	ft_memcmp	ft_memchr	\
		ft_memalloc	ft_memdel	\
		ft_atoi		ft_itoa		ft_abs		ft_numlen	\
		ft_is_prime	ft_sqrt_cl	ft_arrlen	\
		ft_putchar	ft_putstr	ft_putendl	ft_putnbr	\
		ft_putchar_fd	ft_putstr_fd	ft_putendl_fd	ft_putnbr_fd	\
		ft_lstnew	ft_lstdelone	ft_lstdel	ft_lstadd	\
		ft_lstiter	ft_lstmap
BIN := $(addsuffix .o,$(FILES))

OBJS := $(addprefix $(BIN_DIR)/,$(BIN))

$(BIN_DIR)/%.o: %.c
	@$(CC) $(FLAGS) -I . -c $^ -o $@
	@/bin/echo -n "#"

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n\033[32m[ ᕦ(ˇò_ó)ᕤ object files created ᕦ(ò_óˇ)ᕤ ]\033[0m"
	@ar rc $@ $(OBJS)
	@ranlib $@
	@echo "\033[36m[ (^-^)/ library $(NAME) created \(^-^) ]\033[0m"

$(OBJS): | $(BIN_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

clean:
	@/bin/rm -rf $(BIN_DIR)
	@echo "\033[31m[object files deleted]\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[31m[executable $(NAME) deleted]\033[0m"

re: fclean all

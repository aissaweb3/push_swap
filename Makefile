# Executable
NAME = push_swap
NAME_BNS = checker_bonus

# Directories
BONUS_DIR = checker
LIBFT = libft
GNL = gnl
PARS = parsing
ALGO_DIR = algorithm
STACK_DIR = stack
LANG_DIR = push_swap_lang
A_DIR = $(LANG_DIR)/A
A_B_DIR = $(LANG_DIR)/A_B
B_DIR = $(LANG_DIR)/B
INC = $(ALGO_DIR)/algorithm.h $(STACK_DIR)/stack.h $(STACK_DIR)/struct.h push_swap.h parsed_data.h $(LANG_DIR)/language.h $(LIBFT)/libft.h $(PARS)/parsing.h
LIBFT_SRC = $(LIBFT)/ft_atoi.c $(LIBFT)/ft_isalpha.c $(LIBFT)/ft_itoa.c $(LIBFT)/ft_memmove.c $(LIBFT)/ft_putnbr_fd.c $(LIBFT)/ft_strdup.c $(LIBFT)/ft_strlcpy.c    $(LIBFT)/ft_strnstr.c    $(LIBFT)/ft_tolower.c \
			$(LIBFT)/ft_bzero.c $(LIBFT)/ft_isascii.c $(LIBFT)/ft_memchr.c $(LIBFT)/ft_memset.c $(LIBFT)/ft_putstr_fd.c $(LIBFT)/ft_striteri.c $(LIBFT)/ft_strlen.c     $(LIBFT)/ft_strrchr.c    $(LIBFT)/ft_toupper.c \
			$(LIBFT)/ft_calloc.c $(LIBFT)/ft_isdigit.c $(LIBFT)/ft_memcmp.c $(LIBFT)/ft_putchar_fd.c $(LIBFT)/ft_split.c $(LIBFT)/ft_strjoin.c $(LIBFT)/ft_strmapi.c    $(LIBFT)/ft_strtrim.c \
			$(LIBFT)/ft_isalnum.c $(LIBFT)/ft_isprint.c $(LIBFT)/ft_memcpy.c $(LIBFT)/ft_putendl_fd.c $(LIBFT)/ft_strchr.c $(LIBFT)/ft_strlcat.c $(LIBFT)/ft_strncmp.c    $(LIBFT)/ft_substr.c

# Source files
SRC_FILES = \
	$(LIBFT_SRC) \
	$(ALGO_DIR)/my_algo.c $(ALGO_DIR)/calc_rotate_push.c $(ALGO_DIR)/find_LIS_and_push.c $(ALGO_DIR)/mov_to_top.c $(ALGO_DIR)/utils.c \
	$(STACK_DIR)/utils.c \
	$(LANG_DIR)/general.c \
	$(A_DIR)/pa.c $(A_DIR)/ra-rra.c $(A_DIR)/sa.c \
	$(B_DIR)/pb.c $(B_DIR)/rb-rrb.c $(B_DIR)/sb.c \
	$(A_B_DIR)/rr.c $(A_B_DIR)/rrr.c $(A_B_DIR)/ss.c \
	$(PARS)/init.c $(PARS)/parser.c $(PARS)/validator.c $(PARS)/check_dup.c \
	push_swap.c

# Bonus Source files
BNS_SRC_FILES = \
	$(LIBFT_SRC) \
	$(ALGO_DIR)/find_LIS_and_push.c $(ALGO_DIR)/mov_to_top.c \
	$(STACK_DIR)/utils.c \
	$(LANG_DIR)/general.c \
	$(A_DIR)/pa.c $(A_DIR)/ra-rra.c $(A_DIR)/sa.c \
	$(B_DIR)/pb.c $(B_DIR)/rb-rrb.c $(B_DIR)/sb.c \
	$(A_B_DIR)/rr.c $(A_B_DIR)/rrr.c $(A_B_DIR)/ss.c \
	$(PARS)/init.c $(PARS)/parser.c $(PARS)/validator.c $(PARS)/check_dup.c \
	$(BONUS_DIR)/apply_instr_bonus.c $(BONUS_DIR)/stack_sorted_bonus.c $(BONUS_DIR)/read_line_bonus.c \
	$(GNL)/get_next_line.c $(GNL)/get_next_line_utils.c \
	checker.c

# Object files
OBJ_FILES = $(SRC_FILES:.c=.o)
BNS_OBJ_FILES = $(BNS_SRC_FILES:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Rules
all: $(NAME)
bonus: $(NAME_BNS)

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)
	@echo "[INFO] $(NAME) has been created."

$(NAME_BNS): $(BNS_OBJ_FILES)
	@$(CC) $(CFLAGS) $(BNS_OBJ_FILES) -o $(NAME_BNS)
	@echo "[INFO] $(NAME_BNS) has been created."

$(GNL)/%.o: $(GNL)/%.c $(INC) $(GNL)/get_next_line.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "[COMPILE] $<"

$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c $(INC) $(BONUS_DIR)/checker_bonus.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "[COMPILE] $<"

%.o: %.c $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "[COMPILE] $<"


clean:
	@rm -rf $(OBJ_FILES) $(BNS_OBJ_FILES)
	@echo "[INFO] Object files have been cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] $(NAME) has been removed."
	@rm -f $(NAME_BNS)
	@echo "[INFO] $(NAME_BNS) has been removed."

re: fclean all
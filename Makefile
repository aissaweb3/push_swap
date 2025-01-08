# Executable
NAME = push_swap

# Directories
ALGO_DIR = algorithm
STACK_DIR = stack
LANG_DIR = push_swap_lang
A_DIR = $(LANG_DIR)/A
A_B_DIR = $(LANG_DIR)/A_B
B_DIR = $(LANG_DIR)/B
INC = $(ALGO_DIR)/algorithm.h $(STACK_DIR)/stack.h push_swap.h $(LANG_DIR)/language.h

# Source files
SRC_FILES = \
	$(ALGO_DIR)/my_algo.c $(ALGO_DIR)/calc_rotate_push.c $(ALGO_DIR)/find_LIS_and_push.c $(ALGO_DIR)/mov_to_top.c \
	$(STACK_DIR)/utils.c \
	$(LANG_DIR)/general.c \
	$(A_DIR)/pa.c $(A_DIR)/ra-rra.c $(A_DIR)/sa.c \
	$(B_DIR)/pb.c $(B_DIR)/rb-rrb.c $(B_DIR)/sb.c \
	$(A_B_DIR)/rr.c $(A_B_DIR)/rrr.c $(A_B_DIR)/ss.c \
	init.c main.c parsing.c validate.c

# Object files
OBJ_FILES = $(SRC_FILES:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS = 

# Rules
all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)
	@echo "[INFO] $(NAME) has been created."

%.o: %.c $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "[COMPILE] $<"

clean:
	@rm -rf $(OBJ_FILES)
	@echo "[INFO] Object files have been cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] $(NAME) has been removed."

re: fclean all
CC = cc
PUSH_SWAP = push_swap
CFLAGS = -Wall -Wextra -Werror -g
RULES = rules

RM = rm -rf

SRC = push_swap.c parsing.c ft_split.c $(RULES)/push.c $(RULES)/swap.c $(RULES)/rotate.c
OBJ = $(SRC:.c=.o)
# ANSI escape codes for colors
GREEN = \033[32m
RESET = \033[0m

define PRINT_LOADING
	@printf "$(GREEN)compiling... ["
	@for i in $(shell seq 0 10 100); do \
		printf "▓"; \
		sleep 0.001; \
	done
	@printf "] 100%%$(RESET)\n"
endef

all: $(PUSH_SWAP)

$(PUSH_SWAP): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(PUSH_SWAP)
	@echo "$(GREEN)Run './$(PUSH_SWAP)' to execute.$(RESET)"

%.o: %.c push_swap.h
	@$(PRINT_LOADING)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo " "

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(PUSH_SWAP)

re: fclean all

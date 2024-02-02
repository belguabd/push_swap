CC = cc

PUSH_SWAP = push_swap
NAME_BONUS = checker

CFLAGS = -Wall -Wextra -Werror

RULES = rules
RULES_BONUS = rules_bonus
UTILS = utils
PARSING=parsing
SORT=sort
DISPLAY=display
GET_NEXT_LINE=get_next_line_bonus
BONUS=bonus

RM = rm -rf

SRC=push_swap.c\
	$(PARSING)/parsing.c \
	$(UTILS)/ft_split.c $(UTILS)/ft_lstsize.c  $(UTILS)/ft_lstadd_end.c $(UTILS)/ft_addnew_nbr.c $(UTILS)/ft_strlen.c $(UTILS)/ft_free.c\
	$(RULES)/push.c $(RULES)/swap.c $(RULES)/rotate.c $(RULES)/reverse_rotate.c \
	$(SORT)/sort_normal.c $(SORT)/sort_big.c $(SORT)/sort_big_utils.c $(SORT)/sort_normal_utils.c\


SRC_BONUS=ft_bonus.c \
	$(PARSING)/parsing.c \
	$(GET_NEXT_LINE)/get_next_line.c $(GET_NEXT_LINE)/get_next_line_utils.c \
	$(UTILS)/ft_split.c $(UTILS)/ft_lstsize.c  $(UTILS)/ft_lstadd_end.c $(UTILS)/ft_addnew_nbr.c $(UTILS)/ft_strlen.c $(UTILS)/ft_free.c\
	$(RULES_BONUS)/push.c $(RULES_BONUS)/swap.c $(RULES_BONUS)/rotate.c $(RULES_BONUS)/reverse_rotate.c \

OBJB = $(SRC_BONUS:.c=.o)
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


bonus:$(OBJB)
	@$(CC) $(CFLAGS) $(OBJB) -o $(NAME_BONUS)
	@echo "$(GREEN)Run './$(NAME_BONUS)' to execute.$(RESET)"

%.o: %.c push_swap.h
	@$(PRINT_LOADING)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo " "


clean:
	@$(PRINT_LOADING)
	@$(RM) $(OBJ) $(OBJB)
	@echo "$(GREEN)Clean complete.$(RESET)"

fclean: clean
	@$(PRINT_LOADING)
	@$(RM) $(PUSH_SWAP) $(NAME_BONUS)
	@echo "$(GREEN)Full Clean complete.$(RESET)"
re: fclean all 
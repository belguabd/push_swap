CC = cc
PUSH_SWAP = push_swap
CFLAGS = -Wall -Wextra -Werror  -g
RULES=rules

RM =rm -rf

SRC = push_swap.c parsing.c ft_split.c $(RULES)/push.c $(RULES)/swap.c $(RULES)/rotate.c 
OBJ = $(SRC:.c=.o)

all: $(PUSH_SWAP)


$(PUSH_SWAP): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(PUSH_SWAP)


clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(PUSH_SWAP)

re: fclean all
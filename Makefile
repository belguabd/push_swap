CC = cc
PUSH_SWAP = push_swap
CFLAGS = -Wall -Wextra -Werror  -g
RM =rm -rf

SRC = push_swap.c ft_atoi.c ft_split.c
OBJ = $(SRC:.c=.o)


all: $(PUSH_SWAP)


$(PUSH_SWAP): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(PUSH_SWAP)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(PUSH_SWAP)

re: fclean all
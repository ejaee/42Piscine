CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

HEADER = includes
SRC_DIR = srcs
SRC = $(SRC_DIR)/ft_putnbr.c \
$(SRC_DIR)/define_op.c \
$(SRC_DIR)/main.c \
$(SRC_DIR)/ft_op.c \
$(SRC_DIR)/ft_putstr.c \
$(SRC_DIR)/ft_atoi.c
OBJ = $(SRC:.c=.o)
NAME = do-op

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $@ -I $(HEADER)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

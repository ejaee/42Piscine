CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs
HEADER = includes
RM = rm -f
SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/hexdump.c $(SRC_DIR)/hexdump_detail.c $(SRC_DIR)/utility.c
OBJECTS = $(SOURCES:.c=.o)
NAME = ft_hexdump

all:	$(NAME)

$(NAME):
	$(CC) $(CFALGS) $(SOURCES) -o $@ -I $(HEADER)

clean:
	$(RM) $(ObJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs
HEADER = includes
RM = rm -f
SOURCES = $(SRC_DIR)/main.c \
$(SRC_DIR)/display_file.c \
$(SRC_DIR)/ft_putstr.c \
$(SRC_DIR)/count_file_size.c \
$(SRC_DIR)/ft_atoi.c
OBJECTS = $(SOURCES:.c=.o)
NAME = ft_tail

all:    $(NAME)

$(NAME):
	$(CC) $(CFALGS) $(SOURCES) -o $@ -I $(HEADER)
clean:
	$(RM) $(ObJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

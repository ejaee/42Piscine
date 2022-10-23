.SUFFIXES = .c .o
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
RM = rm -f

SRC_DIR = srcs
HEADER = includes

SOURCES = $(SRC_DIR)/ft_putchar.c \
$(SRC_DIR)/ft_swap.c \
$(SRC_DIR)/ft_putstr.c \
$(SRC_DIR)/ft_strlen.c \
$(SRC_DIR)/ft_strcmp.c
OBJECTS = $(SOURCES:.c=.o)

TARGET = libft.a

all : $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(HEADER)

$(TARGET) : $(OBJECTS) 
	ar -rc $@ $(OBJECTS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

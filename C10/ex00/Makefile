# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 19:20:59 by choiejae          #+#    #+#              #
#    Updated: 2022/02/16 23:51:21 by choiejae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES = .c .o
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_DIR = srcs
HEADER = includes

SOURCES = $(SRC_DIR)/ft_display_file.c
OBJECTS = $(SOURCES:.c=.o)

TARGET = ft_display_file

all : $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(SOURCES) -o $@ -I $(HEADER)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 00:12:21 by choiejae          #+#    #+#              #
#    Updated: 2022/02/17 19:04:19 by choiejae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

HEADER = includes

SRC = ft_cat.c
OBJS = $(SRC:.c=.o)

TARGET = ft_cat

all : $(TARGET)

$(TARGET) :
	$(CC) $(CFLAGS) $(SRC) -o $@ -I $(HEADER)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(TARGET)

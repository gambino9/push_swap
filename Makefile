# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 22:05:27 by lboukrou          #+#    #+#              #
#    Updated: 2019/11/12 20:20:22 by lboukrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	checker
CC				=	gcc
CFLAGS			=	-Werror -Wall -Wextra
LIB_PATH		=	libft
LIB				=	$(LIB_PATH)/libft.a

INC_DIR			=	includes
INCS			=	-I $(INC_DIR) -I $(LIB_PATH)

SRC_DIR			=	srcs
SRC				=	checker.c \
					error.c \
					parsing_arg.c \
					parsing_cmds.c \
					push.c \
					reverse_rotate.c \
					rotate.c \
					swap.c \
					utility.c \
					algo.c \
					quicksort.c \
					push_swap.c \
					median.c

OBJ_DIR			=	obj

SRCS			=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJS			=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


all: $(NAME)

$(NAME): obj $(LIB) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIB)

obj:
	mkdir obj

$(LIB):
	make -C $(LIB_PATH)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCS) -c -o $@ $<

clean:
	make -C $(LIB_PATH) clean
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
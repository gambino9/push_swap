# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 22:05:27 by lboukrou          #+#    #+#              #
#    Updated: 2019/11/20 20:07:17 by lboukrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	both
NAME_1			=	checker
NAME_2			=	push_swap
CC				=	gcc
CFLAGS			=	-Werror -Wall -Wextra
LIB_PATH		=	libft
LIB				=	$(LIB_PATH)/libft.a

INC_DIR			=	includes
INCS			=	-I $(INC_DIR) -I $(LIB_PATH)

SRC_DIR			=	srcs
SRC_CHECKER		=	checker.c 
SRC_PUSH_SWAP	=	push_swap.c \
					quicksort.c \
					sort_tiny_list.c \
					median.c \
					optimization.c \
					optimization_utils.c
SRC_BOTH		=	error.c \
					parsing_arg.c \
					parsing_cmds.c \
					push.c \
					reverse_rotate.c \
					rotate.c \
					swap.c \
					utils_list.c \
					utils.c

OBJ_DIR			=	obj

SRCS_BOTH		=	$(addprefix $(SRC_DIR)/, $(SRC_BOTH))
SRCS_CHECKER	=	$(addprefix $(SRC_DIR)/, $(SRC_CHECKER))
SRCS_PUSH_SWAP	=	$(addprefix $(SRC_DIR)/, $(SRC_PUSH_SWAP))

OBJS_BOTH		=	$(addprefix $(OBJ_DIR)/, $(SRC_BOTH:.c=.o))
OBJS_CHECKER	=	$(addprefix $(OBJ_DIR)/, $(SRC_CHECKER:.c=.o))
OBJS_PUSH_SWAP	=	$(addprefix $(OBJ_DIR)/, $(SRC_PUSH_SWAP:.c=.o))

all: $(NAME)

$(NAME): $(NAME_1) $(NAME_2)

$(NAME_1): obj $(LIB) $(OBJS_CHECKER) $(OBJS_BOTH)
	$(CC) $(CFLAGS) -o $@ $(OBJS_CHECKER) $(OBJS_BOTH) $(LIB)

$(NAME_2): obj $(LIB) $(OBJS_PUSH_SWAP) $(OBJS_BOTH)
	$(CC) $(CFLAGS) -o $@ $(OBJS_PUSH_SWAP) $(OBJS_BOTH) $(LIB)

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
	rm -f $(NAME_1)
	rm -f $(NAME_2)

re: fclean all

.PHONY: both all clean fclean re
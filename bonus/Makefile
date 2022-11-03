# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 10:16:28 by jlima             #+#    #+#              #
#    Updated: 2022/06/10 10:35:47 by jlima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= checker

INCLUDES	= -I includes -I $(LIBFT_DIR)/includes/

LIBFT_DIR	= ../libft/

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
MAKE		= make

DIR_SRCS	= ./
DIR_OBJS	= objs/

SRCS_FILES	= checker push reverse_rotate rotate swap utils_1

OBJS 	= $(addprefix $(DIR_OBJS), $(addsuffix .o, $(SRCS_FILES)))

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_DIR)libft.a

$(DIR_OBJS)%.o :	$(DIR_SRCS)%.c
			@$(MAKE) -C $(LIBFT_DIR)
			@mkdir -p $(DIR_OBJS)
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
			rm -f $(OBJS)
			rm -r $(DIR_OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re

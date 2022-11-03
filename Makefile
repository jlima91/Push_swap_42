# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 08:48:15 by jlima             #+#    #+#              #
#    Updated: 2022/11/03 13:09:56 by jlima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#//= Colors =//#
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

NAME 		= push_swap

BONUS		= checker

INCLUDES	= -I includes -I $(LIBFT_DIR)includes/

LIBFT_DIR	= libft/
LIBFT_OBJS	= $(LIBFT_DIR)objs/

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
MAKE		= make

DIR_SRCS	= srcs/
DIR_OBJS	= objs/

DIR_BONUS	= bonus/
DIR_BO_OBJS	= bonus/objs/

SRCS_FILES	= push_swap push reverse_rotate rotate swap sort utils_1 utils_2 utils_3 utils_4

BONUS_FILES = checker push reverse_rotate rotate swap utils_1

OBJS		= $(addprefix $(DIR_OBJS), $(addsuffix .o, $(SRCS_FILES)))

BONUS_OBJS	= $(addprefix $(DIR_BONUS), $(addsuffix .o, $(BONUS_FILES)))

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(MAKE) -C $(LIBFT_DIR)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_DIR)libft.a
			@echo "$(YELLOW)$(BOLD)Library compiled!$(RESET)"
			@echo "$(MAGENTA)$(BOLD)Executable created!$(RESET)"

$(DIR_OBJS)%.o :	$(DIR_SRCS)%.c
			@mkdir -p $(DIR_OBJS)
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus:		$(BONUS_OBJS)
			@$(MAKE) -C $(LIBFT_DIR)
			@$(CC) $(CFLAGS) -o $(BONUS) $(BONUS_OBJS) $(LIBFT_DIR)libft.a
			@echo "$(YELLOW)$(BOLD)Library compiled!$(RESET)"
			@echo "$(MAGENTA)$(BOLD)Checker executable created!$(RESET)"

$(DIR_BO_OBJS)%.o :	$(DIR_BONUS)%.c
			@mkdir -p $(DIR_BO_OBJS)
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
			rm -f $(BONUS_OBJS)
			rm -rf $(DIR_OBJS)
			rm -rf $(LIBFT_OBJS)
			rm -rf $(DIR_BO_OBJS)

fclean:		clean
			rm -f $(NAME)
			rm -f $(BONUS)
			rm -f $(LIBFT_DIR)libft.a

re:			fclean all

.PHONY: 	all clean fclean re bonus

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/26 18:35:26 by mmensing          #+#    #+#              #
#    Updated: 2022/06/29 00:22:50 by mmensing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a
#define compiler and flags
CC= gcc 
CFLAGS= -Wall -Wextra -Werror
HEADER= ft_printf.h
#Source Functions for the library
MAND_SRC = ft_printf.c libft_funcs.c p_type.c u_type.c x_X_type.c c_s_type.c i_d_type.c
#BONUS_SRC = ft_lstmap.c
 
# The object files after compiling
MAND_OBS = $(MAND_SRC:%.c=%.o)

#BONUS_OBS = $(BONUS_SRC:%.c=%.o)

RM = rm -f

all: $(NAME)

$(NAME): $(MAND_OBS) $(HEADER)
	ar rcs $(NAME) $(MAND_OBS)

# later deleten !!-------
g: $(all)
	@gcc $(MAND_OBS)
	@./a.out
#------------------------

clean:
	$(RM) $(MAND_OBS) $(BONUS_OBS)

fclean: clean
	${RM} $(NAME)
	
#bonus: $(BONUS_OBS) $(HEADER)
#	ar rcs $(NAME) $(BONUS_OBS)

re: fclean all

.PHONY: all clean fclean re
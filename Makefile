# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshana <sshana@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 20:06:35 by sshana            #+#    #+#              #
#    Updated: 2022/05/18 16:29:44 by sshana           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		fdf

NAME_B		=		fdf_bonus

SRCS		=		fdf.c default.c draw_mod.c draw.c errors.c errors2.c ft_atoi.c ft_itoa.c ft_putstr_fd.c ft_split.c ft_strlen.c get_next_line.c get_next_line_utils.c keys.c take_parameters.c 

SRCS_B		=		fdf_bonus.c default.c draw_bonus.c draw_mod.c errors.c errors2.c ft_atoi.c ft_itoa.c ft_putstr_fd.c ft_split.c ft_strlen.c get_next_line.c get_next_line_utils.c keys_bonus.c keys_functions.c take_parameters.c

HEADER		=		fdf.h

OBJS		=		$(patsubst %.c, %.o, $(SRCS))

OBJS_B		=		$(patsubst %.c, %.o, $(SRCS_B))

D_FILES		=		$(patsubst %.c, %.d, $(SRCS))

D_FILES_B	=		$(patsubst %.c, %.d, $(SRCS_B))

CC			=		gcc

CFLAGS		=		-Wall -Werror -Wextra

OPENGL		=		-lmlx -framework OpenGL -framework AppKit

MLXLIBX		=		-L /usr/local/lib/ 

.PHONY		:		all clean fclean re 

all			:		$(NAME)	
				
bonus		:		$(NAME_B)

$(NAME)		:		$(OBJS)
					$(CC) ${OBJS} ${MLXLIBX} ${OPENGL} -o ${NAME}

$(NAME_B)	:		$(OBJS_B)
					$(CC) ${OBJS_B} ${OPENGL} -o ${NAME_B}					

%.o 		: 		%.c
					$(CC) $(CFLAGS) -c $< -o $@ -MD 	 			

include	$(wildcard $(D_FILES))
include	$(wildcard $(D_FILES_B))

clean		:
					rm -f $(OBJS)	$(D_FILES)
					rm -f $(OBJS_B)	$(D_FILES_B)
			
fclean		:		clean
					$(RM) $(NAME) $(NAME_B)

re			:		fclean all
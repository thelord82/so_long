# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malord <malord@student.42quebec.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 10:07:57 by malord            #+#    #+#              #
#    Updated: 2022/07/04 14:31:40 by malord           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
LIBFT		=	libft/libft.a

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -f

SRCS		=	so_long.c		\
				error_funcs.c	\
				moves_funcs.c	\
				moves_funcs2.c	\
				enemy_moves.c

OBJS		= 	${SRCS:.c=.o}

# Targets

.c.o:
				@$(CC) $(CFLAGS) -Imlx -c $< -o $(<:.c=.o)

$(NAME): 		$(OBJS)
				@echo "Compiling libft..."
				@$(MAKE) -C libft
				@echo "libft compiled successfully."
				@echo "Compiling $(NAME) sources"
				@$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) $(LIBFT)	
				@echo "Done !"

all: 			$(NAME)

# Removes objects
clean:
				@echo "Removing $(NAME) objects..."
				@$(RM) $(OBJS)
				@echo "Removing libft objects..."
				@make clean -C libft
				@echo "$(NAME) objects successfully deleted."
				@echo "libft objects successfully deleted."

# Removes objects and executable
fclean: 		clean
				@echo "Removing $(NAME) program..."
				@$(RM) $(NAME)
				@echo "Removing libft archive..."
				@$(RM) $(LIBFT)
				@echo "Executable(s) and archive(s) successfully deleted."

# Removes objects and executable then remakes all
re: 			fclean all
				
.PHONY:			all clean fclean bonus re				
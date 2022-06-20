# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malord <malord@student.42quebec.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 10:07:57 by malord            #+#    #+#              #
#    Updated: 2022/06/20 13:55:05 by malord           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
LIBFT		=	libft/libft.a

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -f

SRCS		=	so_long.c

OBJS		= 	${SRCS:.c=.o}

# Targets

.c.o:
				$(CC) $(CFLAGS) -Imlx -c $< -o $(<:.c=.o)

$(NAME): 		$(OBJS)
				$(MAKE) -C libft
				$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) $(LIBFT)	

all: 			$(NAME)

# Removes objects
clean:
				$(RM) $(OBJS)
				make clean -C libft

# Removes objects and executable
fclean: 		clean
				$(RM) $(NAME)
				$(RM) $(LIBFT)

# Removes objects and executable then remakes all
re: 			fclean all
				
.PHONY:			all clean fclean bonus re				
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkamal <bkamal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/09 00:15:39 by bkamal            #+#    #+#              #
#    Updated: 2022/10/18 19:52:38 by bkamal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fractol

BONUS	= fractol_bonus

SRCS   = ./srcm/fractol.c\
			./utils/calculations.c\
			./utils/fractals.c\
			./events/mouse.c\
			./events/close.c\
			./utils/misc.c\
			./utils/colours.c

SRCB   = ./srcb/fractol_bonus.c\
			./events_bonus/keyboard_bonus.c\
			./events_bonus/mouse_bonus.c\
			./utils/calculations.c\
			./utils/fractals.c\
			./events/close.c\
			./utils/misc.c\
			./utils/colours.c
			
OBJS   = $(SRCS:.c=.o)

OBJB   = $(SRCB:.c=.o)

CFLAGS = -Wall -Werror -Wextra

RM     = rm -f

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(BONUS): $(OBJB)
	$(CC) $(CFLAGS) $(OBJB) -lmlx -framework OpenGL -framework AppKit -o $(BONUS)

all: $(NAME) $(BONUS)

bonus: $(BONUS)

clean:
	$(RM) $(OBJS) $(OBJB)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lellong- < lellong-@student.42.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 12:50:26 by lellong-          #+#    #+#              #
#    Updated: 2022/11/29 20:18:11 by lellong-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c				\
				ft_printf_words.c			\
				ft_printf_numbers.c			\
				ft_printf_utils.c			\
				
		
OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:		
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:		
			${RM} ${OBJS} 

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		bonus all clean fclean re
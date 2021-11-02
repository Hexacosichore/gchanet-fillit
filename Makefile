# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/04 11:30:14 by gchanet           #+#    #+#              #
#    Updated: 2021/10/14 18:58:15 by gchanet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLU 		= \033[0;34m
GRN 		= \033[0;32m
RED 		= \033[0;31m
RST 		= \033[0m

SRCS		= main.c \
				parsing.c \
				resolve.c \
				utils.c \
				print.c
OBJS		= ${SRCS:.c=.o}
GCC			= gcc
GCC_FLAGS	= -Wall -Wextra -Werror -fsanitize=address -fdiagnostics-color 
NAME		= fillit

all: ${NAME}

.c.o:
	@${GCC} ${GCC_FLAGS} -c $< -o ${<:.c=.o}
	@echo "${BLU}[BUILD]${RST} ${<:.c=.o}"

${NAME}: ${OBJS}
	@${GCC} ${GCC_FLAGS} ${OBJS} -L../libft -lft -o ${NAME}
	@echo "${GRN}[DONE]${RST} ${NAME} has created"

clean:
	@rm -f *.o
	@echo "${GRN}[CLEAN]${RST} done"

fclean: clean
	@rm -f ${NAME}
	@echo "${GRN}[FCLEAN]${RST} done"

run: re
	@echo "${BLU}[RUN]${RST}"
	@time ./${NAME} extern_file.txt

re: fclean all
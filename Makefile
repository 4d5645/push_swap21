CFLAGS = -Wall -Wextra -Werror

HDR = pushswap.h

HDR_DIR = inc/

CC = cc

RM = rm -f

NAME = push_swap

SRC = lists.c pushswap_main.c initialization.c modified_comands.c basic_comands.c write_and_close.c sort_three.c

SRC_DIR = src/

LIBFT_NAME = libft.a

LIBFTDIR = ./libft/

LIBFT = $(addprefix ${LIBFTDIR}, ${LIBFT_NAME})

HEADERS = $(addprefix ${HDRS_DIR}, ${HDRS})

SOURCES = $(addprefix ${SRC_DIR}, ${SRC})

.PHONY:	clean all fclean re

all:	${LIBFT} ${NAME}

${LIBFT}:
	${MAKE} -C ${LIBFTDIR}

${NAME}:	${SOURCES} ${HEADERS} ${LIBFT}
	${CC} ${CFLAGS} ${SOURCES} -L ${LIBFTDIR} -lft -o $@

clean:
	${MAKE} clean -C ${LIBFTDIR}

fclean:		clean
	${RM} ${NAME}
	${MAKE} fclean -C ${LIBFTDIR}

re:	fclean all
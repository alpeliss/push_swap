SRCDIR	= ./srcs/
SRCNAME	= 	pile.c 			\
		init_pile.c		\
		operation.c

		SRCS	= ${addprefix ${SRCDIR}, ${SRCNAME}}

		INCDIR	=./includes/

		OBJS	= ${SRCS:.c=.o}

		NAME	= pile.a

		CC	= gcc
		RM	= rm -f

		CFLAGS	= -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -I ${INCDIR} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		ar rc ${NAME} ${OBJS}

all: 		${NAME}

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:		fclean all

c:		all clean

.PHONY:		clean fclean re all

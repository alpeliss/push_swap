LIBDIR		= pile
LIBNAME		= pile.a
LIBMAKE		= make -C $(LIBDIR)
LINC		= includes

CC		= gcc
CFLAGS		= -Wall -Wextra -Werror

PNAME		= push_swap
PDIR		= ./push/srcs/
PSRCNAMES	= 	main.c		\
			triple_tri.c	\
			utils.c		\
			insert.c	\
			medium_tri.c

PINC		= ./push/includes/
PSRC 		= $(addprefix $(PDIR), $(PSRCNAMES))
POBJ		= $(PSRC:.c=.o)


CNAME		= checker
CDIR		= ./check/srcs/
CSRCNAMES	= 	main.c		 \
			do_op.c

CINC 		= ./check/includes/
CSRC 		= $(addprefix $(CDIR), $(CSRCNAMES))
COBJ		= $(CSRC:.c=.o)

all:	$(PNAME) $(CNAME)

$(PNAME): $(POBJ)
	$(LIBMAKE) all
	$(CC) $(CFLAGS)  -o $(PNAME) $(POBJ) $(LIBDIR)/$(LIBNAME)

$(CNAME): $(COBJ)
	$(LIBMAKE) all
	$(CC) $(CFLAGS)  -o $(CNAME) $(COBJ) $(LIBDIR)/$(LIBNAME)


.c.o:
	${CC} ${CFLAGS} -I ${PINC} -I ${CINC} -I $(LIBDIR)/$(LINC) -c $<  -o ${<:.c=.o}

clean:
	$(LIBMAKE) clean
	$(RM) $(COBJ)
	$(RM) $(POBJ)

fclean:	clean
	$(LIBMAKE) fclean
	$(RM) $(CNAME)
	$(RM) $(PNAME)

push:	$(PNAME)

check:	$(CNAME)

re:	fclean all

.PHONY:	all clean fclean re push check

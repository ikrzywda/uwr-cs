CC = gcc
SRC = rational.c main.c
LIBS = -lm
FLAGS = -xc -std=c11 -Wall -Wextra -Werror 
FLAGS_DEBUG = -xc -std=c11 -Wall -Wextra
OUT = out

build:
	${CC} -o ${OUT} ${LIBS} ${FLAGS} ${SRC}
debug:
	${CC} -o ${OUT} ${LIBS} ${FLAGS_DEBUG} ${SRC}
run:
	./${OUT} ${ARGS}
clean:
	rm ${OUT}

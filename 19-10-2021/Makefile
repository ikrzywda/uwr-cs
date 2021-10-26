CC = gcc
SRC = base_conversion.c
LIBS = -lm
FLAGS = -xc -std=c11 -Wall -Wextra -Werror 
OUT = out

build:
	${CC} -o ${OUT} ${LIBS} ${FLAGS} ${SRC}
run:
	./${OUT} ${ARGS}
clean:
	rm ${OUT}

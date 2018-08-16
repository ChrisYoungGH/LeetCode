CC:=g++

UTIL_DIR:=utils
TEST_DIR:=${DIR}

SRCS:=$(wildcard ${UTIL_DIR}/*.cc) $(wildcard ${TEST_DIR}/*.cc)
OBJS:=${SRCS:.cc=.o}

TARGET:=leetcode

CFLAGS:=-std=c++11 -I${UTIL_DIR}

all: ${TARGET}

${TARGET}: ${OBJS}
	${CC} ${CFLAGS} $^ -o $@

%.o: %.cc
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${TARGET} ${OBJS}
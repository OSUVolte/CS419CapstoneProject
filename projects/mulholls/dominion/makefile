CXX = gcc
CXXFLAGS = -std=c99
CXXFLAGS += -Wall
CXXFLAGS += -g
CXXFLAGS += -pedantic-errors


SRC1 = 
SRC2 = 
SRC3 = 
SRCS = ${SRC1} ${SRC2} ${SRC3}

OBJ1 = 
OBJ2 = 
OBJ3 = 
OBJS = ${OBJ1} ${OBJ2} ${OBJ3}

HDR1 = 
HDR2 = 
HRDS = ${HRD1} ${HDR2}

PROG = 

default: dominion rngs unittest1 unittest2 unittest3 unittest4
	./unittest1 > unittestresults.out
	./unittest2 >> unittestresults.out
	./unittest3 >> unittestresults.out
	./unittest4 >> unittestresults.out

dominion: dominion.c
	${CXX} ${CXXFLAGS} dominion.c -c -coverage 

rngs: rngs.c
	${CXX} ${CXXFLAGS} rngs.c -c -coverage 

unitTestLib: unitTestLib.c
	${CXX} ${CXXFLAGS} unitTestLib.c -lm -c

unittest1: unittest1.c unitTestLib
	${CXX} ${CXXFLAGS} unittest1.c rngs.o dominion.o unitTestLib.o -lm -coverage -o unittest1

unittest2: unittest2.c unitTestLib
	${CXX} ${CXXFLAGS} unittest2.c rngs.o dominion.o unitTestLib.o -lm -coverage -o unittest2

unittest3: unittest3.c unitTestLib
	${CXX} ${CXXFLAGS} unittest3.c rngs.o dominion.o unitTestLib.o -lm -coverage -o unittest3

unittest4: unittest4.c unitTestLib dominion.o
	${CXX} ${CXXFLAGS} unittest4.c rngs.o dominion.o unitTestLib.o -lm -coverage -o unittest4

	
clean:
	rm -f  *.o *~ *.gch  ${PROG}

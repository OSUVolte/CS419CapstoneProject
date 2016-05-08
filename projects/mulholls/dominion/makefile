CXX = gcc
CXXFLAGS = -std=c99
CXXFLAGS += -Wall
CXXFLAGS += -g
CXXFLAGS += -pedantic-errors

default: 
	echo "Please enter a target: unittestresults.out, randomtestcard.out, randomtestadventure.out"

randomtestcard.out: randCard
	./randCard  1234 > randomtestcard.out

randCard: randomtestcard.c rngs unitTestLib dominion
	gcc randomtestcard.c unitTestLib.o rngs.o dominion.o -lm -coverage -o randCard

randomtestadventurer.out: randAdv
	./randAdv  1234 > randomtestadventurer.out

randAdv: randomtestadventurer.c rngs unitTestLib dominion
	gcc randomtestadventurer.c unitTestLib.o rngs.o dominion.o -lm -coverage -o randAdv

unittests: dominion rngs unitTestLib unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4

unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	./unittest1 > unittestresults.out
	./unittest2 >> unittestresults.out
	./unittest3 >> unittestresults.out
	./unittest4 >> unittestresults.out
	./cardtest1 >> unittestresults.out
	./cardtest2 >> unittestresults.out
	./cardtest3 >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov unittest1.c -b >> unittestresults.out
	gcov unittest2.c -b >> unittestresults.out
	gcov unittest3.c -b >> unittestresults.out
	gcov unittest4.c -b >> unittestresults.out
	gcov cardtest1.c -b >> unittestresults.out
	gcov cardtest2.c -b >> unittestresults.out
	gcov cardtest3.c -b >> unittestresults.out
	gcov cardtest4.c -b >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
dominion: dominion.c
	${CXX} ${CXXFLAGS} dominion.c -c -coverage 

rngs: rngs.c
	${CXX} ${CXXFLAGS} rngs.c -c -coverage 

unitTestLib: unitTestLib.c
	${CXX} ${CXXFLAGS} unitTestLib.c -lm -c

unittest1: unittest1.c dominion rngs unitTestLib
	${CXX} ${CXXFLAGS} unittest1.c rngs.o dominion.o unitTestLib.o -lm -coverage -o unittest1

unittest2: unittest2.c dominion rngs unitTestLib
	${CXX} ${CXXFLAGS} unittest2.c rngs.o dominion.o unitTestLib.o -lm -coverage -o unittest2

unittest3: unittest3.c dominion rngs unitTestLib
	${CXX} ${CXXFLAGS} unittest3.c rngs.o dominion.o unitTestLib.o -lm -coverage -o unittest3

unittest4: unittest4.c dominion rngs unitTestLib 
	${CXX} ${CXXFLAGS} unittest4.c rngs.o dominion.o unitTestLib.o -lm -coverage -o unittest4

cardtest1: cardtest1.c dominion rngs unitTestLib
	${CXX} ${CXXFLAGS} cardtest1.c rngs.o dominion.o unitTestLib.o -lm -coverage -o cardtest1

cardtest2: cardtest2.c dominion rngs unitTestLib
	${CXX} ${CXXFLAGS} cardtest2.c rngs.o dominion.o unitTestLib.o -lm -coverage -o cardtest2

cardtest3: cardtest3.c dominion rngs unitTestLib
	${CXX} ${CXXFLAGS} cardtest3.c rngs.o dominion.o unitTestLib.o -lm -coverage -o cardtest3

cardtest4: cardtest4.c unitTestLib dominion.o
	${CXX} ${CXXFLAGS} cardtest4.c rngs.o dominion.o unitTestLib.o -lm -coverage -o cardtest4	
clean:
	rm  *.o *.c.gcov *.gcda *.gcno randCard randAdv unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 unittestresults.out

CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

unittest1: dominion.o rngs.o unittest1.c
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)

unittest2: dominion.o rngs.o unittest2.c
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)

unittest3: dominion.o rngs.o unittest3.c
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)

unittest4: dominion.o rngs.o unittest4.c
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)

cardtest1: dominion.o rngs.o cardtest1.c
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)

cardtest2: dominion.o rngs.o cardtest2.c
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)

cardtest3: dominion.o rngs.o cardtest3.c
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)

cardtest4: dominion.o rngs.o cardtest4.c
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)

unitcardtests: unittest1 unittest2 unittest3 unittest3 cardtest1 cardtest2 cardtest3 cardtest4
	unittest1 >> unittestresults.out
	gcov -b unittest1.c >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	unittest2 >> unittestresults.out
	gcov -b unittest2.c >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	unittest3 >> unittestresults.out
	gcov -b unittest3.c >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	unittest4 >> unittestresults.out
	gcov -b unittest4.c >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	cardtest1 >> unittestresults.out
	gcov -b cardtest1.c >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	cardtest2 >> unittestresults.out
	gcov -b cardtest2.c >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	cardtest3 >> unittestresults.out
	gcov -b cardtest3.c >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	cardtest4 >> unittestresults.out
	gcov -b cardtest4.c >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so

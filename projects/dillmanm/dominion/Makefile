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

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

unittestresults.out: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.o rngs.o dominion.h dominion_helpers.h
	gcc -c dominion.c -g $(CFLAGS)
	gcc -c unittest1.c -g $(CFLAGS)
	gcc -c unittest2.c -g $(CFLAGS)
	gcc -c unittest3.c -g $(CFLAGS)
	gcc -c unittest4.c -g $(CFLAGS)
	gcc -c cardtest1.c -g $(CFLAGS)
	gcc -c cardtest2.c -g $(CFLAGS)
	gcc -c cardtest3.c -g $(CFLAGS)
	gcc -c cardtest4.c -g $(CFLAGS)
	gcc -o unittest1 -g dominion.o unittest1.o rngs.o $(CFLAGS)
	gcc -o unittest2 -g dominion.o unittest2.o rngs.o $(CFLAGS)
	gcc -o unittest3 -g dominion.o unittest3.o rngs.o $(CFLAGS)
	gcc -o unittest4 -g dominion.o unittest4.o rngs.o $(CFLAGS)
	gcc -o cardtest1 -g dominion.o cardtest1.o rngs.o $(CFLAGS)
	gcc -o cardtest2 -g dominion.o cardtest2.o rngs.o $(CFLAGS)
	gcc -o cardtest3 -g dominion.o cardtest3.o rngs.o $(CFLAGS)
	gcc -o cardtest4 -g dominion.o cardtest4.o rngs.o $(CFLAGS)
	unittest1 &> unittestresults.out
	unittest2 >> unittestresults.out
	unittest3 >> unittestresults.out
	unittest4 >> unittestresults.out
	cardtest1 >> unittestresults.out
	cardtest2 >> unittestresults.out
	cardtest3 >> unittestresults.out
	cardtest4 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so

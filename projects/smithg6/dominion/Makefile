CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: unittestresults.out
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

all: playdom player testDrawCard testBuyCard badTestDrawCard

unittestresults.out: unittest1.c  unittest2.c unittest3.c unittest4.c dominion.c rngs.c interface.c 
	echo "Result for running tests:" > unittestresults.out
	
	echo "unittest1.c:" >> unittestresults.out
	gcc -o unittest1 dominion.c rngs.c interface.c unittest1.c -lm $(CFLAGS)
	unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "unittest2.c:" >> unittestresults.out
	gcc -o unittest2 dominion.c rngs.c interface.c unittest2.c -lm $(CFLAGS)	
	unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "unittest3.c:" >> unittestresults.out
	gcc -o unittest3 dominion.c rngs.c interface.c unittest3.c -lm $(CFLAGS)
	unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "unittest4.c:" >> unittestresults.out
	gcc -o unittest4 dominion.c rngs.c interface.c unittest4.c -lm $(CFLAGS)
	unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	rm -f *.o playdom.exe unittestresults.out playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so

cleanall:
	rm unittestresults.out unittest1 unittest2 unittest3 unittest4 cardtest1.c cardtest2.c cardtest3.c cardtest4.c *.gcda *.gcno *.gcov
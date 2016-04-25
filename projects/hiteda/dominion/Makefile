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
	
unittests: unittest1.c unittest2.c dominion.c
	gcc -o unittest1 unittest1.c dominion.c rngs.c $(CFLAGS)
	echo "unittest1" > unittestresult.out
	unittest1 >> unittestresult.out
	gcov -b dominion.c >> unittestresult.out
	gcc -o unittest2 unittest2.c dominion.c rngs.c $(CFLAGS)
	echo "-----------------------------------------------------------" >> unittestresult.out
	echo "unittest2" >> unittestresult.out
	unittest2 >> unittestresult.out
	gcov -b dominion.c >> unittestresult.out
	gcc -o unittest3 unittest3.c dominion.c rngs.c $(CFLAGS)
	echo "-----------------------------------------------------------" >> unittestresult.out
	echo "unittest3" >> unittestresult.out
	unittest3 >> unittestresult.out
	gcov -b dominion.c >> unittestresult.out
	gcc -o unittest4 unittest4.c dominion.c rngs.c $(CFLAGS)
	echo "-----------------------------------------------------------" >> unittestresult.out
	echo "unittest4" >> unittestresult.out
	unittest4 >> unittestresult.out
	gcov -b dominion.c >> unittestresult.out
	gcc -o cardtest1 cardtest1.c dominion.c rngs.c $(CFLAGS)
	echo "-----------------------------------------------------------" >> unittestresult.out
	echo "cardtest1" >> unittestresult.out
	cardtest1 >> unittestresult.out
	gcov -b dominion.c >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.out
	rm -f unittest1 unittest2 unittest3 unittest4 cardtest1

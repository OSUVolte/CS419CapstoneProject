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
	
unittestresults.out: cardtest1.c  cardtest2.c cardtest3.c unittest1.c unittest2.c dominion.c rngs.o interface.o
	echo "UNIT AND CARD TEST RESULTS:" > unittestresults.out
	
	gcc -o unittest1 unittest1.c -g dominion.c rngs.o interface.o $(CFLAGS)
	unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	gcc -o unittest2 unittest2.c -g dominion.c rngs.o $(CFLAGS)
	unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	gcc -o cardtest1 cardtest1.c -g dominion.c rngs.o interface.o $(CFLAGS)
	cardtest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	gcc -o cardtest2 cardtest2.c -g dominion.c rngs.o interface.o $(CFLAGS)
	cardtest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	gcc -o cardtest3 cardtest3.c -g dominion.c rngs.o interface.o $(CFLAGS)
	cardtest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

all: playdom player testDrawCard testBuyCard badTestDrawCard unittestresults.out

clean:
	rm -f *.o unittestresults.out.exe unittestresults.out playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so

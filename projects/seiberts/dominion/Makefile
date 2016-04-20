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

all: playdom player testDrawCard testBuyCard badTestDrawCard cardtest1 cardtest2 cardtest3 cardtest4 unittest1 unittest2 unittest3 unittest4

cardtest1:
	gcc cardtest1.c dominion.c rngs.c -o cardtest1 -lm $(CFLAGS)

cardtest2: 
	gcc cardtest2.c dominion.c rngs.c -o cardtest2 -lm $(CFLAGS)
	
cardtest3: 
	gcc cardtest3.c dominion.c rngs.c -o cardtest3 -lm $(CFLAGS)

cardtest4: 
	gcc cardtest4.c dominion.c rngs.c -o cardtest4 -lm $(CFLAGS)

unittest1:
	gcc unittest1.c dominion.c rngs.c -o unittest1 -lm $(CFLAGS)

unittest2:
	gcc unittest2.c dominion.c rngs.c -o unittest2 -lm $(CFLAGS)

unittest3:
	gcc unittest3.c dominion.c rngs.c -o unittest3 -lm $(CFLAGS)

unittest4:
	gcc unittest4.c dominion.c rngs.c -o unittest4 -lm $(CFLAGS)
	
clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4

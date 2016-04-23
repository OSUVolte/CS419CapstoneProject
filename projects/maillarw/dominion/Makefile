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

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so unittest[1-4] cardtest[1-4]

unit1:
	gcc -std=c99 dominion.c unittest1.c rngs.c -o unittest1 -lm
unit2:
	gcc -std=c99 dominion.c unittest2.c rngs.c -o unittest2 -lm
unit3:
	gcc -std=c99 dominion.c unittest3.c rngs.c -o unittest3 -lm
unit4:
	gcc -std=c99 dominion.c unittest4.c rngs.c -o unittest4 -lm
card1:
	gcc -std=c99 dominion.c cardtest1.c rngs.c -o cardtest1 -lm
card2:
	gcc -std=c99 dominion.c cardtest2.c rngs.c -o cardtest2 -lm
card3:
	gcc -std=c99 dominion.c cardtest3.c rngs.c -o cardtest3 -lm
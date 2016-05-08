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

unit: 
	gcc -o unit1 unittest1.c dominion.c rngs.c -lm
	gcc -o unit2 unittest2.c dominion.c rngs.c -lm
	gcc -o unit3 unittest3.c dominion.c rngs.c -lm
	gcc -o unit4 unittest4.c dominion.c rngs.c -lm

card:
	gcc -o card1 cardtest1.c dominion.c rngs.c -lm
	gcc -o card2 cardtest2.c dominion.c rngs.c -lm
	gcc -o card3 cardtest3.c dominion.c rngs.c -lm
	gcc -o card4 cardtest4.c dominion.c rngs.c -lm

randTestAdventurer:
	gcc -o randTestAdventurer randomtestadventurer.c dominion.c rngs.c -lm
	./randTestAdventurer &> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

randTestCard:
	gcc -o randTestCard randomtestcard.c dominion.c rngs.c -lm	 
	./randTestCard &> randomtestcard.out
	gcov dominion.c >> randomtestcard.out
	cat dominion.c.gcov >> randomtestcard.out

myTest:
	./unit1 &> unittestresult.out
	./unit2 >> unittestresult.out
	./unit3 >> unittestresult.out
	./unit4 >> unittestresult.out
	./cardtest1 >> unittestresult.out
	./cardtest2 >> unittestresult.out
	./cardtest3 >> unittestresult.out
	./cardtest4 >> unittestresult.out
	gcov dominion.c -b >> unittestresult.out	
	
player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so

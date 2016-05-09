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

test: unit1 unit2 unit3 unit4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestadventurer randomtestcard
	./unit1 &> unittestresult.out
	gcov unittest1.c -b >> unittestresult.out
	gcov dominion.c -b >> unittestresult.out
	./unit2 >> unittestresult.out
	gcov unittest2.c -b >> unittestresult.out
	gcov dominion.c -b >> unittestresult.out
	./unit3 >> unittestresult.out
	gcov unittest3.c -b >> unittestresult.out
	gcov dominion.c -b >> unittestresult.out
	./unit4 >> unittestresult.out
	gcov unittest4.c -b >> unittestresult.out
	gcov dominion.c -b >> unittestresult.out
	./cardtest1 >> unittestresult.out
	gcov cardtest1.c -b >> unittestresult.out
	gcov dominion.c -b >> unittestresult.out
	./cardtest2 >> unittestresult.out
	gcov cardtest2.c -b >> unittestresult.out
	gcov dominion.c -b >> unittestresult.out
	./cardtest3 >> unittestresult.out
	gcov cardtest3.c -b >> unittestresult.out
	gcov dominion.c -b >> unittestresult.out
	./cardtest4 >> unittestresult.out
	gcov cardtest4.c -b >> unittestresult.out
	gcov dominion.c -b >> unittestresult.out
	./randomtestadventurer >> randomtestadventurer.out
	gcov randomtestadventurer.c -b >> randomtestadventurer.out
	gcov dominion.c -b >> randomtestadventurer.out
	./randomtestcard >> randomtestcard.out
	gcov randomtestcard.c -b >> randomtestcard.out
	gcov dominion.c -b >> randomtestcard.out

testrandom: randomtestadventurer randomtestcard
	./randomtestadventurer >> randomtestadventurer.out
	gcov randomtestadventurer.c -b >> randomtestadventurer.out
	gcov dominion.c -b >> randomtestadventurer.out
	./randomtestcard >> randomtestcard.out
	gcov randomtestcard.c -b >> randomtestcard.out
	gcov dominion.c -b >> randomtestcard.out
    
player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

unittest1.o: unittest1.c unittest1.o dominion.o rngs.o
	gcc -c unittest1.c -g $(CFLAGS)

unit1: unittest1.c unittest1.o dominion.o rngs.o
	gcc -o unit1 unittest1.c -g dominion.o rngs.o $(CFLAGS)

unittest2.o: unittest2.c unittest2.o dominion.o rngs.o
	gcc -c unittest2.c -g $(CFLAGS)

unit2: unittest2.c unittest2.o dominion.o rngs.o
	gcc -o unit2 unittest2.c -g dominion.o rngs.o $(CFLAGS)

unittest3.o: unittest3.c unittest3.o dominion.o rngs.o
	gcc -c unittest3.c -g $(CFLAGS)

unit3: unittest3.c unittest3.o dominion.o rngs.o
	gcc -o unit3 unittest3.c -g dominion.o rngs.o $(CFLAGS)

unittest4.o: unittest4.c unittest4.o dominion.o rngs.o
	gcc -c unittest4.c -g $(CFLAGS)

unit4: unittest4.c unittest4.o dominion.o rngs.o
	gcc -o unit4 unittest4.c -g dominion.o rngs.o $(CFLAGS)

cardtest1.o: cardtest1.c cardtest1.o dominion.o rngs.o
	gcc -c cardtest1.c -g $(CFLAGS)

cardtest1: cardtest1.c cardtest1.o dominion.o rngs.o
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)

cardtest2.o: cardtest2.c cardtest2.o dominion.o rngs.o
	gcc -c cardtest2.c -g $(CFLAGS)

cardtest2: cardtest2.c cardtest2.o dominion.o rngs.o
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)

cardtest3.o: cardtest3.c cardtest3.o dominion.o rngs.o
	gcc -c cardtest3.c -g $(CFLAGS)

cardtest3: cardtest3.c cardtest3.o dominion.o rngs.o
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)

cardtest4.o: cardtest4.c cardtest4.o dominion.o rngs.o
	gcc -c cardtest4.c -g $(CFLAGS)

cardtest4: cardtest4.c cardtest4.o dominion.o rngs.o
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)

randomtestcard.o: randomtestcard.c randomtestcard.o dominion.o rngs.o
	gcc -c randomtestcard.c -g $(CFLAGS)

randomtestcard: randomtestcard.c randomtestcard.o dominion.o rngs.o
	gcc -o randomtestcard randomtestcard.c -g dominion.o rngs.o $(CFLAGS)

randomtestadventurer.o: randomtestadventurer.c randomtestadventurer.o dominion.o rngs.o
	gcc -c randomtestadventurer.c -g $(CFLAGS)

randomtestadventurer: randomtestadventurer.c randomtestadventurer.o dominion.o rngs.o
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard unit1 unit2 unit3 unit4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestcard randomtestadventurer

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so

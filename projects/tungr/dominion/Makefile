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

unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
	
unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)
	
cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)
	
cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)
	
cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)
	
cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)

randomtestcard: randomtestcard.c dominion.o rngs.o
	gcc -o randomtestcard randomtestcard.c -g dominion.o rngs.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)

randomtestadventurer.out: dominion.o randomtestadventurer rngs.o
	echo "* * * * * * * * * * * RANDOMTESTADVENTURER * * * * * * * * * * *" &> randomtestadventurer.out
	./randomtestadventurer >> randomtestadventurer.out
		gcov randomtestadventurer.c >> randomtestadventurer.out
		gcov randomtestadventurer.c -b >> randomtestadventurer.out
	echo "* * * * * * * * * * * DOMINION * * * * * * * * * * *" >> randomtestadventurer.out
		gcov dominion.c >> randomtestadventurer.out
		gcov dominion.c -b >> randomtestadventurer.out
	echo "* * * * * * * * * * * DOMINION1 * * * * * * * * * * *" >> randomtestadventurer.out
		gcov -f -b dominion.c >> randomtestadventurer.out

randomtestcard.out: dominion.o randomtestcard rngs.o
	echo "* * * * * * * * * * *  RANDOMTESTADVENTURER * * * * * * * * * * *" &> randomtestcard.out
	./randomtestcard >> randomtestcard.out
		gcov randomtestcard.c >> randomtestcard.out
		gcov randomtestcard.c -b >> randomtestcard.out
	echo "* * * * * * * * * * * DOMINION * * * * * * * * * * *" >> randomtestcard.out
		gcov dominion.c >> randomtestcard.out
		gcov dominion.c -b >> randomtestcard.out
	echo "* * * * * * * * * * * DOMINION1 * * * * * * * * * * *" >> randomtestcard.out
		gcov -f -b dominion.c >> randomtestcard.out

unittestresults.out: dominion.o unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 rngs.o
	echo "* * * * * * * * * * * UNITTEST1 * * * * * * * * * * *" &> unittestresults.out
	./unittest1 >> unittestresults.out
		gcov unittest1.c >> unittestresults.out
		gcov unittest1.c -b >> unittestresults.out
	echo "* * * * * * * * * * * UNITTEST2 * * * * * * * * * * *" >> unittestresults.out
	./unittest2 >> unittestresults.out
		gcov unittest2.c >> unittestresults.out
		gcov unittest2.c -b >> unittestresults.out
	echo "* * * * * * * * * * * UNITTEST3 * * * * * * * * * * *" >> unittestresults.out
	./unittest3 >> unittestresults.out
		gcov unittest3.c >> unittestresults.out
		gcov unittest3.c -b >> unittestresults.out
	echo "* * * * * * * * * * * UNITTEST4 * * * * * * * * * * *" >> unittestresults.out
	./unittest4 >> unittestresults.out
		gcov unittest4.c >> unittestresults.out
		gcov unittest4.c -b >> unittestresults.out
	echo "* * * * * * * * * * * CARDTEST1 * * * * * * * * * * *" >> unittestresults.out
	./cardtest1 >> unittestresults.out
		gcov cardtest1.c >> unittestresults.out
		gcov cardtest1.c -b >> unittestresults.out
	echo "* * * * * * * * * * * CARDTEST2 * * * * * * * * * * *" >> unittestresults.out
	./cardtest2 >> unittestresults.out
		gcov cardtest2.c >> unittestresults.out
		gcov cardtest2.c -b >> unittestresults.out
	echo "* * * * * * * * * * * CARDTEST3 * * * * * * * * * * *" >> unittestresults.out
	./cardtest3 >> unittestresults.out
		gcov cardtest3.c >> unittestresults.out
		gcov cardtest3.c -b >> unittestresults.out
	echo "* * * * * * * * * * * CARDTEST4 * * * * * * * * * * *" >> unittestresults.out
	./cardtest4 >> unittestresults.out
		gcov cardtest4.c >> unittestresults.out
		gcov cardtest4.c -b >> unittestresults.out
	echo "* * * * * * * * * * * DOMINION * * * * * * * * * * *" >> unittestresults.out
		gcov dominion.c >> unittestresults.out
		gcov dominion.c -b >> unittestresults.out
	echo "* * * * * * * * * * * DOMINION1 * * * * * * * * * * *" >> unittestresults.out
		gcov -f -b dominion.c >> unittestresults.out

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so

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
	./testDrawCard &> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
unittestresults.out: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c dominion.c
	gcc -o unittest1 unittest1.c dominion.c rngs.c $(CFLAGS)
	echo "unittest1" > unittestresults.out
	unittest1 >> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	gcc -o unittest2 unittest2.c dominion.c rngs.c $(CFLAGS)
	echo "-----------------------------------------------------------" >> unittestresults.out
	echo "unittest2" >> unittestresults.out
	unittest2 >> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	gcc -o unittest3 unittest3.c dominion.c rngs.c $(CFLAGS)
	echo "-----------------------------------------------------------" >> unittestresults.out
	echo "unittest3" >> unittestresults.out
	unittest3 >> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	gcc -o unittest4 unittest4.c dominion.c rngs.c $(CFLAGS)
	echo "-----------------------------------------------------------" >> unittestresults.out
	echo "unittest4" >> unittestresults.out
	unittest4 >> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	gcc -o cardtest1 cardtest1.c dominion.c rngs.c $(CFLAGS)
	echo "-----------------------------------------------------------" >> unittestresults.out
	echo "cardtest1" >> unittestresults.out
	cardtest1 >> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	gcc -o cardtest2 cardtest2.c dominion.c rngs.c $(CFLAGS)
	echo "-----------------------------------------------------------" >> unittestresults.out
	echo "cardtest2" >> unittestresults.out
	cardtest2 >> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	gcc -o cardtest3 cardtest3.c dominion.c rngs.c $(CFLAGS)
	echo "-----------------------------------------------------------" >> unittestresults.out
	echo "cardtest3" >> unittestresults.out
	cardtest3 >> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	
randomtestadventurer.out: randomtestadventurer.c dominion.c rngs.c
	gcc -o randomtestadventurer randomtestadventurer.c dominion.c rngs.c $(CFLAGS)
	randomtestadventurer > randomtestadventurer.out
	gcov -b -f dominion.c >> randomtestadventurer.out
	
randomtestcard.out: randomtestcard.c dominion.c rngs.c
	gcc -o randomtestcard randomtestcard.c dominion.c rngs.c $(CFLAGS)
	randomtestcard > randomtestcard.out
	gcov -b -f dominion.c >> randomtestcard.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.out
	rm -f badTestDrawCard testDrawCard
	rm -f unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3
	rm -f randomtestadventurer randomtestcard

CFLAGS = -Wall -fpic -coverage -lm -std=c99 

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

# Unit Tests

unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)
	
unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
	
unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
	
unittest4: unittest4.c dominion.o rngs.o 
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)
	
# Card Tests

cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)
	
# Unit/Card Testing Suite
unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	echo "Results for running unit tests:" > unittestresults.out
	
	echo "unittest1.c:" >> unittestresults.out
	./unittest1 >> unittestresults.out
	echo "" >> unittestresults.out
	echo "GCOV results for unittest1.c" >> unittestresults.out
	gcov -b unittest1.c >> unittestresults.out
	echo "" >> unittestresults.out
	echo "GCOV results for dominion.c from unittest1.c" >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	
	echo "" >> unittestresults.out
	echo "unittest2.c:" >> unittestresults.out
	./unittest2 >> unittestresults.out
	echo "" >> unittestresults.out
	echo "GCOV results for unittest2.c" >> unittestresults.out
	gcov -b unittest2.c >> unittestresults.out
	echo "" >> unittestresults.out
	echo "GCOV results for dominion.c from unittest2.c" >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	
	echo "" >> unittestresults.out
	echo "unittest3.c:" >> unittestresults.out
	./unittest3 >> unittestresults.out
	echo "" >> unittestresults.out
	echo "GCOV results for unittest3.c" >> unittestresults.out
	gcov -b unittest3.c >> unittestresults.out
	echo "" >> unittestresults.out
	echo "GCOV results for dominion.c from unittest3.c" >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	
	echo "" >> unittestresults.out
	echo "unittest4.c:" >> unittestresults.out
	./unittest4 >> unittestresults.out
	echo "" >> unittestresults.out
	echo "GCOV results for unittest4.c" >> unittestresults.out
	gcov -b unittest4.c >> unittestresults.out
	echo "" >> unittestresults.out
	echo "GCOV results for dominion.c from unittest4.c" >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	
	echo "" >> unittestresults.out
	echo "Results for running card tests:" >> unittestresults.out
	
	echo "cardtest1.c:" >> unittestresults.out
	./cardtest1 >> unittestresults.out
	echo "" >> unittestresults.out
	echo "GCOV results for cardtest1.c" >> unittestresults.out
	gcov -b cardtest1.c >> unittestresults.out
	echo "" >> unittestresults.out
	echo "GCOV results for dominion.c from cardtest1.c" >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	
	echo "" >> unittestresults.out
	echo "cardtest2.c:" >> unittestresults.out
	./cardtest2 >> unittestresults.out
	echo "GCOV results for cardtest2.c" >> unittestresults.out
	gcov -b cardtest2.c >> unittestresults.out
	echo "" >> unittestresults.out
	echo "GCOV results for dominion.c from cardtest2.c" >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	
	echo "" >> unittestresults.out
	echo "cardtest3.c:" >> unittestresults.out
	./cardtest3 >> unittestresults.out
	echo "GCOV results for cardtest3.c" >> unittestresults.out
	gcov -b cardtest3.c >> unittestresults.out
	echo "" >> unittestresults.out
	echo "GCOV results for dominion.c from cardtest3.c" >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	
	echo "" >> unittestresults.out
	echo "cardtest4.c:" >> unittestresults.out
	./cardtest4 >> unittestresults.out
	echo "GCOV results for cardtest4.c" >> unittestresults.out
	gcov -b cardtest4.c >> unittestresults.out
	echo "" >> unittestresults.out
	echo "GCOV results for dominion.c from cardtest4.c" >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

# Random Card Tests
randomtestcard: randomtestcard.c dominion.o rngs.o
	gcc -o randomtestcard randomtestcard.c -g dominion.o rngs.o $(CFLAGS)
	
randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)
	
# Random Card Testing Suites
randomtestcard.out: randomtestcard
	echo "Results for running randomtestcard:" > randomtestcard.out
	./randomtestcard >> randomtestcard.out
	echo "" >> randomtestcard.out
	echo "GCOV results for randomtestcard.c" >> randomtestcard.out
	gcov -b randomtestcard.c >> randomtestcard.out
	echo "" >> randomtestcard.out
	echo "GCOV results for dominion.c from randomtestcard.c" >> randomtestcard.out
	gcov -b dominion.c >> randomtestcard.out
	
randomtestadventurer.out: randomtestadventurer
	echo "Results for running randomtestadventurer:" > randomtestadventurer.out
	./randomtestadventurer >> randomtestadventurer.out
	echo "" >> randomtestadventurer.out
	echo "GCOV results for randomtestadventurer.c" >> randomtestadventurer.out
	gcov -b randomtestadventurer.c >> randomtestadventurer.out
	echo "" >> randomtestadventurer.out
	echo "GCOV results for dominion.c from randomtestadventurer.c" >> randomtestcard.out
	gcov -b dominion.c >> randomtestadventurer.out
	
player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
	rm -f unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 unittestresults.out
	rm -f randomtestadventurer randomtestcard randomtestadventurer.out randomtestcard.out
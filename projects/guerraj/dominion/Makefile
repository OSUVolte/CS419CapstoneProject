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

unittestresults.out: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.h dominion.c rngs.h rngs.c 
	echo "Result for running unit tests cards:" > unittestsresults.out
	
	echo "cardtest1.c:" >> unittestsresults.out
	gcc -o cardtest1 -g cardtest1.c dominion.c rngs.c $(CFLAGS) **need to test?*
	cardtest1 >> unittestsresults.out
	gcov dominion.c >> unittestsresults.out
	
	echo "cardtest2.c:" >> unittestsresults.out
	gcc -o cardtest2 compare.c bst.c cardtest2.c $(CFLAGS)
	cardtest2 >> unittestsresults.out
	gcov dominion.c >> unittestsresults.out
	
	echo "cardtest3.c:" >> unittestsresults.out
	gcc -o cardtest3 compare.c bst.c cardtest3.c $(CFLAGS)
	cardtest3 >> unittestsresults.out
	gcov dominion.c >> unittestsresults.out
	
	echo "cardtest4.c:" >> unittestsresults.out
	gcc -o cardtest4 compare.c bst.c cardtest4.c $(CFLAGS)
	cardtest4 >> unittestsresults.out
	gcov  dominion.c >> unittestsresults.out
	
	echo "Result for running unit tests functions:" > unittestsresults.out
	
	echo "unittest1.c:" >> unittestsresults.out
	gcc -o unittest1 compare.c bst.c unittest1.c $(CFLAGS)
	unittest1 >> unittestsresults.out
	gcov dominion.c >> unittestsresults.out
	
	echo "unittest2.c:" >> unittestsresults.out
	gcc -o unittest2 compare.c bst.c unittest2.c $(CFLAGS)
	unittest2 >> unittestsresults.out
	gcov dominion.c >> unittestsresults.out
	
	echo "unittest3.c:" >> unittestsresults.out
	gcc -o unittest3 compare.c bst.c unittest3.c $(CFLAGS)
	unittest3 >> unittestsresults.out
	gcov dominion.c >> unittestsresults.out
	
	echo "unittest4.c:" >> unittestsresults.out
	gcc -o unittest4 compare.c bst.c unittest4.c $(CFLAGS)
	unittest4 >> unittestsresults.out
	gcov dominion.c >> unittestsresults.out
	


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so

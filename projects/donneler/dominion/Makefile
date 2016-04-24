CFLAGS = -Wall -fpic -coverage -lm

default: unittestresults.out

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

test_helpers.o: dominion.h dominion.c rngs.o
	gcc -c test_helpers.c -g $(CFLAGS)

unittest1: unittest1.c dominion.o rngs.o test_helpers.o
	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o test_helpers.o $(CFLAGS) 

unittest2: unittest2.c dominion.o rngs.o test_helpers.o
	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o test_helpers.o $(CFLAGS) 

unittest3: unittest3.c dominion.o rngs.o test_helpers.o
	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o test_helpers.o $(CFLAGS) 

unittest4: unittest4.c dominion.o rngs.o test_helpers.o
	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o test_helpers.o $(CFLAGS) 

unittestresults.out: unittest1 unittest2 unittest3 unittest4
	echo "Result for running dominion tests:" > tests.out
	
	echo "unittest1.c:" >> unittestresults.out
	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o test_helpers.o $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "unittest2.c:" >> unittestresults.out
	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o test_helpers.o $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out


	echo "unittest3.c:" >> unittestresults.out
	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o test_helpers.o $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "unittest4.c:" >> unittestresults.out
	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o test_helpers.o $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so unittestresults.out unittest1 unittest2 unittest3 unittest4 unittest5

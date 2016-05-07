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

unittest1.o: dominion.o rngs.o
unittest2.o: dominion.o rngs.o
unittest3.o: dominion.o rngs.o
unittest4.o: dominion.o rngs.o
cardtest1.o: dominion.o rngs.o
cardtest2.o: dominion.o rngs.o
cardtest3.o: dominion.o rngs.o
cardtest4.o: dominion.o rngs.o

unittestresults.out: unittest1.o unittest2.o unittest3.o unittest4.o \
					cardtest1.o cardtest2.o cardtest3.o cardtest4.o dominion.o rngs.o
	> unittestresults.out
	gcc -o test1 unittest1.o dominion.o rngs.o $(CFLAGS)
	./test1 >> unittestresults.out
	gcc -o test2 unittest2.o dominion.o rngs.o $(CFLAGS)
	./test2 >> unittestresults.out
	gcc -o test3 unittest3.o dominion.o rngs.o $(CFLAGS)
	./test3 >> unittestresults.out
	gcc -o test4 unittest4.o dominion.o rngs.o $(CFLAGS)
	./test4 >> unittestresults.out
	gcc -o ctest1 cardtest1.o dominion.o rngs.o $(CFLAGS)
	./ctest1 >> unittestresults.out
	gcc -o ctest2 cardtest2.o dominion.o rngs.o $(CFLAGS)
	./ctest2 >> unittestresults.out
	gcc -o ctest3 cardtest3.o dominion.o rngs.o $(CFLAGS)
	./ctest3 >> unittestresults.out
	gcc -o ctest4 cardtest4.o dominion.o rngs.o $(CFLAGS)
	./ctest4 >> unittestresults.out

	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out






clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so test* ctest* unittestresults.out

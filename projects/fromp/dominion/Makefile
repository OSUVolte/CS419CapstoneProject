CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

test_helpers.o: test_helpers.h test_helpers.c dominion.o
	gcc -std=c99 -c test_helpers.c -g $(CFLAGS)

test_helpers_unit.o: test_helpers_unit.h test_helpers_unit.c dominion.o
	gcc -std=c99 -c test_helpers_unit.c -g $(CFLAGS)

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


unit1: dominion.o test_helpers.o unittest1.c
	gcc -std=c99 -fprofile-arcs -ftest-coverage -Wall dominion.o unittest1.c test_helpers.c rngs.c -o unittest1 -lm -g

unit2: dominion.o test_helpers_unit.o unittest2.c
	gcc -std=c99 -fprofile-arcs -ftest-coverage -Wall dominion.o unittest2.c test_helpers_unit.c rngs.c -o unittest2 -lm -g

unit3: dominion.o test_helpers_unit.o unittest3.c
	gcc -std=c99 -fprofile-arcs -ftest-coverage -Wall dominion.o unittest3.c test_helpers_unit.c rngs.c -o unittest3 -lm -g

unit4: dominion.o test_helpers_unit.o unittest4.c
	gcc -std=c99 -fprofile-arcs -ftest-coverage -Wall dominion.o unittest4.c test_helpers_unit.c rngs.c -o unittest4 -lm -g

card1: dominion.o test_helpers.o cardtest1.c
	gcc -std=c99 -fprofile-arcs -ftest-coverage -Wall dominion.o cardtest1.c test_helpers.c rngs.c -o cardtest1 -lm -g

card2: dominion.o test_helpers.o cardtest2.c
	gcc -std=c99 -fprofile-arcs -ftest-coverage -Wall dominion.o cardtest2.c test_helpers.c rngs.c -o cardtest2 -lm -g

card3: dominion.o test_helpers.o cardtest3.c
	gcc -std=c99 -fprofile-arcs -ftest-coverage -Wall dominion.o cardtest3.c test_helpers.c rngs.c -o cardtest3 -lm -g

card4: dominion.o test_helpers.o cardtest4.c
	gcc -std=c99 -fprofile-arcs -ftest-coverage -Wall dominion.o cardtest4.c test_helpers.c rngs.c -o cardtest4 -lm -g

unittestresults.out: unit1 unit2 unit3 unit4 card1 card2 card3 card4 dominion.o
	./unittest1 >> unittestresults.out 
	./unittest2 >> unittestresults.out 
	./unittest3 >> unittestresults.out 
	./unittest4 >> unittestresults.out 
	./cardtest1 >> unittestresults.out 
	./cardtest2 >> unittestresults.out 
	./cardtest3 >> unittestresults.out 
	./cardtest4 >> unittestresults.out 
	gcov -b dominion.c     >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out 


all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 unittestresults.out

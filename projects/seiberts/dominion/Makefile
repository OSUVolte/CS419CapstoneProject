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


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.out
	
unit1:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest1.c rngs.c -o unittest1 -lm -g

unit2:
	gcc -coverage dominion.c unittest2.c rngs.c -o unittest2 -lm

unit3:
	gcc -coverage dominion.c unittest3.c rngs.c -o unittest3 -lm 

unit4:
	gcc -coverage dominion.c unittest4.c rngs.c -o unittest4 -lm 

card1:
	gcc -coverage dominion.c cardtest1.c rngs.c -o cardtest1 -lm 

card2:
	gcc -coverage dominion.c cardtest2.c rngs.c -o cardtest2 -lm 

card3:
	gcc -coverage dominion.c cardtest3.c rngs.c -o cardtest3 -lm 

card4:
	gcc -coverage dominion.c cardtest4.c rngs.c -o cardtest4 -lm 
	
run: unit1 unit2 unit3 unit4 card1 card2 card3 card4
	echo "----------UNIT TEST 1-------------"
	./unittest1 &> unittestresults.out
	gcov unittest1.c >> unittestresults.out
	gcov -b unittest1.c >> unittestresults.out
	echo "----------UNIT TEST 2-------------"
	./unittest2 >> unittestresults.out
	gcov unittest2.c >> unittestresults.out
	gcov -b unittest2.c >> unittestresults.out
	echo "----------UNIT TEST 3-------------"
	./unittest3 >> unittestresults.out
	gcov unittest3.c >> unittestresults.out
	gcov -b unittest3.c >> unittestresults.out
	echo "----------UNIT TEST 4-------------"
	./unittest4 >> unittestresults.out
	gcov unittest4.c >> unittestresults.out
	gcov -b unittest4.c >> unittestresults.out
	echo "----------CARD TEST 1-------------"
	./cardtest1 >> unittestresults.out
	gcov cardtest1.c >> unittestresults.out
	gcov -b cardtest1.c >> unittestresults.out
	echo "----------CARD TEST 2-------------"
	./cardtest2 >> unittestresults.out
	gcov cardtest2.c >> unittestresults.out
	gcov -b cardtest2.c >> unittestresults.out
	echo "----------CARD TEST 3-------------"
	./cardtest3 >> unittestresults.out
	gcov cardtest3.c >> unittestresults.out
	gcov -b cardtest3.c >> unittestresults.out
	echo "----------CARD TEST 4-------------"
	./cardtest4 >> unittestresults.out
	gcov cardtest4.c >> unittestresults.out
	gcov -b cardtest4.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

unittestresults.out: unit1 unit2 unit3 unit4 card1 card2 card3 card4 run
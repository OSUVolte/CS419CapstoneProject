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

//format from other Makefiles in projects

unittestresults.out:
	make cardtest1
	make cardtest2
	make cardtest3
	make cardtest4
	make unittest1
	make unittest2
	make unittest3
	make unittest4
	echo "----------------- RUNNING TEST BUNDLE : Printout --------------" >> unittestresults.out
	echo "All" >> unittestresults.out
	make tests >> unittestresults.out
	echo " --------------- COVERAGE: Individual functions and TOTAL DOMINION.C COVERAGE -------------------" >> unittestresults.out
	gcov -f -b dominion.c >> unittestresults.out
	echo "Results now written to file: unittestresults.out"
	echo "Please open or CAT to view"

unittest1: unittest1.c dominion.o rngs.o
       gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
       
unittest2: unittest2.c dominion.o rngs.o
       gcc -o unittest1 -g  unittest2.c dominion.o rngs.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o
       gcc -o unittest1 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
   
unittest4: unittest4.c dominion.o rngs.o
       gcc -o unittest1 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
       
cardtest1: cardtest1.c dominion.o rngs.o
       gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
       
cardtest2: cardtest2.c dominion.o rngs.o
       gcc -o cardtest1 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o
       gcc -o cardtest1 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
   
cardtest4: cardtest4.c dominion.o rngs.o
       gcc -o cardtest1 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard


clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so

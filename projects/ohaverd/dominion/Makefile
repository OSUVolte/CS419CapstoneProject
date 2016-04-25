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
	
card1: cardtest1.c dominion.o rngs.o
	gcc -o ct1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)
	
card2: cardtest2.c dominion.o rngs.o
	gcc -o ct2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)
	
card3: cardtest3.c dominion.o rngs.o
	gcc -o ct3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)
	
card4: cardtest4.c dominion.o rngs.o
	gcc -o ct4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)
	
unit1: unittest1.c dominion.o rngs.o
	gcc -o ut1 -g unittest1.c dominion.o rngs.o $(CFLAGS)
	
unit2: unittest2.c dominion.o rngs.o
	gcc -o ut2 -g unittest2.c dominion.o rngs.o $(CFLAGS)
	
unit3: unittest3.c dominion.o rngs.o
	gcc -o ut3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
	
unit4: unittest4.c dominion.o rngs.o
	gcc -o ut4 -g unittest4.c dominion.o rngs.o $(CFLAGS)
	
unittestresults.out: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c 
	make rngs.o
	make dominion.o
	
	echo "Result for running unit tests:" > unittestresults.out
	
	echo "unittest1.c:" >> unittestresults.out
	gcc -o ut1 -g unittest1.c dominion.o rngs.o $(CFLAGS)
	ut1 >> unittestresults.out
	gcov -f -b dominion.c >> unittestresults.out
	
	echo "unittest2.c:" >> unittestresults.out
	gcc -o ut2 -g unittest2.c dominion.o rngs.o $(CFLAGS)
	ut2 >> unittestresults.out
	gcov -f -b dominion.c >> unittestresults.out
	
	echo "unittest3.c:" >> unittestresults.out
	gcc -o ut3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
	ut3 >> unittestresults.out
	gcov -f -b dominion.c >> unittestresults.out
	
	echo "unittest4.c:" >> unittestresults.out
	gcc -o ut4 -g unittest4.c dominion.o rngs.o $(CFLAGS)
	ut4 >> unittestresults.out
	gcov -f -b dominion.c >> unittestresults.out
	
	echo "cardtest1.c:" >> unittestresults.out
	gcc -o ct1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)
	ct1 >> unittestresults.out
	gcov -f -b dominion.c >> unittestresults.out
	
	echo "cardtest2.c:" >> unittestresults.out
	gcc -o ct2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)
	ct2 >> unittestresults.out
	gcov -f -b dominion.c >> unittestresults.out
	
	echo "cardtest3.c:" >> unittestresults.out
	gcc -o ct3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)
	ct3 >> unittestresults.out
	gcov -f -b dominion.c >> unittestresults.out
	
	echo "cardtest4.c:" >> unittestresults.out
	gcc -o ct4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)
	ct4 >> unittestresults.out
	gcov -f -b dominion.c >> unittestresults.out
	
dotests: 
	./ct1
	./ct2
	./ct3
	./ct4
	./ut1
	./ut2
	./ut3
	./ut4
	
dotestsgcov:
	gcov -f -b unittest1.c
	gcov -f -b unittest2.c
	gcov -f -b unittest3.c
	gcov -f -b unittest4.c
	gcov -f -b cardtest1.c
	gcov -f -b cardtest2.c
	gcov -f -b cardtest3.c
	gcov -f -b cardtest4.c

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
	rm -f unittestresults.out

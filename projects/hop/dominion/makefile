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

unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o  $(CFLAGS)

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

run: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	mkdir results
	./unittest1 > unittestresults.out
	echo "Coverage Test: unittest1" >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	gcov -b unittest1.c >> unittestresults.out
	cp dominion.c.gcov ./results/dominion_unittest1.c.gcov
	
	./unittest2 >> unittestresults.out
	echo "Coverage Test: unittest2" >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	gcov -b unittest2.c >> unittestresults.out
	cp dominion.c.gcov ./results/dominion_unittest2.c.gcov
	
	./unittest3 >> unittestresults.out
	echo "Coverage Test: unittest3" >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	gcov -b unittest3.c >> unittestresults.out
	cp dominion.c.gcov ./results/dominion_unittest3.c.gcov
	
	./unittest4 >> unittestresults.out
	echo "Coverage Test: unittest4" >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	gcov -b unittest4.c >> unittestresults.out
	cp dominion.c.gcov ./results/dominion_unittest4.c.gcov
	
	./cardtest1 >> unittestresults.out
	echo "Coverage Test: cardtest1" >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	gcov -b cardtest1.c >> unittestresults.out
	cp dominion.c.gcov ./results/dominion_cardtest1.c.gcov
	
	./cardtest2 >> unittestresults.out
	echo "Coverage Test: cardtest2" >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	gcov -b cardtest2.c >> unittestresults.out
	cp dominion.c.gcov ./results/dominion_cardtest2.c.gcov
	
	./cardtest3 >> unittestresults.out
	echo "Coverage Test: cardtest3" >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	gcov -b cardtest3.c >> unittestresults.out
	cp dominion.c.gcov ./results/dominion_cardtest3.c.gcov
	
	./cardtest4 >> unittestresults.out
	echo "Coverage Test: cardtest4" >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	gcov -b cardtest4.c >> unittestresults.out
	cp dominion.c.gcov ./results/dominion_cardtest4.c.gcov
   
unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 run

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe unittestresults.out *.gcov *.gcda *.gcno *.so
	rm -rf ./results *.dSYM unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4

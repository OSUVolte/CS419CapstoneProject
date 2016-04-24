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

unitTest1: unittest1.c dominion.o rngs.o
	gcc -o unitTest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS) 

unitTest2: unittest2.c dominion.o rngs.o
	gcc -o unitTest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS) 

unitTest3: unittest3.c dominion.o rngs.o
	gcc -o unitTest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS) 

unitTest4: unittest4.c dominion.o rngs.o
	gcc -o unitTest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS) 

cardTest1: cardtest1.c dominion.o rngs.o
	gcc -o cardTest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)

cardTest2: cardtest2.c dominion.o rngs.o
	gcc -o cardTest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS) 

cardTest3: cardtest3.c dominion.o rngs.o
	gcc -o cardTest3 -g cardtest3.c dominion.o rngs.o $(CFLAGS) 

cardTest4: cardtest4.c dominion.o rngs.o
	gcc -o cardTest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS) 

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

unittestresults.out: unitTest1 unitTest2 unitTest3 unitTest4 cardTest1 cardTest2 cardTest3 cardTest4
	./unitTest1 &> unittestresult.out
	./unitTest2 >> unittestresult.out
	./unitTest3 >> unittestresult.out
	./unitTest4 >> unittestresult.out
	./cardTest1 >> unittestresult.out
	./cardTest2 >> unittestresult.out
	./cardTest3 >> unittestresult.out
	./cardTest4 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -rf *.o playdom.exe .DS_Store unitTest1 unitTest2 unitTest3 unitTest4 cardTest1 cardTest2 cardTest3 cardTest4 playdom test.exe test player player.exe testInit testInit.exe unittestresult.out *.gcov *.gcda *.gcno *.so *.dSYM

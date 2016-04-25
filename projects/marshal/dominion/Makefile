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

testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
	gcc -o testUpdateCoins -g testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
    
unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)    

cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)

unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 dominion.o rngs.o
	./unittest1 &> unittestresults.out
	gcov unittest1.c >> unittestresults.out
	gcov unittest1.c -b >> unittestresults.out
	cat unittest1.c.gcov >> unittestresults.out
	unittest2 >> unittestresults.out
	gcov unittest2.c >> unittestresults.out
	gcov unittest2.c -b >> unittestresults.out
	cat unittest2.c.gcov >> unittestresults.out
	unittest3 >> unittestresults.out
	gcov unittest3.c >> unittestresults.out
	gcov unittest3.c -b >> unittestresults.out
	cat unittest3.c.gcov >> unittestresults.out
	unittest4 >> unittestresults.out
	gcov unittest4.c >> unittestresults.out
	gcov unittest4.c -b >> unittestresults.out
	cat unittest4.c.gcov >> unittestresults.out
	cardtest1 >> unittestresults.out
	gcov cardtest1.c >> unittestresults.out
	gcov cardtest1.c -b >> unittestresults.out
	cat cardtest1.c.gcov >> unittestresults.out
	cardtest2 >> unittestresults.out
	gcov cardtest2.c >> unittestresults.out
	gcov cardtest2.c -b >> unittestresults.out
	cat cardtest2.c.gcov >> unittestresults.out
	cardtest3 >> unittestresults.out
	gcov cardtest3.c >> unittestresults.out
	gcov cardtest3.c -b >> unittestresults.out
	cat cardtest3.c.gcov >> unittestresults.out
	cardtest4 >> unittestresults.out
	gcov cardtest4.c >> unittestresults.out
	gcov cardtest4.c -b >> unittestresults.out
	cat cardtest4.c.gcov >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out 
	cat dominion.c.gcov >> unittestresults.out
    

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard testUpdateCoins unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testDrawCard testDrawCard.exe badTestDrawCard badTestDrawCard.exe testUpdateCoins testUpdateCoins.exe testInit testInit.exe unittest1 unittest1.exe unittest2 unittest2.exe unittest3 unittest3.exe unittest4 unittest4.exe cardtest1 cardtest1.exe cardtest2 cardtest2.exe cardtest3 cardtest3.exe cardtest4 cardtest4.exe *.gcov *.gcda *.gcno *.so

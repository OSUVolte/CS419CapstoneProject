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

testShuffle: unittest1.c dominion.o rngs.o
	gcc -o testShuffle -g  unittest1.c dominion.o rngs.o $(CFLAGS)

testUpdateCoins: unittest2.c dominion.o rngs.o
	gcc -o testUpdateCoins -g  unittest2.c dominion.o rngs.o $(CFLAGS)

testScoreFor: unittest3.c dominion.o rngs.o
	gcc -o testScoreFor -g  unittest3.c dominion.o rngs.o $(CFLAGS)

testIsGameOver: unittest4.c dominion.o rngs.o
	gcc -o testIsGameOver -g  unittest4.c dominion.o rngs.o $(CFLAGS)

testSmithy: cardtest1.c dominion.o rngs.o
	gcc -o testSmithy -g  cardtest1.c dominion.o rngs.o $(CFLAGS)

testAdvent: cardtest2.c dominion.o rngs.o
	gcc -o testAdvent -g  cardtest2.c dominion.o rngs.o $(CFLAGS)

testVillage: cardtest3.c dominion.o rngs.o
	gcc -o testVillage -g  cardtest3.c dominion.o rngs.o $(CFLAGS)

testGH: cardtest4.c dominion.o rngs.o
	gcc -o testGH -g  cardtest4.c dominion.o rngs.o $(CFLAGS)

unittestresults.out: unittest1.c unittest2.c unittest3.c unittest4.c 
	echo "Results for running unit and card tests:${\n}" > unittestresults.out
 		
	echo "${\n}unittest1.c:" >> unittestresults.out
	gcc -o unittest1 unittest1.c dominion.o rngs.o $(CFLAGS)
	unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "unittest2.c:" >> unittestresults.out
	gcc -o unittest2 unittest2.c dominion.o rngs.o $(CFLAGS)
	unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out	

	echo "unittest3.c:" >> unittestresults.out
	gcc -o unittest3 unittest3.c dominion.o rngs.o $(CFLAGS)
	unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	echo "unittest4.c:" >> unittestresults.out
	gcc -o unittest4 unittest4.c dominion.o rngs.o $(CFLAGS)
	unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "cardtest1.c:" >> unittestresults.out
	gcc -o cardtest1 cardtest1.c dominion.o rngs.o $(CFLAGS)
	cardtest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "cardtest2.c:" >> unittestresults.out
	gcc -o cardtest2 cardtest2.c dominion.o rngs.o $(CFLAGS)
	cardtest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "cardtest3.c:" >> unittestresults.out
	gcc -o cardtest3 cardtest3.c dominion.o rngs.o $(CFLAGS)
	cardtest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "cardtest4.c:" >> unittestresults.out
	gcc -o cardtest4 cardtest4.c dominion.o rngs.o $(CFLAGS)
	cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	gcov -b dominion.c >> unittestresults.out

randomtestcard: randomtestcard.c dominion.o rngs.o
	gcc -o randomtestcard -g randomtestcard.c dominion.o rngs.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

randomtestcard.out: randomtestcard.c
	echo "Results for running random card test" > randomtestcard.out
	gcc -o randomtestcard randomtestcard.c dominion.o rngs.o ${CFLAGS}
	randomtestcard >> randomtestcard.out
	gcov -b dominion.c >> randomtestcard.out

randomtestadventurer.out: randomtestadventurer.c
	echo "Results for running random Adventurer card test" > randomtestadventurer.out
	gcc -o randomtestadventurer randomtestadventurer.c dominion.o rngs.o ${CFLAGS}
	randomtestadventurer >> randomtestadventurer.out
	gcov -b dominion.c >> randomtestadventurer.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
	rm -f *.o randomtestcard randomtestadventurer
	rm -f *.o cardtest1 cardtest2 cardtest3 cardtest4 unittest1 unittest2 unittest3 unittest4


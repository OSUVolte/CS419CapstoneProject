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

unittestresults.out: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.o rngs.o interface.o
	echo "Result for running unit tests:" > unittestresults.out	
	echo "unittest1.c:" >> unittestresults.out
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o interface.o $(CFLAGS)
	unittest1 >> unittestresults.out
	gcov unittest1.c >> unittestresults.out
	
	echo "unittest2.c:" >> unittestresults.out
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o interface.o $(CFLAGS)
	unittest2 >> unittestresults.out
	gcov unittest2.c >> unittestresults.out
	
	echo "unittest3.c:" >> unittestresults.out
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o interface.o $(CFLAGS)
	unittest3 >> unittestresults.out
	gcov unittest3.c >> unittestresults.out
	
	echo "unittest4.c:" >> unittestresults.out
	gcc -o unittest4 -g unittest4.c dominion.o rngs.o interface.o $(CFLAGS)
	unittest4 >> unittestresults.out
	gcov unittest4.c >> unittestresults.out
	
	echo "cardtest1.c:" >> unittestresults.out
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o interface.o $(CFLAGS)
	cardtest1 >> unittestresults.out
	gcov cardtest1.c >> unittestresults.out
	
	echo "cardtest2.c:" >> unittestresults.out
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o interface.o $(CFLAGS)
	cardtest2 >> unittestresults.out
	gcov cardtest2.c >> unittestresults.out
	
	echo "cardtest3.c:" >> unittestresults.out
	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o interface.o $(CFLAGS)
	cardtest3 >> unittestresults.out
	gcov cardtest3.c >> unittestresults.out
	
	echo "cardtest4.c:" >> unittestresults.out
	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o interface.o $(CFLAGS)
	cardtest4 >> unittestresults.out
	gcov cardtest4.c >> unittestresults.out
	
	#dominion.o >> unittestresults.out
	gcov dominion.c >> unittestresults.out


############ ADDED MAKEFILE FOR ASSIGNMENT 4 ##################################################
randomtestcard.out: randomtestcard.c dominion.o rngs.o interface.o
	echo "randomtestcard.c:" > randomtestcard.out
	gcc -o randomtestcard -g randomtestcard.c dominion.o rngs.o interface.o $(CFLAGS)
	
	randomtestcard >> randomtestcard.out
	gcov randomtestcard.c >> randomtestcard.out
	cat randomtestcard.c.gcov >> randomtestcard.out	
	
	gcov dominion.c >> randomtestcard.out
	cat dominion.c.gcov >> randomtestcard.out
#testrc: randomtestcard.c dominion.o rngs.o interface.o
#	gcc -o randomtestcard -g randomtestcard.c dominion.o rngs.o interface.o $(CFLAGS)

randomtestadventurer.out: randomtestadventurer.c dominion.o rngs.o interface.o
	echo "randomtestadventurer.c:" > randomtestadventurer.out
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o interface.o $(CFLAGS)
	
	randomtestadventurer >> randomtestadventurer.out
	gcov randomtestadventurer.c >> randomtestadventurer.out	
	cat randomtestadventurer.c.gcov >> randomtestadventurer.out	
	
	gcov dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out
testra: randomtestadventurer.c dominion.o rngs.o interface.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o interface.o $(CFLAGS)

###############################################################################################


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.out *.gcov *.gcda *.gcno *.so

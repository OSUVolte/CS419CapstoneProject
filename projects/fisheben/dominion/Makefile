CFLAGS = -Wall -fpic -coverage -lm

default:  unittestresults.out randomtestadventurer.out randomtestcard.out

unittestresults.out: unittest1.c dominion.o
	echo "Result for running unit tests:" > unittestresults.out
	echo "--------------------------------------------------------------------" >> unittestresults.out

	
	echo "unittest1.c:" >> unittestresults.out
	echo "-------------------------UNITTEST1---------------------------------" >> unittestresults.out

	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)
	unittest1 >> unittestresults.out
	gcov unittest1.c >> unittestresults.out
	gcov unittest1.c -b >> unittestresults.out
	
	echo "unittest2.c:" >> unittestresults.out
	echo "-------------------------UNITTEST2--------------------------------" >> unittestresults.out

	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
	unittest2 >> unittestresults.out
	gcov unittest2.c >> unittestresults.out
	gcov unittest2.c -b >> unittestresults.out
	
	echo "unittest3.c:" >> unittestresults.out
	echo "--------------------------UNITTEST3------------------------------" >> unittestresults.out

	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
	unittest3 >> unittestresults.out
	gcov unittest3.c >> unittestresults.out
	gcov unittest3.c -b >> unittestresults.out
	
	echo "unittest4.c:" >> unittestresults.out
	echo "-------------------------UNITTEST4----------------------------" >> unittestresults.out
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)
	unittest4 >> unittestresults.out
	gcov unittest4.c >> unittestresults.out
	gcov unittest4.c -b >> unittestresults.out
	
	echo "cardtest1.c:" >> unittestresults.out
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)
	cardtest1 >> unittestresults.out
	gcov cardtest1.c >> unittestresults.out
	gcov cardtest1.c -b >> unittestresults.out
	
	echo "cardtest2.c:" >> unittestresults.out
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)
	cardtest2 >> unittestresults.out
	gcov cardtest2.c >> unittestresults.out
	gcov cardtest2.c -b >> unittestresults.out
	
	echo "cardtest3.c:" >> unittestresults.out
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)
	cardtest3 >> unittestresults.out
	gcov cardtest3.c >> unittestresults.out
	gcov cardtest3.c -b >> unittestresults.out
	
	echo "cardtest4.c:" >> unittestresults.out
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)
	cardtest4 >> unittestresults.out
	gcov cardtest4.c >> unittestresults.out
	gcov cardtest4.c -b >> unittestresults.out

	echo "dominion.c:" >> unittestresults.out
	echo "--------------------DOMINION CODE COVERAGE--------------------" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
randomtestadventurer.out: randomtestadventurer.c dominion.o 
	echo "Result for running random test:" > randomtestadventurer.out
	echo "--------------------------------------------------------------------" >> randomtestadventurer.out

	
	echo "randomtestadventurer.c:" >> randomtestadventurer.out
	echo "-------------------------RANDOM TESTER ADVENTURER---------------------------------" >> randomtestadventurer.out

	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)
	randomtestadventurer >> randomtestadventurer.out
	gcov randomtestadventurer.c >> randomtestadventurer.out
	gcov randomtestadventurer.c -b >> randomtestadventurer.out

	echo "dominion.c:" >> unittestresults.out
	echo "--------------------------DOMINION CODE COVERAGE---------------------------------------"
	gcov dominion.c >> randomtestadventurer.out
	gcov dominion.c -b >> randomtestadventurer.out

randomtestcard.out: randomtestcard.c dominion.o 
	echo "Result for running random test:" > randomtestcard.out
	echo "--------------------------------------------------------------------" >> randomtestcard.out

	
	echo "randomtestcard.c:" >> randomtestcard.out
	echo "-------------------------RANDOM TESTER SMITHY---------------------------------" >> randomtestcard.out

	gcc -o randomtestcard randomtestcard.c -g dominion.o rngs.o $(CFLAGS)
	randomtestcard >> randomtestcard.out
	gcov randomtestcard.c >> randomtestcard.out
	gcov randomtestcard.c -b >> randomtestcard.out

	echo "dominion.c:" >> unittestresults.out
	echo "--------------------------DOMINION CODE COVERAGE---------------------------------------"
	gcov dominion.c >> randomtestcard.out
	gcov dominion.c -b >> randomtestcard.out

	

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

clean:
	rm -f *.o *.out randomtestadventurer randomtestcard unittest1 playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so

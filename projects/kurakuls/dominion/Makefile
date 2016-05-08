CFLAGS = -Wall -fpic -coverage -lm

UNITS = unit
CARDS = card

RANDOM1 = randomtestcard
RANDOM2 = randomtestadventurer

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


unittestresults.out: dominion.o rngs.o $(UNITS) $(CARDS) 
	./unit1 &> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
	./unit2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out 
	
	./unit3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
	./unit4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
	./card1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
	./card2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
	./card3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
	./card4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out   
   
unit: 
	gcc -o unit1 unittest1.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o unit2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o unit3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o unit4 unittest4.c -g dominion.o rngs.o $(CFLAGS)

card:
	gcc -o card1 cardtest1.c -g dominion.o rngs.o $(CFLAGS) 
	gcc -o card2 cardtest2.c -g dominion.o rngs.o $(CFLAGS) 
	gcc -o card3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o card4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)   

   
randomtestresults.out: dominion.o rngs.o $(RANDOM1) $(RANDOM2)
	./randomtestcard &> randomtestcard.out
	gcov dominion.c >> randomtestcard.out
	cat dominion.c.gcov >> randomtestcard.out
	
	./randomtestadventurer >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out 

randomtestcard: randomtestcard.c dominion.o
	gcc -o randomtestcard randomtestcard.c -g dominion.o rngs.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)
   
all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit
	rm -f testInit.exe *.gcov *.gcda *.gcno *.so badTestDrawCard testDrawCard
	rm -f $(UNITS) $(CARDS) unittestresults.out
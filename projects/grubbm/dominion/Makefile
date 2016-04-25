CC = gcc
CFLAGS  = -g -Wall -coverage -fpic -lm

all: unittest1 unittest2 unittest3 unittest4 test1 test2 test3 test4

unittest1:  unittest1.o dominion.o rngs.o 
	$(CC) $(CFLAGS) -o unittest1 unittest1.o dominion.o rngs.o 


unittest2: unittest2.o dominion.o rngs.o 
	$(CC) $(CFLAGS) -o unittest2 unittest2.o dominion.o rngs.o 

unittest3: unittest3.o dominion.o rngs.o 
	$(CC) $(CFLAGS) -o unittest3 unittest3.o dominion.o rngs.o 

unittest4: unittest4.o dominion.o rngs.o 
	$(CC) $(CFLAGS) -o unittest4 unittest4.o dominion.o rngs.o 

cardtest1: cardtest1.o dominion.o rngs.o
	$(CC) $(CFLAGS) -o cardtest1 cardtest1.o dominion.o rngs.o 

cardtest2: cardtest2.o dominion.o rngs.o
	$(CC) $(CFLAGS) -o cardtest2 cardtest2.o dominion.o rngs.o 
	
cardtest3: cardtest3.o dominion.o rngs.o
	$(CC) $(CFLAGS) -o cardtest3 ctest3.o dominion.o rngs.o 
	
cardtest4: cardtest4.o dominion.o rngs.o
	$(CC) $(CFLAGS) -o cardtest4 ctest4.o dominion.o rngs.o 

unittest1.o:  unittest1.c rngs.h dominion.h dominion_helpers.h
	$(CC) $(CFLAGS) -c unittest1.c	

unittest2.o:  unittest2.c rngs.h dominion.h dominion_helpers.h
	$(CC) $(CFLAGS) -c unittest2.c	

unittest3.o:  unittest3.c rngs.h dominion.h dominion_helpers.h
	$(CC) $(CFLAGS) -c unittest3.c	

unittest4.o:  unittest4.c rngs.h dominion.h dominion_helpers.h
	$(CC) $(CFLAGS) -c unittest4.c	

cardtest1.o:  cardtest1.c rngs.h dominion.h dominion_helpers.h
	$(CC) $(CFLAGS) -c cardtest1.c

cardtest2.o:  cardtest2.c rngs.h dominion.h dominion_helpers.h
	$(CC) $(CFLAGS) -c cardtest2.c

cardtest3.o:  cardtest3.c rngs.h dominion.h dominion_helpers.h
	$(CC) $(CFLAGS) -c cardtest3.c
	
cardtest4.o:  cardtest4.c rngs.h dominion.h dominion_helpers.h
	$(CC) $(CFLAGS) -c cardtest4.c
	
dominion.o:  dominion.c dominion.h 
	$(CC) $(CFLAGS) -c dominion.c

rngs.o:  rngs.c rngs.h 
	$(CC) $(CFLAGS) -c rngs.c

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

unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 dominion.o rngs.o
	unittest1 >> unittestresults.out
	unittest2 >> unittestresults.out
	unittest3 >> unittestresults.out
	unittest4 >> unittestresults.out
	cardtest1 >> unittestresults.out
	cardtest2 >> unittestresults.out
	cardtest3 >> unittestresults.out
	cardtest4 >> unittestresults.out
	gcov -f -b dominion.c >> unittestresults.out

	
ucTest:
	./unittest1 &> unittestresults.out
	./unittest2 >> unittestresults.out
	./unittest3 >> unittestresults.out
	./unittest4 >> unittestresults.out
	./cardtest1 >> unittestresults.out
	./cardtest2 >> unittestresults.out
	./cardtest3 >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

	
	
clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so

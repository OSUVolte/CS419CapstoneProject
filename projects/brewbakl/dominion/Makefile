CFLAGS =  -fpic -coverage -lm 

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g -B $(CFLAGS)

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
	
unit1: unittest1.c dominion.o rngs.o
		gcc -o unittest1 -g unittest1.c  dominion.o rngs.o -lm -std=c99 $(CFLAGS)

unit2: unittest2.c dominion.o rngs.o
		gcc -o unittest2 -g unittest2.c  dominion.o rngs.o -lm -std=c99 $(CFLAGS)

unit3: unittest3.c dominion.o rngs.o
		gcc -o unittest3 -g unittest3.c  dominion.o rngs.o -lm -std=c99 $(CFLAGS)
		
unit4: unittest4.c dominion.o rngs.o
		gcc -o unittest4 -g unittest4.c  dominion.o rngs.o -lm -std=c99 $(CFLAGS)

card1: cardtest1.c dominion.o rngs.o
		gcc -o cardtest1 -g cardtest1.c  dominion.o rngs.o -lm -std=c99 $(CFLAGS)
		
card2: cardtest2.c dominion.o rngs.o
		gcc -o cardtest2 -g cardtest2.c  dominion.o rngs.o -lm -std=c99 $(CFLAGS)
		
card3: cardtest3.c dominion.o rngs.o
		gcc -o cardtest3 -g cardtest3.c  dominion.o rngs.o -lm -std=c99 $(CFLAGS)
		
card4: cardtest4.c dominion.o rngs.o
		gcc -o cardtest4 -g cardtest4.c  dominion.o rngs.o -lm -std=c99 $(CFLAGS)

tests:
	./unittest1 &> unittestresult.out
	./unittest2 >> unittestresult.out
	./unittest3 >> unittestresult.out
	./unittest4 >> unittestresult.out
	./cardtest1 >> unittestresult.out
	./cardtest2 >> unittestresult.out
	./cardtest3 >> unittestresult.out
	./cardtest4 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard unit1 unit2 unit3 unit4 card1 card2 card3 card4 runtests tests

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so

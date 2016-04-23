CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

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

u1: unittest1
	./unittest1 > unittestresults.out
	gcov dominion.c >> unittestresults.out
	
u2: unittest2
	./unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

u3: unittest3
	./unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
u4: unittest4
	./unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

c1: cardtest1
	./cardtest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
c2: cardtest2
	./cardtest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

c3: cardtest3
	./cardtest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
c4: cardtest4
	./cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

unittestresults.out: u1 u2 u3 u4 c1 c2 c3 c4
		

all: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4

clean:
	rm -f *.o unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 *.gcov *.gcda *.gcno *.so *~
